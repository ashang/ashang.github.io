---
title: "Is True Greater Than False? (an empirical study)"
layout: post
---

Haskell is known for being very strict in its type system.  So I was a bit
surprised when I saw the following:

    Prelude> True > False
    True

Was this a mistake?  Or was someone trying to sneak in evangelism of the
metaphysical stance that truths are superior to falsehoods?

If [an answer on Stack Overflow is to be believed][1], it isn't a design choice
made on whim--or desire for appeasing C programmers.  Rather, this arises from
a mathematical consensus regarding [bounded lattices][2], or *"...more
specifically, a complemented distributive lattice."*

[1]: https://stackoverflow.com/a/23880921
[2]: https://en.wikipedia.org/wiki/Lattice_%28order%29#Bounded_lattice

Hmmm.  🤔  Be that as it may, my perception is that there are two separate
questions:

* Should you be *able* to compare True with False?
* If you *can*, is there an obviously correct answer to which is greater?


## The Lattice Argument Speaks to the Second Question

There is a framework in math for relating operations to each other based on
their properties.  People point out that AND in boolean logic acts very much
like multiplication when you consider True to be 1 and False to be 0:

    False and False = False    0 * 0 = 0
     True and False = False    1 * 0 = 0
    False and True  = False    0 * 1 = 0
     True and True  = True     1 * 1 = 1

False's "lessening attitude" leads it to have a filtering effect which reduces
sets of values.  If you inventory enough of these characteristics, it might
drive you to think something like *"if false was a number, it would be 0"*.

But Haskell isn't saying that False "is" 0:

    Prelude> False == 0
        • No instance for (Num Bool) arising from the literal ‘0’

And it's also not letting you use multiplication on Bools:

    Prelude> True * False
        • No instance for (Num Bool) arising from a use of ‘*’

It doesn't do those things...despite that there would probably be a sound
rationale from math-based-conventions for what they should do if they *were*
legal.  So what's different about orderedness?


## The Reason It's *Legal* Is Ultimately Pragmatic

One of the most convincing arguments for this came from [another Stack Overflow
answer][3]:

> "...sometimes we want Ord because there's a logically meaningful ordering
> for things, and sometimes we just want some arbitrary order, typically so we
> can use something as a key for Data.Map or similar. Arguably there ought to
> be two separate classes for that...but there isn't.)"

Having built-in types be a member of `Ord` offers leverage of this kind.  It's
a level of benefit that would not be realized by letting you multiply booleans.
And it means merely adding a boolean to your type won't inhibit you from
`deriving` to inherit various behaviors.

---

But to put some more perspective on the issue, I thought it would be useful
to look around and see how boolean comparison was handled in other languages.
It's a simple task to run...and behaviors you get provide some insight into
each language's design heritage.


### C and C++: true > false => Legal

C89 has no boolean type, so people would often define things like:

    #define TRUE 1
    #define FALSE 0

This means comparisons like `TRUE > FALSE` were actually just testing `1 > 0`.
Though in practice, all non-zero values are "conditionally false".  *(The C
standard does unambiguously say the result of the comparison operators are
[guaranteed to be forced to 1 or 0][3])*

[3]: https://en.cppreference.com/w/c/language/operator_comparison

C++ and C99 have a boolean type, but due to how "integer promotion" works, the
definitions come back to comparing integers again.

*(Note: despite the stronger typing, `true == 1` or `false == 0` do not
generate warnings or errors.  But comparing `boolfunc() == 2` will at least
give "comparison to constant is always false" errors...though no warning is
generated for `boolfunc() == intfunc()`.)*


### JavaScript: true > false => Legal

Much like C, JavaScript's behavior on true and false comparison comes from
numeric conversions, where `true == 1` and `false == 0`.

There is a "strict equality" operator `===` that subverts conversion.  But
greater than and less than [do not have strict forms][4].

[4]: https://stackoverflow.com/questions/14533046/


### Java: true > false => Error

Java actually has two boolean types: a primitive value, and a wrapper class.
The primitive is just `boolean`, and the comparison fails:

    if (true > false) { System.out.println("Greater"); }
              ^
        error: bad operand types for binary operator '>'
        first type:  boolean
        second type: boolean

The wrapper class is `java.lang.Boolean`, which *can't* work because there is
no operator overloading in Java.  So classes cannot define `>` behaviors:

    if (Boolean.TRUE > Boolean.FALSE) { System.out.println("Greater"); }
                     ^
        Main.java:12: error: bad operand types for binary operator '>'
        first type:  Boolean
        second type: Boolean

But to work around the lack of operator overloading, there is a `compare`
method for the class

    if (1 == Boolean.compare(true, false)) { System.out.println("Greater"); }
    Greater  // <-- output

The comparison returns positive if the first argument is greater, negative if
it is lesser, and zero if they are equal.


### Clojure: (> true false) => Error

Clojure runs on top of Java, so it's not surprising that it would have similar
behavior.  But the error is different, seemingly a result of wanting to go
through a numeric cast that is not allowed:

    user=> (> true false)
        Exception in thread "main" java.lang.ClassCastException:
        java.lang.Boolean cannot be cast to java.lang.Number

The [Clojure guide to comparators][5] mentions the availability of `compare`,
which appears to build on top of Java's abilities.  Falling through to Java's
compareTo() is pointed out as why Booleans can be compared this way:

[5]: https://clojure.org/guides/comparators

    user=> (compare true false)
    1

    user=> (compare false true)
    -1


### Rust: true > false => Legal

Rust's Haskell-inspired implementation of the [`Ord` "trait"][6] on booleans
allows `true > false`.

[6]: https://doc.rust-lang.org/std/primitive.bool.html#impl-Ord

It's also willing to convert true to 1 and false to 0, but not implicitly:

    error[E0308]: mismatched types
      |     if true == 1 { println!("Equal"); }
      |                ^ expected `bool`, found integer


### Python: True > False => Legal

Python 2 and 3 both consider `True > False`, with `True == 1` and `False == 0`.
This turns out to be because [Python's boolean *inherits* from integer][7].

[7]: https://www.python.org/dev/peps/pep-0285/

*(Unfortunately, Python's lack of type enforcement means that this is really
just an implementation detail.  Unless checked explicitly by the user, there
is no type signature on functions to enable them to accept only booleans and
not integers.)*


### Go: true > false => Error

The Go language spec is known for being relatively short.  It makes it clear
in [the section on comparison operators][8] that there are only three ordered
types: integers, floating point numbers, and strings.

[8]: https://golang.org/ref/spec#Comparison_operators

    if (true > false) { fmt.Println("Greater") }
       -- invalid operation: true > false
       -- (operator > not defined on bool)

It also won't implicitly make true equal to 1 (or false equal to 0):

    if (true == 1) { fmt.Println("Equal") }
        -- invalid operation: true == 1
        -- (mismatched types untyped bool and untyped int)


### OCaml: true > false => Legal

OCaml has a [`val compare : bool -> bool -> int` definition][9].  There
it says *"compare b0 b1 is a total order on boolean values. false is smaller
than true."*

[9]: https://caml.inria.fr/pub/docs/manual-ocaml/libref/Bool.html

    # true > false ;;
    - : bool = true

Comparisons of booleans and integers give an error:

    # true == 1 ;;
    This expression has type int but an expression was expected of type bool

*(Note: `;;` is not part of the expression, it just tells the REPL you're done
with input.)*


### Ruby: true > false => Error

Ruby's comparison abilities come from methods, and Boolean lacks a definition
for the comparison:

    true > false
        >: undefined method `>' for true:Boolean

*(An interesting quirk about Ruby's methodization of the operator is that they
use `<=>` for method that returns -1, 0, or 1...and call it the "spaceship
operator".)*

While Ruby hasn't defined an ordering, it seems that equality tests are legal
against integers or other values...they just fail:

    true == 1
    => false

    true == "ae1020"
    => false

    false == 0
    => false


## Julia: true > false

Julia allows you to compare booleans against each other, and against integers,
with true == 1 and false == 0:

    julia> true > false
    true

    julia> true == 1
    true

The [Julia documentation mentions "chaining comparisons"][10].  It claims that
this can *"often be quite useful in numerical code"*.

    julia> 1 < 2 <= 2 < 3 == 3 > 2 >= 1 == 1 < 3 != 5
    true

[10]: https://docs.julialang.org/en/v1/manual/mathematical-operations/

Note that this also permits `1 > 2 < 3`.  It also points out the worrying
property that the order of operations is undefined.  :-(


## In Conclusion: *False Is Less Than True!*

If anything, the research I did shows that comparing booleans to each other
*on accident* must not come up that often in practice.  There's scant
discussion on how booleans should compare outside of the Haskellsphere...and
few threads on the error messages.  (Searching the web for `"golang operator >
not defined on bool"` had *no* hits).

I think that the real thing to be concerned about is implicit integer
conversion.  The example from the Julia chained comparisons looks like
something best avoiding in a modern language, vs. embracing it as a feature.
Their mileage may vary.

Yet when you realize Haskell is not conflating the bad properties of some
"hidden integer mechanic" into the type by being ordered, it's less scary.
I'm now basically satisfied that `true > false`.