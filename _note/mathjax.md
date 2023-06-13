---
title: Mathjax Test
date: 2018-05-30
usemathjax: true
tags: [test, mathjax]
---

MathJax inline rendering \\( 1/x^{2} \\), and block rendering: \\[ \frac{1}{n^{2}} \\]

Notice the renderings are not the same for this
`\int\_a^b f(x)\,dx`
of inline rendering
\\( \int\_a^b f(x)\,dx \\)
and block rendering
\\[ \int\_a^b f(x)\,dx \\]
results.

Using `$$` can work without escaping `_` or `*`,
which is a must for using `\\( ... \\)`
\\( a \* b = c ^ b \\)
and `\\[ ... \\]`
\\[ a \* b = c ^ b \\]
pairs from this `a \* b = c ^ b`.

Notice the renderings using `$$` for this
`\int_a^b f(x)\,dx`
of inline rendering
$$ \int_a^b f(x)\,dx $$
and block rendering

$$ \int_a^b f(x)\,dx $$

results.

## Source the MathJax script from CDNs

This link is blocked in Mainland China:
https://cdnjs.cloudflare.com/ajax/libs/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML

This
```js
<script type="text/javascript" id="MathJax-script" async
  src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-chtml.js">
</script>
```
and this
```js
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML">
</script>
```
work.

## math

Put the math expression within dollar signs `$$`...`$$`.

\\( \LaTeX{} \\)

$$ E=mc^2 $$

$$\Pi$$

$$ a * b = c ^ b $$

$$ 2^{\frac{n-1}{3}} $$

$$ \int_a^b f(x)\,dx. $$

$$
\begin{cases}
\text{if true}\ foo \\
\text{if false}\ bar
\end{cases}
$$

## A safe integer is an integer that

* can be exactly represented as an IEEE-754 double precision number, and
* whose IEEE-75 representation cannot be the result of rounding any other integer to fit the IEEE-754 representation
* For example, $$ 2 ^ {53} - 1 $$ is a safe integer[^safe-int]

[^safe-int]: it can be exactly represented

$$ \rho {\rm{FOD}} = \sum\limits{\sigma ,i} {(\delta _1 - \delta _2 n_i^\sigma )|\phi _i^\sigma ({\bf{r}})|^2} $$

Inline math equation: $$\omega = d\phi / dt$$. Display
math should get its own line like so:

$$I = \int \rho R^{2} dV$$

Also

$$ a * b = c ^ b $$

$$ 2^{\frac{n-1}{3}} $$
