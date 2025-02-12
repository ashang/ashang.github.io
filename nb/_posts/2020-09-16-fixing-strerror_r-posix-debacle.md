---
title: "Pure C Solution for GNU/POSIX strerror_r"
layout: post
---

I'm not going to rehash the problem statement of `strerror_r`...because if
you found this, you likely already know:

[The Strange strerror_r of Dr. POSIX and Mr. GNU][1]

[1]: http://tzimmermann.org/2017/08/25/the-strange_strerror_r_of_dr_posix_and_mr_gnu/

But I will say it's a rather disheartening sign about the state of software.
Actual *committees* of programmers tried to fix `strerror()` by making
**TWO incompatible definitions**. :-(

    // Definition from "The Open Group"
    // in the "X/Open System Interface Extension" (XSI)
    //
    int strerror_r(int errnum, char *buf, size_t buflen);

    // Definition from GNU
    //
    char *strerror_r(int errnum, char *buf, size_t buflen);

Anyway...I'd historically believed that you could do some tests with the
preprocessor and write the code for whichever case you had.  Many people like
me trusted the GNU man pages, giving the rule for when you were using GLIBC
*(e.g. `defined(__GNU_LIBRARY__)` was true)*:

> The XSI-compliant version of strerror_r() is provided if:
>
>     (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && ! _GNU_SOURCE
>
> Otherwise, the GNU-specific version is provided.

It works until it doesn't.  Once 2020 rolled around, I tried building a program
in GCC 9 with `--std=gnu99`.  That had `_GNU_SOURCE` defined, but offered the
int-returning POSIX version...*directly contradicting the GNU manpage*.

Weaving in an ever-more-maddening set of #ifdefs for checking compiler versions
seems futile.  Especially when others have reported trouble with these tests
using libraries like `musl` on Alpine Linux.

If you're using a C++ compiler, you're lucky.  You can go straight to
[detecting the difference at compile time][2] using overloading.  *(Note:
Chromium uses this method.)*

[2]: https://www.zverovich.net/2015/03/13/reliable-detection-of-strerror-variants.html

C programmers don't seem to have much in the way of options.  One choice is
to use an even older API based on `sys_errlist`...that accesses a fixed set of
system error messages directly, avoiding a function call entirely.  But that
causes deprecation warnings--and there's no guarantee that the OS actually
stores all its errors in that list.

Is there no option for a C codebase--besides having whoever is building the
project manually pass in a flag to say which it is?

## BEHOLD...a Pure C Heuristic Solution...with no #ifdefs

I noticed the function only differs in its return result.  So why not choose a
type that could capture either a `char*` or an `int`?  How about `intptr_t`:

    intptr_t r = (intptr_t)strerror_r(errnum, buf, buflen);

The XSI `int` return results are documented, and we can pretty safely assume
they won't overlap string pointers.  There would appear to be enough
information in the mix to guide how to handle any result at runtime.

So here's a technique that seems fairly foolproof:

    void strerror_fixed(int errnum, char *buf, size_t buflen) {
        assert(buflen != 0);

        buf[0] = (char)255;  // never valid in UTF-8 sequences
        int old_errno = errno;
        intptr_t r = (intptr_t)strerror_r(errnum, buf, buflen);
        int new_errno = errno;

        if (r == -1 or new_errno != old_errno) {
            //
            // errno was changed, so probably the return value is just -1 or
            // something else that doesn't provide info.
            //
            snprintf(buf, buflen, "errno %d in strerror_r call", new_errno);
        }
        else if (r == 0) {
            //
            // The GNU version always succeds and should never return 0 (NULL).
            //
            // "The XSI-compliant strerror_r() function returns 0 on success.
            // On error, a (positive) error number is returned (since glibc
            // 2.13), or -1 is returned and errno is set to indicate the error
            // (glibc versions before 2.13)."
            //
            // Documentation isn't clear on whether the buffer is terminated if
            // the message is too long, or ERANGE always returned.  Terminate.
            //
            buf[buflen - 1] = '\0';
        }
        else if (r == EINVAL) {  // documented result from XSI strerror_r
            snprintf(buf, "bad errno %d for strerror_r()", buflen, errnum);
        }
        else if (r == ERANGE) {  // documented result from XSI strerror_r
            error = snprintf(buf, "bad buflen for errno %d", buflen, errnum);
        }
        else if (r == (intptr_t)buf) {
            //
            // The GNU version gives us our error back as a pointer if it
            // filled the buffer successfully.  Sanity check that.
            //
            if (buf[0] == (char)255) {
                assert(false);
                strncpy(buf, "strerror_r didn't update buffer", buflen);
            }
        }
        else if (r < 256) {  // extremely unlikely to be string buffer pointer
            assert(false);
            strncpy(buf, "Unknown XSI strerror_r error result code", buflen);
        }
        else {
            // The GNU version never fails, but may return an immutable string
            // instead of filling the buffer. Unknown errors get an
            // "unknown error" message.  The result is always null terminated.
            //
            // (This is the risky part, if `r` is not a valid pointer but some
            // weird large int return result from XSI strerror_r.)
            //
            strncpy(buf, (const char*)r, buflen);
        }
    }

There might be some pathological platform out there which implements the
XSI version and returns unusual numbers besides `-1`, `ERANGE`, or `EINVAL`
when the error message itself can't display.  But weird platforms tend to need
all kinds of accomodation, so this is probably the least of one's worries.

Anyway, I thought it was an interesting trick so I thought I'd make a post
describing it.