---
date: 2013-11-20
tags: [tcl]
---

## Hello, tcl!

```tcl
#!/usr/bin/tclsh
puts stdout {Hello, tcl!}
```

```tcl
set inputString "xxxxxxx-s12345ab7_0_0_xx2.log"

if {![regexp {ab[^.]+} $inputString extracted]} {
    error "didn't match!"
}
puts "got $extracted"
# ===> got ab7_0_0_xx2
```

get rid of those nasty underscores with string map:

```tcl
set final [string map {"_" ""} $extracted]
puts "got $final"
# ===> ab700xx2
```

keep the last underscore and to up-case the first part.

```tcl
set pieces [split $extracted "_"]
set final [string toupper [join [lrange $pieces 0 2] ""]]_[join [lrange $pieces 3 end] "_"]
puts "got $final"
# ===> got AB700_xx2

(The split command divides a string up into “records” by an optional record specifier — which defaults to any whitespace character — that we can then manipulate easily with list operations. The join command does the reverse, but here I'm using an empty record specifier on one half which makes everything be concatenated. I think you can guess what the string toupper and lrange commands do…)


I would do regsub -all {_(\d)} $extracted {\1} final to remove the "inner" underscores, give or take unspoken requirements.
```

```tcl
#          regsub -all -- "igb: probe of \[0-9:\.]+ failed with error -5" $retString "" reString
```

```tcl
puts [array get env]

parray env
```

# Data structure

## Array

## Dict

## List

# Condition

## while

`while` command has two parameters.

## eval

## for

## foreach

## switch

# string operation

# file access

# window communication

# C interface

# Sockets

# Tk components: canvas, menu, etc.

#
make expr operate more efficiently by grouping the entire expression in curly braces. The explanation has to do with the
byte code compiler that Tcl uses internally,

do not have to worry
about the value of variables until you use eval

```tcl
set escape \u001b
set escape \0x1b
set escape \033

set s Hello
=> Hello
puts stdout "The length of $s is [string length $s]."
=> The length of Hello is 5.
puts stdout {The length of $s is [string length $s].}
=> The length of $s is [string length $s].
```

- Grouping decisions are made before substitutions are performed

## math functions

acos(x) |  Arccosine of x.
asin(x) |  Arcsine of x.
atan(x) |  Arctangent of x.
atan2(y,x) |  Rectangular (x,y) |  to polar (r,th). atan2 gives th.
ceil(x) |  Least integral value greater than or equal to x.
cos(x) |  Cosine of x.
cosh(x) |  Hyperbolic cosine of x.
exp(x) |  Exponential, e x .
floor(x) |  Greatest integral value less than or equal to x.fmod(x,y) |  Floating point remainder of x/y.
hypot(x,y) |  Returns sqrt(x*x + y*y). r part of polar coordinates.
log(x) |  Natural log of x.
log10(x) |  Log base 10 of x.
pow(x,y) |  x to the y power, x y .
sin(x) |  Sine of x.
sinh(x) |  Hyperbolic sine of x.
sqrt(x) |  Square root of x.
tan(x) |  Tangent of x.
tanh(x) |  Hyperbolic tangent of x.
abs(x) |  Absolute value of x.
double(x) |  Promote x to floating point.
int(x) |  Truncate x to an integer.
round(x) |  Round x to an integer.
rand() Return a random floating point value between 0.0 and 1.0.
srand(x) |  Set the seed for the random number generator to the integer x.
wide(x) |  Promote x to a wide (64-bit) integer. (Tcl 8.4)

```tcl
proc Diag {a b} {
   set c [expr {sqrt($a * $a + $b * $b)}]
   return $c
}
puts "The diagonal of a 3, 4 right triangle is [Diag 3 4]"
```

Tcl interpreter returns the value of the last command in
the body as the value of the procedure

- The opening curly brace must be on the same line as proc and while. If you like to put opening
curly braces on the line after a while or if statement, you must escape the newline with a
backslash

By default, it assumes that variable names
contain only letters, digits, and the underscore. The construct $foo.o represents a
concatenation of the value of foo and the literal ".o".

unset
Any number of variable names can be passed to the unset command. However, unset will
raise an error if a variable is not already defined, unless the -nocomplain is given. Use -- to
unset a variable named -nocomplain.

```tcl
if {![info exists foobar]} {
   set foobar 0
} else {
   incr foobar
}

expr 1 / 3
=> 0
expr 1 / 3.0
=> 0.333333333333
set tcl_precision 17
=> 17
expr 1 / 3.0
# The trailing 1 is the IEEE rounding digit
=> 0.33333333333333331
```

You should always group expressions in curly braces and let expr do command and variable
substitutions. Otherwise, your values may suffer extra conversions from numbers to strings
and back to numbers. Not only is this process slow, but the conversions can lose precision in
certain circumstances. For example, suppose x is computed from a math function:
set x [expr {sqrt(2.0)}]
At this point the value of x is a double-precision floating point value, just as you would expect.
If you do this:
set two [expr $x * $x]
then you may or may not get 2.0 as the result! This is because Tcl will substitute $x and expr
will concatenate all its arguments into one string, and then parse the expression again. In
contrast, if you do this:
set two [expr {$x * $x}]
then expr will do the substitutions, and it will be careful to preserve the floating point value of
x. The expression will be more accurate and run more efficiently because no string
conversions will be done.

Unlike in many other languages, the # must
occur at the beginning of a command. A # that occurs elsewhere is not treated specially. An
easy trick to append a comment to the end of a command is to precede the # with a semicolon
to terminate the previous command:

```tcl
set rate 7.0    ;# The interest rate
set months 60   ;# The loan term
```

A single round of substitutions is performed before command invocation. The result of a
substitution is not interpreted a second time. This rule is important if you have a variable
value or a command result that contains special characters such as spaces, dollar signs,square brackets, or braces. Because only a single round of substitution is done, you do
not have to worry about special characters in values causing extra substitutions.

A common error is to forget a space between arguments when grouping with braces or
quotes. This is because white space is used as the separator, while the braces or quotes
only provide grouping. If you forget the space, you will get syntax errors about unexpected
characters after the closing brace or quote.

Backslash sequences
\a Bell. (0x7)
\b Backspace. (0x8)
\f Form feed. (0xc)
\n Newline. (0xa)
\r Carriage return. (0xd)
\t Tab. (0x9)
\v Vertical tab. (0xb)
\
<newline> Replace the newline and the leading white space on the next line with a space.
\\ Backslash. ('\')
\ooo Octal specification of character code. 1, 2, or 3 octal digits (0-7).
\xhh Hexadecimal specification of character code. 1 or 2 hex digits. Be careful when using this in a string of characters,
because all hexadecimal characters following the \x will be consumed, but only the last 2 will specify the value.
\uhhhh Hexadecimal specification of a 16-bit Unicode character value. 4 hex digits.
\c Replaced with literal c if c is not one of the cases listed above. In particular, \$, \", \{, \}, \], and \[ are used to obtain
these characters.


Arithmetic operators from highest to lowest precedence
- ~ ! Unary minus, bitwise NOT, logical NOT.
* / % Multiply, divide, remainder.+ - Add, subtract.
<< >> Left shift, right shift.
< > <= >= Comparison: less, greater, less or equal, greater or equal.
== != eq ne Equal, not equal, string equal (Tcl 8.4), string not equal (Tcl 8.4).
& Bitwise AND.
^ Bitwise XOR.
| Bitwise OR.
&& Logical AND.
|| Logical OR.
x?y:z If x then y else z.


# Built-in Tcl commands
| command    | description                                               |
| ---        | ---                                                       |
| after      | Schedule a Tcl command for later execution.               |
| append     | Append arguments to a variable's value. No spaces added.  |
| array      | Query array state and search through elements.            |
| binary     | Convert between strings and binary data.                  |
| break      | Exit loop prematurely.                                    |
| catch      | Trap errors.                                              |
| cd         | Change working directory.                                 |
| clock      | Get the time and format date strings.                     |
| close      | Close an open I/O stream.                                 |
| concat     | Concatenate arguments with spaces between. Splices lists. |
| console    | Control the console used to enter commands interactively. |
| continue   | Continue with next loop iteration.                        |
| error      | Raise an error.                                           |
| eof        | Check for end of file.                                    |
| eval       | Concatenate arguments and evaluate them as a command.     |
| exec       | Fork and execute a UNIX program.                          |
| exit       | Terminate the process.                                    |
| expr       | Evaluate a math expression.                               |
| fblocked   | Poll an I/O channel to see if data is ready.              |
| fconfigure | Set and query I/O channel properties.                     |
| fcopy      | Copy from one I/O channel to another.                     |
| file       | Query the file system.                                    |
| fileevent  | Register callback for event-driven I/O.                   |
| flush      | Flush output from an I/O stream's internal buffers.       |
| for        | Loop construct similar to C for statement.                |
| foreach    | Loop construct over a list, or lists, of values.          |
| format     | Format a string similar to C sprintf.                     |
| gets       | Read a line of input from an I/O stream.                  |
| glob       | Expand a pattern to matching file names.                  |
| global     | Declare global variables.                                 |
| history    | Use command-line history.                                 |
| if         | Test a condition. Allows else and elseif clauses.         |
| incr       | Increment a variable by an integer amount.                |
| info       | Query the state of the Tcl interpreter.                   |
| interp     | Create additional Tcl interpreters.                       |
| join       | Concatenate list elements with a given separator string.  |
| lappend    | Add elements to the end of a list.                        |
| lindex     | Fetch an element of a list.                               |
| linsert    | Insert elements into a list.                              |
| list       | Create a list out of the arguments.                       |
| llength    | Return the number of elements in a list.                  |
| load       | Load shared libraries that define Tcl commands.           |
| lrange     | Return a range of list elements.                          |
| lreplace   | Replace elements of a list.                               |
| lsearch    | Search for an element of a list that matches a pattern.   |
| lset       | Set an element in a list. (Tcl 8.4)                       |
| lsort      | Sort a list.                                              |
| namespace  | Create and manipulate namespaces.                         |
| open       | Open a file or process pipeline for I/O.                  |
| package    | Provide or require code packages.                         |
| pid        | Return the process ID.                                    |
| proc       | Define a Tcl procedure.                                   |
| puts       | Output a string to an I/O stream.                         |
| pwd        | Return the current working directory.                     |
| read       | Read blocks of characters from an I/O stream.             |
| regexp     | Match regular expressions.                                |
| regsub     | Substitute based on regular expressions.                  |
| rename     | Change the name of a Tcl command.                         |
| return     | Return a value from a procedure.                          |
| scan       | Parse a string according to a format specification.       |
| seek       | Set the seek offset of an I/O stream.                     |
| set        | Assign a value to a variable.                             |
| socket     | Open a TCP/IP network connection.                         |
| source     | Evaluate the Tcl commands in a file.                      |
| split      | Chop a string up into list elements.                      |
| string     | Operate on strings.                                       |
| subst      | Substitute embedded commands and variable references.     |
| switch     | Test several conditions.                                  |
| tell       | Return the current seek offset of an I/O stream.          |
| time       | Measure the execution time of a command.                  |
| trace      | Monitor variable assignments.                             |
| unknown    | Handle unknown commands.                                  |
| unset      | Delete variables.                                         |
| uplevel    | Execute a command in a different scope.                   |
| upvar      | Reference a variable in a different scope.                |
| variable   | Declare namespace variables.                              |
| vwait      | Wait for a variable to be modified.                       |
| while      | Loop until a boolean expression is false                  |



# Hello Tcl

```
#!/usr/bin/env tclsh
puts stdout {Hello, Tcl!}
```

## Hello Tk

```tcl
#!/usr/bin/env wish
button .hello -text Hello -command {puts "Hello, Tk!"}
pack .hello -padx 10 -pady 10
```

```tcl
set arg1 [lindex $argv 0]
```

```tcl
# Tcl script to echo command line arguments
puts "Program: $argv0"
puts "Number of arguments: $argc"
set i 0
foreach arg $argv {
   puts "Arg $i: $arg"
   incr i
}
```

# source command
The source command reads Tcl commands from a file and evaluates them just as if you had typed them interactively.


# Variables defined by tclsh and wish
| argc | The number of command-line arguments.|
| argv | A list of the command-line arguments.|
| argv0 | The name of the script being executed. If being used interactively, argv0 is the name of the shell program.|
| embed_args | The list of arguments in the <EMBED> tag. Tcl applets only. |
| env | An array of the environment variables. |
| tcl_interactive | True (one) if the tclsh is prompting for commands.|
| tcl_library | The script library directory.|
| tcl_patchLevel | Modified version number, e.g., 8.0b1.|
| tcl_platform | Array containing operating system information. |
| tcl_prompt1 | If defined, this is a command that outputs the prompt.|
| tcl_prompt2 | If defined, this is a command that outputs the prompt if the current command is not yet complete.|
| tcl_version | Version number.|
| auto_path | The search path for script library directories. |
| auto_index | A map from command name to a Tcl command that defines it.|
| auto_noload | If set, the library facility is disabled.|
| auto_noexec | If set, the auto execute facility is disabled.|
| geometry (wish only). | The value of the -geometry argument.|


## wish

## Command-Line Options to Wish
Some command-line options are interpreted by wish, and they do not appear in the argv variable. The general form of the wish command line is:
wish ?options? ?script? ?arg1 arg2?

If no script is specified, then wish just enters an interactive command loop.
Wish command line options
-colormap new Use a new private colormap.
-display display Use the specified X display. UNIX only.
-geometry geometry The size and position of the window.
-name name Specify the Tk application name.
-sync Run X synchronously. UNIX only.
-use id Use the window specified by id for the main window.
-visual visual Specify the visual for the main window.
-- Terminate options to wish.


## upvar

```tcl
proc decr {varName {decrement 1}} {
    upvar 1 $varName var
    incr var [expr {-$decrement}]
}
```

## Links

- <https://www.tcl.tk/doc/scripting.html>

