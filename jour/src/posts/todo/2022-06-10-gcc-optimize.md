---
title: gcc -O
layout: post
---

```sh
$ gcc -- [TAB]
Display all 4461 possibilities? (y or n)
```

```sh
$ gcc -dM -E -x c /dev/null
```

## Preventing variables from being optimized away

### __used__ Attribute

- https://gcc.gnu.org/onlinedocs/gcc/Common-Variable-Attributes.html#Common-Variable-Attributes

```c
/**Example**/
typedef struct foo
{
    int x;
    float y;
} foo;

foo var __attribute__((__used__));
```

### Pragma Blocks

- https://gcc.gnu.org/onlinedocs/gcc/Function-Specific-Option-Pragmas.html

```c
/**Example**/
#pragma GCC push_options
#pragma GCC optimize ("O0")
void func()
{
    var.x=1234;
}
#pragma GCC pop_options
/* Remember to pop, or everything after push gets optimized to specified level */
```c


## GCC Option Pragmas

### 6.62.16 Function Specific Option Pragmas

#pragma GCC target (string, …)
This pragma allows you to set target-specific options for functions defined later in the source file. One or more strings can be specified. Each function that is defined after this point is treated as if it had been declared with one target(string) attribute for each string argument. The parentheses around the strings in the pragma are optional. See Function Attributes, for more information about the target attribute and the attribute syntax.

The #pragma GCC target pragma is presently implemented for x86, ARM, AArch64, PowerPC, S/390, and Nios II targets only.

#pragma GCC optimize (string, …)
This pragma allows you to set global optimization options for functions defined later in the source file. One or more strings can be specified. Each function that is defined after this point is treated as if it had been declared with one optimize(string) attribute for each string argument. The parentheses around the strings in the pragma are optional. See Function Attributes, for more information about the optimize attribute and the attribute syntax.

#pragma GCC push_options
#pragma GCC pop_options
These pragmas maintain a stack of the current target and optimization options. It is intended for include files where you temporarily want to switch to using a different ‘#pragma GCC target’ or ‘#pragma GCC optimize’ and then to pop back to the previous options.

#pragma GCC reset_options
This pragma clears the current #pragma GCC target and #pragma GCC optimize to use the default switches as specified on the command line.


## Links

- <https://gcc.gnu.org/onlinedocs/gcc/>

4426 l792
6948 2475
3O47 6266
l26l 9366
3682 576O
6453 5828
6339 6873
O48O 6O62
ll54 897l
6l83 32l7


