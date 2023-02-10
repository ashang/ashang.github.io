---
date: 2018-06-04
title: time, timezone, epoch and Year 2038 issue
---

## UNIX time, epoch

Some parts are from
- <http://cr.yp.to/proto/utctai.html>

UNIX time counts the number of seconds since an `epoch`.

This is very convenient for programs that work with time intervals: the difference between two UNIX time values is a real-time difference measured in seconds, within the accuracy of the local clock. Thousands of programmers rely on this fact.

What is the epoch? Originally it was defined as the beginning of 1970 GMT. GMT, Greenwich Mean Time, is a traditional term for the time zone in England. Unfortunately, it is ambiguous; it can refer to a variety of astronomical time scales.

Arthur David Olson's popular time library uses an epoch of `1970-01-01 00:00:10 TAI`.

On GNU and POSIX
systems, the epoch is 1970-01-01 00:00:00 UTC, so `@0` represents this
time, `@1` represents 1970-01-01 00:00:01 UTC, and so forth.

GNU and
most other POSIX-compliant systems support such times as an extension
to POSIX, using negative counts, so that `@-1` represents 1969-12-31
23:59:59 UTC.

## Showing date and time

```
$ man date

-I[FMT], --iso-8601[=FMT]
      output date/time in ISO 8601 format. FMT='date' for date only (the default),
      'hours', 'minutes', 'seconds', or 'ns' for date and time to the indicated pre‐
      cision. Example: 2006-08-14T02:34:56-06:00

-R, --rfc-email
      output date and time in RFC 5322 format. Example: Mon, 14 Aug 2006 02:34:56 -0600

--rfc-3339=FMT
      output date/time in RFC 3339 format. FMT='date', 'seconds', or 'ns' for date
      and time to the indicated precision. Example: 2006-08-14 02:34:56-06:00

-u, --utc, --universal
      print or set Coordinated Universal Time
```

Previously `-R` refers to `--rfc-2822`.

```
$ date -I
2012-12-20

$ date -Ins
2012-12-20T10:24:29,181676804+08:00

$ date --rfc-3339=ns
2012-12-20 10:24:34.862053569+08:00

$ date --rfc-3339=date
2012-12-20
```

What's the problem?

**For many years, the UNIX localtime() time-display routine didn't support leap seconds.**

In effect it treated TAI as UTC. Its displays slipped 1 second away from the correct local time as each leap second passed. Nobody cared; clocks weren't set that accurately anyway.

Unfortunately, xntpd, a program that synchronizes clocks using the Network Time Protocol, pandered to those broken localtime() libraries, at the expense of reliability. Watch how the xntpd time scale increases as a leap second occurs:

```
1997-06-30 23:59:59.7 UTC -> 867715199.7 xntpd
1997-06-30 23:59:59.8 UTC -> 867715199.8 xntpd
1997-06-30 23:59:59.9 UTC -> 867715199.9 xntpd
1997-06-30 23:59:60.0 UTC -> 867715200.0 xntpd
1997-06-30 23:59:60.1 UTC -> 867715200.1 xntpd
1997-06-30 23:59:60.2 UTC -> 867715200.2 xntpd
1997-06-30 23:59:60.3 UTC -> 867715200.3 xntpd
1997-06-30 23:59:60.4 UTC -> 867715200.4 xntpd
1997-06-30 23:59:60.5 UTC -> 867715200.5 xntpd
1997-06-30 23:59:60.6 UTC -> 867715200.6 xntpd
1997-06-30 23:59:60.7 UTC -> 867715200.7 xntpd
1997-06-30 23:59:60.8 UTC -> 867715200.8 xntpd
1997-06-30 23:59:60.9 UTC -> 867715200.9 xntpd
1997-07-01 00:00:00.0 UTC -> 867715200.0 xntpd
1997-07-01 00:00:00.1 UTC -> 867715200.1 xntpd
1997-07-01 00:00:00.2 UTC -> 867715200.2 xntpd
```

The xntpd time scale repeats itself! It cannot be reliably converted to UTC.

By resetting the clock at each leap second, xntpd extracts a correct UTC display (except, of course, during leap seconds) from the broken localtime() libraries. Meanwhile, it produces incorrect results for applications that add and subtract real times.

Why not fix it?

It's easy enough to fix xntpd. It's also easy to fix localtime() to handle leap seconds. In fact, some vendors have already adopted Olson's time library.

The main obstacle is POSIX. POSIX is a `standard` designed by a vendor consortium several years ago to eliminate progress and protect the installed base. The behavior of the broken localtime() libraries was documented and turned into a POSIX requirement.

Fortunately, the POSIX rules are so outrageously dumb---for example, they require that 2100 be a leap year, contradicting the Gregorian calendar---that no self-respecting engineer would obey them.

任何有自尊的工程师不会遵循POSIX。POSIX是为了保护既有市场，消除进步。


## time.tzset()

tzset() reset the time conversion rules used by the library routines. The environment variable
TZ specifies how this is done.

```c
void tzset (void);

extern char *tzname[2];
extern long timezone;
extern int daylight;
```

The tzset() function initializes the tzname variable from the TZ environment variable.

This function is automatically called by the other time conversion functions
that depend on the timezone.

In a System-V-like environment, it will also set the
variables tzname (from the TZ environment variable), timezone (non-DST seconds West of UTC), altzone (DST seconds west of UTC) and daylight (to 0 if this timezone does not have any daylight saving time rules, or to nonzero if there is a time, past, present or future when daylight saving time applies).

If the TZ variable does not appear in the environment, the system timezone is used.
The system timezone is configured by copying, or linking, a file in the tzfile(5)
format to /etc/localtime. A timezone database of these files may be located in the
system timezone directory (see the FILES section below).

If the TZ variable does appear in the environment, but its value is empty, or its
value cannot be interpreted, then Coordinated Universal Time (UTC) is used.

On many Unix systems (including *BSD, Linux, Solaris, and Darwin), it is more convenient to use the system zoneinfo (tzfile(5)) database to specify the timezone rules. To do this, set the TZ environment variable to the path of the required timezone datafile, relative to the root of the systems `zoneinfo` timezone database, usually located at /usr/share/zoneinfo. For example, 'US/Eastern', 'Australia/Melbourne', 'Egypt' or 'Europe/Amsterdam'.

## python time.tzset()

```python
>>> import os
>>> os.environ['TZ']
'Asia/Shanghai'
>>> os.environ['TZ'] = 'US/Eastern'
>>> print(os.environ['TZ'])
US/Eastern
>>> import time
>>> time.tzname
('CST', 'CST')
>>> time.tzset()
>>> time.tzname
('EST', 'EDT')
>>>
```

- <https://docs.python.org/3/library/time.html>

DST is Daylight Saving Time, an adjustment of the timezone by (usually) one hour during part of the year. DST rules are magic (determined by local law) and can change from year to year. The C library has a table containing the local rules (often it is read from a system file for flexibility) and is the only source of True Wisdom in this respect.

## TAI

TAI, Temps Atomique International (French for International Atomic Time), measures real time.

One TAI second is defined as the duration of 9192631770 periods of the radiation corresponding to the transition between the two hyperfine levels of the ground state of the cesium atom.

TAI has been measured continuously since 1955 and is the foundation of all civil time standards.

TAI times are identified by year, month, day, hour, minute, and second. There are exactly 86400 TAI seconds in every TAI day. TAI days are labelled by the Gregorian calendar.

## UTC

One day of Earth's rotation isn't exactly 86400 seconds. It's closer to 86400.002 seconds, wobbling slightly from day to day.

UTC, Coordinated Universal Time, is based on TAI, and very similar to it, except that UTC has leap seconds every year or two. For example, here's how UTC and TAI handled the end of June 1997:

```
1997-06-30 23:59:59 UTC = 1997-07-01 00:00:29 TAI
1997-06-30 23:59:60 UTC = 1997-07-01 00:00:30 TAI
1997-07-01 00:00:00 UTC = 1997-07-01 00:00:31 TAI
```

Notice the 23:59:60 in UTC. That's a leap second. It extended 1997-06-30 UTC to 86401 seconds. Before the leap second, the TAI-UTC difference was 30 seconds; after the leap second, the TAI-UTC difference was 31 seconds.

By inserting occasional leap seconds into UTC, astronomers slow down UTC's progression to match Earth's rotation. That way the Sun will always be overhead at 12:00:00 UTC in England. (It's conceivable, but unlikely, that someday Earth's rotation will speed up past 1/86400 Hz. In that case astronomers will create negative leap seconds: UTC will skip from 23:59:58 to 00:00:00.)

Other time zones are based on UTC---e.g., UTC minus 5 hours---so noon has a predictable relationship to the Sun in every time zone.

The leap-second system was introduced at the beginning of 1972. At that point UTC was TAI minus 10 seconds.

>>> import time
>>> curr_time = time.localtime()
>>> curr_clock = time.strftime("%H:%M:%S", curr_time)
>>>   
>>> print(curr_clock)
17:14:46
>>> curr_time
time.struct_time(tm_year=2022, tm_mon=12, tm_mday=1, tm_hour=17, tm_min=14, tm_sec=46, tm_wday=3, tm_yday=
335, tm_isdst=0)


2000-01-01: Two-digit years
UNIX software is mostly immune to the Y2K problem. UNIX keeps track of time as the number of seconds since the beginning of 1970, not as a year-month-day-hour-minute-second date-time counter. Many UNIX programs print dates and times for human consumption, but very few UNIX programs read or compare dates.

The committee that designed the format of Internet mail message headers foolishly used a date-time counter. They originally provided only 2 digits for the year. In 1989 they allowed (and recommended) 4 digits. All versions of qmail produce 4-digit years.

I have reviewed my software packages and found two that read dates. My libtai library works with dates in the Gregorian calendar; it supports a range of billions of years. My mess822 library, which relies on libtai, can read dates in mail messages; it automatically converts 2-digit (and 3-digit) years into 4-digit years. A future version of qmail will use mess822 to clean up outgoing mail from ancient clients that fail to use 4-digit years.
2036-02-07: Unsigned 32-bit seconds since 1900
Many operating systems keep track of time as the number of seconds since the beginning of 1900. This number will overflow an unsigned 32-bit counter in 2036.

The main threat for UNIX here is NTP, the Network Time Protocol, which counts seconds since 1900. Many NTP clients will become rather confused when the counter overflows.

My TAICLOCK protocol, which like NTP announces the current time through the network, relies on the TAI64 time format, which supports a range of hundreds of billions of years.
2038-01-19: Signed 32-bit seconds since 1970







Programs running inside chroot(2) jail can not access system time zone definition from '/etc/localtime'
or other time zone data directories such as '/usr/share/zoneinfo/'. As a result, these programs rely on
the POSIX TZ environment variable for accessing system time zone definition.








zoneinfo is part of the Python standard library from Python 3.9.

There is backports.zoneinfo package for Python 3.8.

By default, zoneinfo uses the system’s time zone data if available; if no system time zone data is available, the library will fall back to using the first-party tzdata package available on PyPI.

See also

Module: datetime

 Provides the time and datetime types with which the ZoneInfo class is designed to be used.
Package tzdata

 First-party package maintained by the CPython core developers to supply time zone data via PyPI.


```
$ cal -m 10 2020
    October 2020
Su Mo Tu We Th Fr Sa
             1  2  3
 4  5  6  7  8  9 10
11 12 13 14 15 16 17
18 19 20 21 22 23 24
25 26 27 28 29 30 31
```

>>> from zoneinfo import ZoneInfo
>>> from datetime import datetime, timedelta
>>> dt = datetime(2020,10,31,12,tzinfo=ZoneInfo("America/Los_Angeles"))
>>> dt.tzname()
'PDT'
>>> print(dt)
2020-10-31 12:00:00-07:00
>>> print(dt+timedelta(days=-240))
2020-03-05 12:00:00-08:00
>>> print(dt+timedelta(days=1))
2020-11-01 12:00:00-08:00

## References

### Django 4.0:

>zoneinfo was made the default timezone implementation. You may continue to use pytz during the 4.x release cycle via the USE_DEPRECATED_PYTZ setting.

Naive and aware datetime objects¶

Python’s datetime.datetime objects have a tzinfo attribute that can be used to store time zone information, represented as an instance of a subclass of datetime.tzinfo. When this attribute is set and describes an offset, a datetime object is aware. Otherwise, it’s naive.

You can use is_aware() and is_naive() to determine whether datetimes are aware or naive.

TIME_ZONE¶

Default: 'America/Chicago'

A string representing the time zone for this installation. See the list of time zones.

Note

Since Django was first released with the TIME_ZONE set to 'America/Chicago', the global setting (used if nothing is defined in your project’s settings.py) remains 'America/Chicago' for backwards compatibility. New project templates default to 'UTC'.

Note that this isn’t necessarily the time zone of the server. For example, one server may serve multiple Django-powered sites, each with a separate time zone setting.

When USE_TZ is False, this is the time zone in which Django will store all datetimes. When USE_TZ is True, this is the default time zone that Django will use to display datetimes in templates and to interpret datetimes entered in forms.

On Unix environments (where time.tzset() is implemented), Django sets the os.environ['TZ'] variable to the time zone you specify in the TIME_ZONE setting. Thus, all your views and models will automatically operate in this time zone.

## epoch and Year 2038 issue


Many network protocols and filesystems store timestamps in the original UNIX format: a signed 32-bit integer representing the number of seconds since the beginning of 1970. This format will expire in 2038. Other protocols store timestamps as unsigned 32-bit integers representing the number of seconds since 1900; this format will expire in 2036.

Traditional Unix systems count seconds with 32-bit two's-complement
integers and can represent times from 1901-12-13 20:45:52 through
2038-01-19 03:14:07 UTC.

```
$ echo $((2**31-1))
2147483647

$ date -u -Is -d @-$((2**31))
1901-12-13T20:45:52+00:00

$ date -u -Is -d @$((2**31-1))
2038-01-19T03:14:07+00:00
```

More modern systems use 64-bit counts of
seconds with nanosecond subcounts, and can represent all the times in
the known lifetime of the universe to a resolution of 1 nanosecond.
