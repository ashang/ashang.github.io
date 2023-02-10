---
title: Go
date: 2020-06-21
tags: [go, bash]
render_with_liquid: false
toc: true
---
---

```go
- Where("id IN (" + strings.Join(base.Int64sToStrings(ids), ",") + ")").
+ In("id", ids).

- In("issue.repo_id", base.Int64sToStrings(opts.RepoIDs)).
+ In("issue.repo_id", opts.RepoIDs).

- _, err := e.In("id", strings.Join(base.Int64sToStrings(keyIDs), ",")).Delete(new(PublicKey))
+ _, err := e.In("id", keyIDs).Delete(new(PublicKey))
```

==> Downloading https://downloads.sf.net/project/machomebrew/Bottles/go-1.3.3.yosemite.bottle.tar.gz
######################################################################## 100.0%
==> Pouring go-1.3.3.yosemite.bottle.tar.gz
==> Caveats
As of go 1.2, a valid GOPATH is required to use the `go get` command:
  http://golang.org/doc/code.html#GOPATH

`go vet` and `go doc` are now part of the go.tools sub repo:
  http://golang.org/doc/go1.2#go_tools_godoc

To get `go vet` and `go doc` run:
  go get code.google.com/p/go.tools/cmd/godoc
  go get code.google.com/p/go.tools/cmd/vet

You may wish to add the GOROOT-based install location to your PATH:
  export PATH=$PATH:/usr/local/opt/go/libexec/bin

Bash completion has been installed to:
  /usr/local/etc/bash_completion.d

zsh completion has been installed to:
  /usr/local/share/zsh/site-functions


### Hello world

#### hello.go

```go
package main

import "fmt"

func main() {
  message := greetMe("world")
  fmt.Println(message)
}

func greetMe(name string) string {
  return "Hello, " + name + "!"
}
```

```bash
$ go build
```

Or try it out in the [Go repl](https://repl.it/languages/go), or [A Tour of Go](https://tour.golang.org/welcome/1).

### Variables

#### Variable declaration

```go
var msg string
msg = "Hello"
```

#### Shortcut of above (Infers type)

```go
msg := "Hello"
```

### Constants

```go
const Phi = 1.618
```

Constants can be character, string, boolean, or numeric values.

See: [Constants](https://tour.golang.org/basics/15)

## Basic types

### Strings

```go
str := "Hello"
```

```go
str := `Multiline
string`
```

Strings are of type `string`.

### Numbers

#### Typical types

```go
num := 3          // int
num := 3.         // float64
num := 3 + 4i     // complex128
num := byte('a')  // byte (alias for uint8)
```

#### Other types

```go
var u uint = 7        // uint (unsigned)
var p float32 = 22.7  // 32-bit float
```

### Arrays

```go
// var numbers [5]int
numbers := [...]int{0, 0, 0, 0, 0}
```

Arrays have a fixed size.

### Slices

```go
slice := []int{2, 3, 4}
```

```go
slice := []byte("Hello")
```

Slices have a dynamic size, unlike arrays.

### Pointers

```go
func main () {
  b := *getPointer()
  fmt.Println("Value is", b)
}
```

```go
func getPointer () (myPointer *int) {
  a := 234
  return &a
}
```

```go
a := new(int)
*a = 234
```

Pointers point to a memory location of a variable. Go is fully garbage-collected.

See: [Pointers](https://tour.golang.org/moretypes/1)

### Type conversions

```go
i := 2
f := float64(i)
u := uint(i)
```

See: [Type conversions](https://tour.golang.org/basics/13)

## Flow control

### Conditional

```go
if day == "sunday" || day == "saturday" {
  rest()
} else if day == "monday" && isTired() {
  groan()
} else {
  work()
}
```

See: [If](https://tour.golang.org/flowcontrol/5)

### Statements in if

```go
if _, err := doThing(); err != nil {
  fmt.Println("Uh oh")
}
```

A condition in an `if` statement can be preceded with a statement before a `;`. Variables declared by the statement are only in scope until the end of the `if`.

See: [If with a short statement](https://tour.golang.org/flowcontrol/6)

### Switch

```go
switch day {
  case "sunday":
    // cases don't "fall through" by default!
    fallthrough

  case "saturday":
    rest()

  default:
    work()
}
```

See: [Switch](https://github.com/golang/go/wiki/Switch)

### For loop

```go
for count := 0; count <= 10; count++ {
  fmt.Println("My counter is at", count)
}
```

See: [For loops](https://tour.golang.org/flowcontrol/1)

### For-Range loop

```go
entry := []string{"Jack","John","Jones"}
for i, val := range entry {
  fmt.Printf("At position %d, the character %s is present\n", i, val)
}
```

See: [For-Range loops](https://gobyexample.com/range)

### While loop

```go
n := 0
x := 42
for n != x {
  n := guess()
}
```

See: [Go's "while"](https://tour.golang.org/flowcontrol/3)

## Functions

### Lambdas

```go
myfunc := func() bool {
  return x > 10000
}
```

Functions are first class objects.

### Multiple return types

```go
a, b := getMessage()
```

```go
func getMessage() (a string, b string) {
  return "Hello", "World"
}
```


### Named return values

```go
func split(sum int) (x, y int) {
  x = sum * 4 / 9
  y = sum - x
  return
}
```

By defining the return value names in the signature, a `return` (no args) will return variables with those names.

See: [Named return values](https://tour.golang.org/basics/7)

## Packages

### Importing

```go
import "fmt"
import "math/rand"
```

```go
import (
  "fmt"        // gives fmt.Println
  "math/rand"  // gives rand.Intn
)
```

Both are the same.

See: [Importing](https://tour.golang.org/basics/1)

### Aliases

```go
import r "math/rand"
```

```go
r.Intn()
```

### Exporting names

```go
func Hello () {
  ···
}
```

Exported names begin with capital letters.

See: [Exported names](https://tour.golang.org/basics/3)

### Packages

```go
package hello
```

Every package file has to start with `package`.

## Concurrency

### Goroutines

```go
func main() {
  // A "channel"
  ch := make(chan string)

  // Start concurrent routines
  go push("Moe", ch)
  go push("Larry", ch)
  go push("Curly", ch)

  // Read 3 results
  // (Since our goroutines are concurrent,
  // the order isn't guaranteed!)
  fmt.Println(<-ch, <-ch, <-ch)
}
```

```go
func push(name string, ch chan string) {
  msg := "Hey, " + name
  ch <- msg
}
```

Channels are concurrency-safe communication objects, used in goroutines.

See: [Goroutines](https://tour.golang.org/concurrency/1), [Channels](https://tour.golang.org/concurrency/2)

### Buffered channels

```go
ch := make(chan int, 2)
ch <- 1
ch <- 2
ch <- 3
// fatal error:
// all goroutines are asleep - deadlock!
```

Buffered channels limit the amount of messages it can keep.

See: [Buffered channels](https://tour.golang.org/concurrency/3)

### Closing channels

#### Closes a channel

```go
ch <- 1
ch <- 2
ch <- 3
close(ch)
```

#### Iterates across a channel until its closed

```go
for i := range ch {
  ···
}
```

#### Closed if `ok == false`

```go
v, ok := <- ch
```

See: [Range and close](https://tour.golang.org/concurrency/4)

### WaitGroup

```go
import "sync"

func main() {
  var wg sync.WaitGroup

  for _, item := range itemList {
    // Increment WaitGroup Counter
    wg.Add(1)
    go doOperation(&wg, item)
  }
  // Wait for goroutines to finish
  wg.Wait()

}
```

```go
func doOperation(wg *sync.WaitGroup, item string) {
  defer wg.Done()
  // do operation on item
  // ...
}
```

A WaitGroup waits for a collection of goroutines to finish. The main goroutine calls Add to set the number of goroutines to wait for. The goroutine calls `wg.Done()` when it finishes.
See: [WaitGroup](https://golang.org/pkg/sync/#WaitGroup)


## Error control

### Defer

```go
func main() {
  defer fmt.Println("Done")
  fmt.Println("Working...")
}
```

Defers running a function until the surrounding function returns.
The arguments are evaluated immediately, but the function call is not ran until later.

See: [Defer, panic and recover](https://blog.golang.org/defer-panic-and-recover)

### Deferring functions

```go
func main() {
  defer func() {
    fmt.Println("Done")
  }()
  fmt.Println("Working...")
}
```

Lambdas are better suited for defer blocks.

```go
func main() {
  var d = int64(0)
  defer func(d *int64) {
    fmt.Printf("& %v Unix Sec\n", *d)
  }(&d)
  fmt.Print("Done ")
  d = time.Now().Unix()
}
```
The defer func uses current value of d, unless we use a pointer to get final value at end of main.

## Structs

### Defining

```go
type Vertex struct {
  X int
  Y int
}
```

```go
func main() {
  v := Vertex{1, 2}
  v.X = 4
  fmt.Println(v.X, v.Y)
}
```

See: [Structs](https://tour.golang.org/moretypes/2)

### Literals

```go
v := Vertex{X: 1, Y: 2}
```

```go
// Field names can be omitted
v := Vertex{1, 2}
```

```go
// Y is implicit
v := Vertex{X: 1}
```

You can also put field names.

### Pointers to structs

```go
v := &Vertex{1, 2}
v.X = 2
```

Doing `v.X` is the same as doing `(*v).X`, when `v` is a pointer.

## Methods

### Receivers

```go
type Vertex struct {
  X, Y float64
}
```

```go
func (v Vertex) Abs() float64 {
  return math.Sqrt(v.X * v.X + v.Y * v.Y)
}
```

```go
v := Vertex{1, 2}
v.Abs()
```

There are no classes, but you can define functions with _receivers_.

See: [Methods](https://tour.golang.org/methods/1)

### Mutation

```go
func (v *Vertex) Scale(f float64) {
  v.X = v.X * f
  v.Y = v.Y * f
}
```

```go
v := Vertex{6, 12}
v.Scale(0.5)
// `v` is updated
```

By defining your receiver as a pointer (`*Vertex`), you can do mutations.

See: [Pointer receivers](https://tour.golang.org/methods/4)

## Interfaces

### A basic interface

```go
type Shape interface {
  Area() float64
  Perimeter() float64
}
```

### Struct

```go
type Rectangle struct {
  Length, Width float64
}
```

Struct `Rectangle` implicitly implements interface `Shape` by implementing all of its methods.

### Methods

```go
func (r Rectangle) Area() float64 {
  return r.Length * r.Width
}

func (r Rectangle) Perimeter() float64 {
  return 2 * (r.Length + r.Width)
}
```

The methods defined in `Shape` are implemented in `Rectangle`.

### Interface example

```go
func main() {
  var r Shape = Rectangle{Length: 3, Width: 4}
  fmt.Printf("Type of r: %T, Area: %v, Perimeter: %v.", r, r.Area(), r.Perimeter())
}
```

## References

### Official resources

- [A tour of Go](https://tour.golang.org/welcome/1) _(tour.golang.org)_
- [Golang wiki](https://github.com/golang/go/wiki/) _(github.com)_
- [Effective Go](https://golang.org/doc/effective_go.html) _(golang.org)_

### Other links

- [Go by Example](https://gobyexample.com/) _(gobyexample.com)_
- [Awesome Go](https://awesome-go.com/) _(awesome-go.com)_
- [JustForFunc Youtube](https://www.youtube.com/channel/UC_BzFbxG2za3bp5NRRRXJSw) _(youtube.com)_
- [Style Guide](https://github.com/golang/go/wiki/CodeReviewComments) _(github.com)_


proxychains hooks to dynamically loaded libc.

    go doesn't even use libc, it uses its own syscall wrappers
    go doesn't use dynamic linking, it uses static linking



## Getting started

- [A tour of Go](https://tour.golang.org/welcome/1) _(tour.golang.org)_
- [Go repl](https://repl.it/languages/go) _(repl.it)_
- [Golang wiki](https://github.com/golang/go/wiki/) _(github.com)_

### Hello world

#### hello.go
{: .-file}

```go
package main

import "fmt"

func main() {
  message := greetMe("world")
  fmt.Println(message)
}

func greetMe(name string) string {
  return "Hello, " + name + "!"
}
```

```bash
$ go build
```

Or try it out in the [Go repl](https://repl.it/languages/go), or [A Tour of Go](https://tour.golang.org/welcome/1).

### Variables

#### Variable declaration

```go
var msg string
msg = "Hello"
```

#### Shortcut of above (Infers type)

```go
msg := "Hello"
```

### Constants

```go
const Phi = 1.618
```

Constants can be character, string, boolean, or numeric values.

See: [Constants](https://tour.golang.org/basics/15)

## Basic types
{: .-three-column}

### Strings

```go
str := "Hello"
```

```go
str := `Multiline
string`
```

Strings are of type `string`.

### Numbers

#### Typical types

```go
num := 3          // int
num := 3.         // float64
num := 3 + 4i     // complex128
num := byte('a')  // byte (alias for uint8)
```

#### Other types

```go
var u uint = 7        // uint (unsigned)
var p float32 = 22.7  // 32-bit float
```

### Arrays

```go
// var numbers [5]int
numbers := [...]int{0, 0, 0, 0, 0}
```

Arrays have a fixed size.

### Slices

```go
slice := []int{2, 3, 4}
```

```go
slice := []byte("Hello")
```

Slices have a dynamic size, unlike arrays.

### Pointers

```go
func main () {
  b := *getPointer()
  fmt.Println("Value is", b)
}
```
{: data-line="2"}

```go
func getPointer () (myPointer *int) {
  a := 234
  return &a
}
```
{: data-line="3"}

```go
a := new(int)
*a = 234
```
{: data-line="2"}

Pointers point to a memory location of a variable. Go is fully garbage-collected.

See: [Pointers](https://tour.golang.org/moretypes/1)

### Type conversions

```go
i := 2
f := float64(i)
u := uint(i)
```

See: [Type conversions](https://tour.golang.org/basics/13)

## Flow control
{: .-three-column}

### Conditional

```go
if day == "sunday" || day == "saturday" {
  rest()
} else if day == "monday" && isTired() {
  groan()
} else {
  work()
}
```
{: data-line="1,3,5"}

See: [If](https://tour.golang.org/flowcontrol/5)

### Statements in if

```go
if _, err := doThing(); err != nil {
  fmt.Println("Uh oh")
}
```
{: data-line="1"}

A condition in an `if` statement can be preceded with a statement before a `;`. Variables declared by the statement are only in scope until the end of the `if`.

See: [If with a short statement](https://tour.golang.org/flowcontrol/6)

### Switch

```go
switch day {
  case "sunday":
    // cases don't "fall through" by default!
    fallthrough

  case "saturday":
    rest()

  default:
    work()
}
```

See: [Switch](https://github.com/golang/go/wiki/Switch)

### For loop

```go
for count := 0; count <= 10; count++ {
  fmt.Println("My counter is at", count)
}
```

See: [For loops](https://tour.golang.org/flowcontrol/1)

### For-Range loop

```go
entry := []string{"Jack","John","Jones"}
for i, val := range entry {
  fmt.Printf("At position %d, the character %s is present\n", i, val)
}
```

See: [For-Range loops](https://gobyexample.com/range)

### While loop

```go
n := 0
x := 42
for n != x {
  n := guess()
}
```

See: [Go's "while"](https://tour.golang.org/flowcontrol/3)

## Functions
{: .-three-column}

### Lambdas

```go
myfunc := func() bool {
  return x > 10000
}
```
{: data-line="1"}

Functions are first class objects.

### Multiple return types

```go
a, b := getMessage()
```

```go
func getMessage() (a string, b string) {
  return "Hello", "World"
}
```
{: data-line="2"}


### Named return values

```go
func split(sum int) (x, y int) {
  x = sum * 4 / 9
  y = sum - x
  return
}
```
{: data-line="4"}

By defining the return value names in the signature, a `return` (no args) will return variables with those names.

See: [Named return values](https://tour.golang.org/basics/7)

## Packages
{: .-three-column}

### Importing

```go
import "fmt"
import "math/rand"
```

```go
import (
  "fmt"        // gives fmt.Println
  "math/rand"  // gives rand.Intn
)
```

Both are the same.

See: [Importing](https://tour.golang.org/basics/1)

### Aliases

```go
import r "math/rand"
```
{: data-line="1"}

```go
r.Intn()
```

### Exporting names

```go
func Hello () {
  ···
}
```

Exported names begin with capital letters.

See: [Exported names](https://tour.golang.org/basics/3)

### Packages

```go
package hello
```

Every package file has to start with `package`.

## Concurrency
{: .-three-column}

### Goroutines

```go
func main() {
  // A "channel"
  ch := make(chan string)

  // Start concurrent routines
  go push("Moe", ch)
  go push("Larry", ch)
  go push("Curly", ch)

  // Read 3 results
  // (Since our goroutines are concurrent,
  // the order isn't guaranteed!)
  fmt.Println(<-ch, <-ch, <-ch)
}
```
{: data-line="3,6,7,8,13"}

```go
func push(name string, ch chan string) {
  msg := "Hey, " + name
  ch <- msg
}
```
{: data-line="3"}

Channels are concurrency-safe communication objects, used in goroutines.

See: [Goroutines](https://tour.golang.org/concurrency/1), [Channels](https://tour.golang.org/concurrency/2)

### Buffered channels

```go
ch := make(chan int, 2)
ch <- 1
ch <- 2
ch <- 3
// fatal error:
// all goroutines are asleep - deadlock!
```
{: data-line="1"}

Buffered channels limit the amount of messages it can keep.

See: [Buffered channels](https://tour.golang.org/concurrency/3)

### Closing channels

#### Closes a channel

```go
ch <- 1
ch <- 2
ch <- 3
close(ch)
```
{: data-line="4"}

#### Iterates across a channel until its closed

```go
for i := range ch {
  ···
}
```
{: data-line="1"}

#### Closed if `ok == false`

```go
v, ok := <- ch
```

See: [Range and close](https://tour.golang.org/concurrency/4)

### WaitGroup

```go
import "sync"

func main() {
  var wg sync.WaitGroup

  for _, item := range itemList {
    // Increment WaitGroup Counter
    wg.Add(1)
    go doOperation(&wg, item)
  }
  // Wait for goroutines to finish
  wg.Wait()

}
```
{: data-line="1,4,8,12"}

```go
func doOperation(wg *sync.WaitGroup, item string) {
  defer wg.Done()
  // do operation on item
  // ...
}
```
{: data-line="2"}

A WaitGroup waits for a collection of goroutines to finish. The main goroutine calls Add to set the number of goroutines to wait for. The goroutine calls `wg.Done()` when it finishes.
See: [WaitGroup](https://golang.org/pkg/sync/#WaitGroup)


## Error control

### Defer

```go
func main() {
  defer fmt.Println("Done")
  fmt.Println("Working...")
}
```
{: data-line="2"}

Defers running a function until the surrounding function returns.
The arguments are evaluated immediately, but the function call is not ran until later.

See: [Defer, panic and recover](https://blog.golang.org/defer-panic-and-recover)

### Deferring functions

```go
func main() {
  defer func() {
    fmt.Println("Done")
  }()
  fmt.Println("Working...")
}
```
{: data-line="2,3,4"}

Lambdas are better suited for defer blocks.

```go
func main() {
  var d = int64(0)
  defer func(d *int64) {
    fmt.Printf("& %v Unix Sec\n", *d)
  }(&d)
  fmt.Print("Done ")
  d = time.Now().Unix()
}
```
{: data-line="3,4,5"}
The defer func uses current value of d, unless we use a pointer to get final value at end of main.

## Structs
{: .-three-column}

### Defining

```go
type Vertex struct {
  X int
  Y int
}
```
{: data-line="1,2,3,4"}

```go
func main() {
  v := Vertex{1, 2}
  v.X = 4
  fmt.Println(v.X, v.Y)
}
```

See: [Structs](https://tour.golang.org/moretypes/2)

### Literals

```go
v := Vertex{X: 1, Y: 2}
```

```go
// Field names can be omitted
v := Vertex{1, 2}
```

```go
// Y is implicit
v := Vertex{X: 1}
```

You can also put field names.

### Pointers to structs

```go
v := &Vertex{1, 2}
v.X = 2
```

Doing `v.X` is the same as doing `(*v).X`, when `v` is a pointer.

## Methods

### Receivers

```go
type Vertex struct {
  X, Y float64
}
```

```go
func (v Vertex) Abs() float64 {
  return math.Sqrt(v.X * v.X + v.Y * v.Y)
}
```
{: data-line="1"}

```go
v := Vertex{1, 2}
v.Abs()
```

There are no classes, but you can define functions with _receivers_.

See: [Methods](https://tour.golang.org/methods/1)

### Mutation

```go
func (v *Vertex) Scale(f float64) {
  v.X = v.X * f
  v.Y = v.Y * f
}
```
{: data-line="1"}

```go
v := Vertex{6, 12}
v.Scale(0.5)
// `v` is updated
```

By defining your receiver as a pointer (`*Vertex`), you can do mutations.

See: [Pointer receivers](https://tour.golang.org/methods/4)

## Interfaces

### A basic interface

```go
type Shape interface {
  Area() float64
  Perimeter() float64
}
```

### Struct

```go
type Rectangle struct {
  Length, Width float64
}
```

Struct `Rectangle` implicitly implements interface `Shape` by implementing all of its methods.

### Methods

```go
func (r Rectangle) Area() float64 {
  return r.Length * r.Width
}

func (r Rectangle) Perimeter() float64 {
  return 2 * (r.Length + r.Width)
}
```

The methods defined in `Shape` are implemented in `Rectangle`.

### Interface example

```go
func main() {
  var r Shape = Rectangle{Length: 3, Width: 4}
  fmt.Printf("Type of r: %T, Area: %v, Perimeter: %v.", r, r.Area(), r.Perimeter())
}
```

## References

- [A tour of Go](https://tour.golang.org/welcome/1) _(tour.golang.org)_
- [Go repl](https://repl.it/languages/go) _(repl.it)_
- [Golang wiki](https://github.com/golang/go/wiki/) _(github.com)_
- [Effective Go](https://golang.org/doc/effective_go.html) _(golang.org)_
- [Go by Example](https://gobyexample.com/) _(gobyexample.com)_
- [Awesome Go](https://awesome-go.com/) _(awesome-go.com)_
- [JustForFunc Youtube](https://www.youtube.com/channel/UC_BzFbxG2za3bp5NRRRXJSw) _(youtube.com)_
- [Style Guide](https://github.com/golang/go/wiki/CodeReviewComments) _(github.com)_

## 并发执行的“执行体”。执行体是个抽象的概念,在操作系统层面有多个概念

与之对应,比如操作系统自己掌管的进程(process)、进程内的线程(thread)以及进程内的协程
(coroutine,也叫轻量级线程)。多数语言在语法层面并不直接支持协程,而通过库的方式支持的
协程的功能也并不完整,比如仅仅提供协程的创建、销毁与切换等能力。如果在这样的协程中调
用一个同步IO操作,比如网络通信、本地文件读写,都会阻塞其他的并发执行协程,从而无法真
正达到协程本身期望达到的目标。
Go语言在语言级别支持协程,叫goroutine。Go语言标准库提供的所有系统调用(syscall)操
作,当然也包括所有同步IO操作,都会出让CPU给其他goroutine,这让事情变得非常简单。

## 执行体间的通信包含几个方式:
 执行体之间的互斥与同步
 执行体之间的消息传递
先说“执行体之间的互斥与同步”
。当执行体之间存在共享资源(一般是共享内存)时,为
2
3
4
保证内存访问逻辑的确定性,需要对访问该共享资源的相关执行体进行互斥。当多个执行体之间
的逻辑存在时序上的依赖时,也往往需要在执行体之间进行同步。互斥与同步是执行体间最基础
的交互方式。
多数语言在库层面提供了线程间的互斥与同步支持,那么协程之间的互斥与同步呢?呃,不
5
好意思,没有。事实上多数语言标准库中连协程都是看不到的。
再说“执行体之间的消息传递”。在并发编程模型的选择上,有两个流派,一个是共享内存
模型,一个是消息传递模型。多数传统语言选择了前者,少数语言选择后者,其中选择“消息传
递模型”的最典型代表是Erlang语言。业界有专门的术语叫“Erlang风格的并发模型”,其主体思
6
想是两点:一是“轻量级的进程(Erlang中‘进程’这个术语就是我们上面说的‘执行体’)
”,二
是“消息乃进程间通信的唯一方式”
。当执行体之间需要相互传递消息时,通常需要基于一个消
息队列(message queue)或者进程邮箱(process mail box)这样的设施进行通信。
Go语言推荐采用“Erlang风格的并发模型”的编程范式,尽管传统的“共享内存模型”仍然
被保留,允许适度地使用。在Go语言中内置了消息队列的支持,只不过它叫通道(channel)。两
7
个goroutine之间可以通过通道来进行交互。


## Style

 代码风格规范
 错误处理规范
 包管理
 契约规范(接口)
 单元测试规范
 功能开发的流程规范
Go语言很可能是第一个将代码风格强制统一的语言,例如Go语言要求 public 的变量必须以
大写字母开头, private 变量则以小写字母开头,这种做法不仅免除了 public 、 private 关键
字,更重要的是统一了命名风格。

## 错误处理规范:
f, err := os.Open(filename)
if err != nil {
log.Println("Open file failed:", err)
return
}
defer f.Close()
... // 操作已经打开的f文件
这里有两个关键点。其一是 defer 关键字。 defer 语句的含义是不管程序是否出现异常,均
在函数退出时自动执行相关代码。在上面的例子中,正是因为有了 defer ,才使得无论后续是否
会出现异常,都可以确保文件被正确关闭。其二是Go语言的函数允许返回多个值。大多数函数
的最后一个返回值会为 error 类型,以在错误情况下返回详细信息。 error 类型只是一个系统内
置的 interface ,如下:
type error interface {
Error() string
}
有了 error 类型,程序出现错误的逻辑看起来就相当统一。

## 在Java中,你可能这样写代码来保证资源正确释放:
Connection conn = ...;
try {
Statement stmt = ...;
try {
ResultSet rset = ...;
try {
... // 正常代码
}
finally {
rset.close();
}
}
finally {
stmt.close();
}
}
finally {
conn.close();
}
1
2
3
完成同样的功能,相应的Go代码只需要写成这样:
conn := ...
defer conn.Close()
4
stmt := ...
defer stmt.Close()
rset := ...
defer rset.Close()


## Go语言反对函数和操作符重载(overload),而C++、Java和C#都允许出现同名函数或
操作符,只要它们的参数列表不同。虽然重载解决了一小部分面向对象编程(OOP)的问题,但
图灵社区会员 soooldier(soooldier@live.com) 专享 尊重版权
Linux公社(www.LinuxIDC.com)是专业的Linux系统门户网站,实时发布最新Linux资讯。
7
8
9www.Linuxidc.com
6
前言:为什么我们需要一门新语言
同样给这些语言带来了极大的负担。而Go语言有着完全不同的设计哲学,既然函数重载带来了
负担,并且这个特性并不对解决任何问题有显著的价值,那么Go就不提供它。
其次,Go语言支持类、类成员方法、类的组合,但反对继承,反对虚函数(virtual function)
和虚函数重载。确切地说,Go也提供了继承,只不过是采用了组合的文法来提供:
type Foo struct {
Base
...
}
func (foo *Foo) Bar() {
...
}
再次,Go语言也放弃了构造函数(constructor)和析构函数(destructor)。由于Go语言中没
有虚函数,也就没有 vptr ,支持构造函数和析构函数就没有太大的价值。本着“如果一个特性
并不对解决任何问题有显著的价值,那么Go就不提供它”的原则,构造函数和析构函数就这样
被Go语言的作者们干掉了。
在放弃了大量的OOP特性后,Go语言送上了一份非常棒的礼物:接口(interface)。你可能
会说,除了C这么原始的语言外,还有什么语言没有接口呢?是的,多数语言都提供接口,但它
们的接口都不同于Go语言的接口。
Go语言中的接口与其他语言最大的一点区别是它的非侵入性。在C++、Java和C#中,为了实
现一个接口,你需要从该接口继承,具体代码如下:
class Foo implements IFoo { // Java文法
...
}
class Foo : public IFoo { // C++文法
...
}
IFoo* foo = new Foo;
在Go语言中,实现类的时候无需从接口派生,具体代码如下:
type Foo struct { // Go 文法
...
}
var foo IFoo = new(Foo)
只要 Foo 实现了接口 IFoo 要求的所有方法,就实现了该接口,可以进行赋值。
Go语言的非侵入式接口,看似只是做了很小的文法调整,实则影响深远。
其一,Go语言的标准库再也不需要绘制类库的继承树图。你只需要知道这个类实现了哪些
方法,每个方法是啥含义就足够了。
其二,不用再纠结接口需要拆得多细才合理,比如我们实现了 File 类,它有下面这些方法:
图灵社区会员 soooldier(soooldier@live.com) 专享 尊重版权
Linux公社(www.LinuxIDC.com)是专业的Linux系统门户网站,实时发布最新Linux资讯。www.Linuxidc.com
前言:为什么我们需要一门新语言
7
Read(buf []byte) (n int, err error)
Write(buf []byte) (n int, err error)
Seek(off int64, whence int) (pos int64, err error)
Close() error

## 不用为了实现一个接口而专门导入一个包,而目的仅仅是引用其中的某个接口的定义。
在Go语言中,只要两个接口拥有相同的方法列表,那么它们就是等同的,可以相互赋值,如对
于以下两个接口,第一个接口:
1
2
3
package one
type ReadWriter interface {
Read(buf [] byte) (n int, err error)
Write(buf [] byte) (n int, err error)
}
4
第二个接口:
package two
type IStream interface {
Write(buf [] byte) (n int, err error)
Read(buf [] byte) (n int, err error)
}
这里我们定义了两个接口,一个叫 one.ReadWriter ,一个叫 two.IStream ,两者都定义
了 Read() 和 Write() 方法,只是定义的次序相反。 one.ReadWriter 先定义了 Read() 再定义
Write() ,而 two.IStream 反之。
在Go语言中,这两个接口实际上并无区别,因为:
- 任何实现了 one.ReadWriter 接口的类,均实现了 two.IStream ;
- 任何 one.ReadWriter 接口对象可赋值给 two.IStream ,反之亦然;
- 在任何地方使用 one.ReadWriter 接口,与使用 two.IStream 并无差异。
所以在Go语言中,为了引用另一个包中的接口而导入这个包的做法是不被推荐的。因为多
引用一个外部的包,就意味着更多的耦合。

## 函数式编程

### 支持匿名函数
### 支持闭包

## 面向消息编程
### 支持goroutine
### 支持通道
推荐使用消息而不是共享内存来进行并发编程

## 特性:
- 自动垃圾回收
- 更丰富的内置类型
- 函数多返回值
- 错误处理
- 匿名函数和闭包
- 类型和接口
- 并发编程
- 反射
- 语言交互性

### 自动垃圾回收
C语言代码:
```
void foo()
{
    char* p = new char[128];
    ... // 对p指向的内存块进行赋值
    func1(p); // 使用内存指针
    delete[] p;
}
```
各种非预期的原因,比如由于开发者的疏忽导致最后的 delete 语句没有被调用,都会引发
经典而恼人的内存泄露问题。假如该函数被调用得非常频繁,那么我们观察该进程执行时,会发
现该进程所占用的内存会一直疯长,直至占用所有系统内存并导致程序崩溃,而如果泄露的是系
统资源的话,那么后果还会更加严重,最终很有可能导致系统崩溃。
手动管理内存的另外一个问题就是由于指针的到处传递而无法确定何时可以释放该指针所
指向的内存块。假如代码中某个位置释放了内存,而另一些地方还在使用指向这块内存的指针,
那么这些指针就变成了所谓的“野指针”
(wild pointer)或者“悬空指针”
(dangling pointer),对
这些指针进行的任何读写操作都会导致不可预料的后果。
由于其杰出的效率,C和C++语言在非常长的时间内都作为服务端系统的主要开发语言,比
如Apache、Nginx和MySQL等著名的服务器端软件就是用C和C++开发的。然而,内存和资源管
理一直是一个让人非常抓狂的难题。服务器的崩溃十有八九就是因为不正确的内存和资源管理导
致,更讨厌的是这种内存和资源管理问题即使被发现了,也很难定位到具体的错误地点,导致无
数程序员通宵达旦地调试程序。
这个问题在多年里被不同人用不同的方式来试图解决,并诞生了一些非常著名的内存检查工
具,比如Rational Purify、Compuware BoundsChecker和英特尔的Parallel Inspector等。从设计方法的
角度也衍生了类似于内存引用计数之类的方法(通常被称为“智能指针”),


内存泄露的最佳解决方案是在语言级别引入自动垃圾回收算法(Garbage
Collection,简称GC)。所谓垃圾回收,即所有的内存分配动作都会被在运行时记录,同时任何对
该内存的使用也都会被记录,然后垃圾回收器会对所有已经分配的内存进行跟踪监测,一旦发现
有些内存已经不再被任何人使用,就阶段性地回收这些没人用的内存。当然,因为需要尽量最小
化垃圾回收的性能损耗,以及降低对正常程序执行过程的影响,现实中的垃圾回收算法要比这个
复杂得多,比如为对象增加年龄属性等,但基本原理都是如此。
自动垃圾回收在C/C++社区一直作为一柄双刃剑看待,虽然到C++0x(后命名为C++11)正
式发布时,这个呼声颇高的特性总算是被加入了,但按C++之父的说法,由于C++本身过于强大,
导致在C++中支持垃圾收集变成了一个困难的工作。假如C++支持垃圾收集,以下的代码片段在
运行时就会是一个严峻的考验:
```
    int* p = new int;
    p += 10; // 对指针进行了偏移,因此那块内存不再被引用
    // ...... 这里可能会发生针对这块int内存的垃圾收集 ......
    p -= 10; // 咦,居然又偏移到原来的位置
    *p = 10; // 如果有垃圾收集,这里就无法保证可以正常运行了
```
微软的C++/CLI算是用一种偏门的方式让C++程序员们有机会品尝一下垃圾回收功能的鲜美
味道。在C/C++之后出现的新语言,比如Java和C#等,基本上都已经自带自动垃圾回收功能。
Go语言作为一门新生的开发语言,当然不能忽略内存管理这个问题。又因为Go语言没有C++
这么“强大”的指针计算功能,因此可以很自然地包含垃圾回收功能。因为垃圾回收功能的支持,
开发者无需担心所指向的对象失效的问题,因此Go语言中不需要 delete 关键字,也不需要 free()
方法来明确释放内存。例如,对于以上的这个C语言例子,如果使用Go语言实现,我们就完全不
用考虑何时需要释放之前分配的内存的问题,系统会自动帮我们判断,并在合适的时候(比如CPU
相对空闲的时候)进行自动垃圾收集工作。

### 更丰富的内置类型
Go语言也内置了一
些比较新的语言中内置的高级类型,比如C#和Java中的数组和字符串。除此之外,Go语言还内置
了一个对于其他静态类型语言通常用库方式支持的字典类型( map )。Go语言设计者对为什么内
置 map 这个问题的回答也颇为简单:既然绝大多数开发者都需要用到这个类型,为什么还非要每
个人都写一行 import 语句来包含一个库?

#### 数组切片( Slice )
可以认为数组切片是一种可动态增长的数组。
数组切片的功能与C++标准库中的 vector 非常类似。


### 函数多返回值
Go语言革命性地在静态开发语言阵营中率先提供了多返回值功能。这个特性让开发者可以
从原来用各种比较别扭的方式返回多个值的痛苦中解脱出来,既不用再区分参数列表中哪几个用
于输入,哪几个用于输出,也不用再只为了返回多个值而专门定义一个数据结构。
图灵社区会员 soooldier(soooldier@live.com) 专享 尊重版权
Linux公社(www.LinuxIDC.com)是专业的Linux系统门户网站,实时发布最新Linux资讯。
6
7
8
9www.Linuxidc.com
6
第 1 章 初识 Go 语言
在Go语言中,上述的例子可以修改为以下的样子:
func getName()(firstName, middleName, lastName, nickName string){
return "May", "M", "Chen", "Babe"
}
因为返回值都已经有名字,因此各个返回值也可以用如下方式来在不同的位置进行赋值,从
而提供了极大的灵活性:
func getName()(firstName, middleName, lastName, nickName string){
firstName = "May"
middleName = "M"
lastName = "Chen"
nickName = "Babe"
return
}
并不是每一个返回值都必须赋值,没有被明确赋值的返回值将保持默认的空值。而函数的调
用相比C/C++语言要简化很多:
fn, mn, ln, nn := getName()
如果开发者只对该函数其中的某几个返回值感兴趣的话,也可以直接用下划线作为占位符来
忽略其他不关心的返回值。下面的调用表示调用者只希望接收 lastName 的值,这样可以避免声
明完全没用的变量:
_, _, lastName, _ := getName()


### 错误处理
与C++和Java等语言中的异常捕获机制相比,
Go语言的错误处理机制可以大量减少代码量,让开发者也无需仅仅为了程序安全性而添加大量
一层套一层的 try-catch 语句。这对于代码的阅读者和维护者来说也是一件很好的事情,因为可
以避免在层层的代码嵌套中定位业务代码。


### 匿名函数和闭包
Go语言中,所有的函数也是值类型,可以作为参数传递。Go语言支持常规的匿名函数和
闭包,比如下列代码就定义了一个名为 f 的匿名函数,开发者可以随意对该匿名函数变量进行传
递和调用:
f := func(x, y int) int {
return x + y
}

### 类型和接口
Go语言的类型定义非常接近于C语言中的结构(struct),甚至直接沿用了 struct 关键字。相
比而言,Go语言并没有直接沿袭C++和Java的传统去设计一个超级复杂的类型系统,不支持继承
和重载,而只是支持了最基本的类型组合功能。
巧妙的是,虽然看起来支持的功能过于简洁,细用起来你却会发现,C++和Java使用那些复
杂的类型系统实现的功能在Go语言中并不会出现无法表现的情况,这反而让人反思其他语言中
引入这些复杂概念的必要性。我们在第3章中将详细描述Go语言的类型系统。
Go语言也不是简单的对面向对象开发语言做减法,它还引入了一个无比强大的“非侵入式”
接口的概念,让开发者从以往对C++和Java开发中的接口管理问题中解脱出来。在C++中,我们
通常会这样来确定接口和类型的关系:
// 抽象接口
interface IFly {
    virtual void Fly()=0;
};
// 实现类
class Bird : public IFly {
    public:
        Bird() {}
        virtual ~Bird() {}
    public:
        void Fly() {
            // 以鸟的方式飞行
        }
};
void main() {
    IFly* pFly = new Bird();
    pFly->Fly();
    delete pFly;
}
显然,在实现一个接口之前必须先定义该接口,并且将类型和接口紧密绑定,即接口的修改
会影响到所有实现了该接口的类型,而Go语言的接口体系则避免了这类问题:
```
type Bird struct {
    ...
}
func (b *Bird) Fly() {
    // 以鸟的方式飞行
}
```
实现 Bird 类型时完全没有任何 IFly 的信息。我们可以在另外一个地方定义这个 IFly
接口:
type IFly interface {
Fly()
}
这两者目前看起来完全没有关系,现在看看我们如何使用它们:
func main() {
var fly IFly = new(Bird)
fly.Fly()
}
可以看出,虽然 Bird 类型实现的时候,没有声明与接口 IFly 的关系,但接口和类型可以直
接转换,甚至接口的定义都不用在类型定义之前,这种比较松散的对应关系可以大幅降低因为接
口调整而导致的大量代码调整工作。

### 并发编程
Go语言引入了goroutine概念,它使得并发编程变得非常简单。通过使用goroutine而不是裸用
操作系统的并发机制,以及使用消息传递来共享内存而不是使用共享内存来通信,Go语言让并
发编程变得更加轻盈和安全。
通过在函数调用前使用关键字 go ,我们即可让该函数以goroutine方式执行。goroutine是一种
比线程更加轻盈、更省资源的协程。Go语言通过系统的线程来多路派遣这些函数的执行,使得
每个用 go 关键字执行的函数可以运行成为一个单位协程。当一个协程阻塞的时候,调度器就会自
动把其他协程安排到另外的线程中去执行,从而实现了程序无等待并行化运行。而且调度的开销
非常小,一颗CPU调度的规模不下于每秒百万次,这使得我们能够创建大量的goroutine,从而可
以很轻松地编写高并发程序,达到我们想要的目的。
Go语言实现了CSP(通信顺序进程,Communicating Sequential Process)模型来作为goroutine
间的推荐通信方式。在CSP模型中,一个并发系统由若干并行运行的顺序进程组成,每个进程不
能对其他进程的变量赋值。进程之间只能通过一对通信原语实现协作。Go语言用channel(通道)
这个概念来轻巧地实现了CSP模型。channel的使用方式比较接近Unix系统中的管道(pipe)概念,
可以方便地进行跨goroutine的通信。
另外,由于一个进程内创建的所有goroutine运行在同一个内存地址空间中,因此如果不同的
goroutine不得不去访问共享的内存变量,访问前应该先获取相应的读写锁。Go语言标准库中的
sync 包提供了完备的读写锁功能。



### 反射
反射(reflection)是在Java语言出现后迅速流行起来的一种概念。通过反射,你可以获取对
象类型的详细信息,并可动态操作对象。反射是把双刃剑,功能强大但代码可读性并不理想。若
非必要,我们并不推荐使用反射。
Go语言的反射实现了反射的大部分功能,但没有像Java语言那样内置类型工厂,故而无法做
到像Java那样通过类型字符串创建对象实例。在Java中,你可以读取配置并根据类型名称创建对
应的类型,这是一种常见的编程手法,但在Go语言中这并不被推荐。
反射最常见的使用场景是做对象的序列化(serialization,有时候也叫Marshal & Unmarshal)。
例如,Go语言标准库的encoding/json、encoding/xml、encoding/gob、encoding/binary等包就大量
依赖于反射功能来实现。

### 语言交互性
由于Go语言与C语言之间的天生联系,Go语言的设计者们自然不会忽略如何重用现有C模块
的这个问题,这个功能直接被命名为Cgo。Cgo既是语言特性,同时也是一个工具的名称。
在Go代码中,可以按Cgo的特定语法混合编写C语言代码,然后Cgo工具可以将这些混合的C
代码提取并生成对于C功能的调用包装代码。开发者基本上可以完全忽略这个Go语言和C语言的
边界是如何跨越的。
与Java中的JNI不同, Cgo的用法非常简单,比如代码清单1-3就可以实现在Go中调用C语言标
准库的 puts 函数。


## Go语言基础

每个Go源代码文件的开头都是一个 package 声明,表示该Go代码所属的包。包是Go语言里
最基本的分发单位,也是工程管理中依赖关系的体现。要生成Go可执行程序,必须建立一个名
字为 main 的包,并且在该包中包含一个叫 main() 的函数(该函数是Go可执行程序的执行起点)
。
Go语言的 main() 函数不能带参数,也不能定义返回值。命令行传入的参数在 os.Args 变量
中保存。如果需要支持命令行开关,可使用 flag 包

## 函数
所有Go函数(包括在对象编程中会提到的类型成员函数)以关键字 func 开头。一个常规的
函数定义包含以下部分:
func 函数名(参数列表)(返回值列表) {
// 函数体

对应的一个实例如下:
func Compute(value1 int, value2 float64)(result float64, err error) {
// 函数体
}
Go支持多个返回值。以上的示例函数 Compute() 返回了两个值,一个叫 result ,另一个是
err 。并不是所有返回值都必须赋值。在函数返回时没有被明确赋值的返回值都会被设置为默认
值,比如 result 会被设为0.0, err 会被设为 nil 。

## Go project management

http://go-lang.cat-v.org/text-editors/gedit/go.lang

获取gocode:
1
$ go get -u github.com/nsf/gocode

Vim还可以配合gocode支持输入提示功能

+配置gocode:
$ cd /usr/local/go/src/pkg/github.com/nsf/gocode/
$ cd vim
$ ./update.bash
配置就是这么简单。现在使用以下Vim的语法提示效果。用Vim创建一个新的Go文件(比如
命名为auto.go),输入以下内容:
2
3
package main
import "fmt"
func main() {
fmt.Print
请将光标停在 fmt.Print 后面,然后按组合键Ctrl+X+O(三个键同时按住后放开)
,你会看
到 fmt 包里的所有3个以 Print 开头的全局函数都被列了出来: Print 、 Printf 和 Println 。之
后就可以用上下方向键选取,按回车键即可完成输入,非常方便。
gocode其实是一个独立地提供输入提示的服务器程序,并非专为Vim打造


liteide

Go命令行工具的革命性之处在于彻底消除了工程文件的概念,完全用目录结构和包名来推
导工程结构和构建顺序。

## 变量
### 变量声明
Go语言的变量声明方式与C和C++语言有明显的不同。对于纯粹的变量声明,Go语言引入了
关键字 var ,而类型信息放在变量名之后,示例如下:
var v1 int
var v2 string
var v3 [10]int
var v4 []int
var v5 struct {
    f int
}
var v6 *int
var v7 map[string]int
var v8 func(a int) int

var (
    v1 int
    v2 string
)

# Go语言的优势
## 部署简单

Go 编译生成的是一个静态可执行文件，除了 glibc 外没有其他外部依赖。这让部署变得异常方便：目标机器上只需要一个基础的系统和必要的管理、监控工具，完全不需要操心应用所需的各种包、库的依赖关系，大大减轻了维护的负担。可直接编译成机器码，不依赖其他库，glibc的版本有一定要求，部署就是扔一个文件上去就完成了。

## 性能优秀

虽然不如 C 和 Java，但通常比原生 Python 应用还是高一个数量级的，适合编写一些瓶颈业务。内存占用也非常省。
并发性&通道

Goroutine 和 channel 使得编写高并发的服务端软件变得相当容易，很多情况下完全不需要考虑锁机制以及由此带来的各种问题。单个 Go 应用也能有效的利用多个 CPU 核，并行执行的性能好。


## 良好的语言设计

Go 非常简单，且易于学习。从学术的角度讲 Go 语言其实非常平庸，不支持许多高级的语言特性；但从工程的角度讲，Go 的设计是非常优秀的：规范足够简单灵活。正是由于 Go 的简单性，任何的 Python、Elixir、C++、Scala 或者 Java 开发者皆可在一月内组建成一个高效的 Go 团队。

## 标准库&工具

Go目前已经内置了大量的库，特别是网络库非常强大。更重要的是 Go 自带完善的工具链，大大提高了团队协作的一致性。比如 gofmt 自动排版 Go 代码，很大程度上杜绝了不同人写的代码排版风格不一致的问题。把编辑器配置成在编辑存档的时候自动运行 gofmt，这样在编写代码的时候可以随意摆放位置，存档的时候自动变成正确排版的代码。此外还有 gofix, govet 等非常有用的工具。

## Go成功的项目

Go语言在云时代得到了比较广泛的应用，特别是Docker和K8s这样的杀手级产品的出现让Go语言在工程界占有一席之地 除此之外Go语言还有非常多的成功运行中的软件： nsq：bitly开源的消息队列系统，性能非常高，目前他们每天处理数十亿条的消息 packer:用来生成不同平台的镜像文件，例如VM、vbox、AWS等，作者是vagrant的作者 skynet：分布式调度框架 Doozer：分布式同步工具，类似ZooKeeper Heka：mazila开源的日志处理系统 cbfs：couchbase开源的分布式文件系统 tsuru：开源的PAAS平台，和SAE实现的功能一模一样 groupcache：memcahe作者写的用于Google下载系统的缓存系统 god：类似redis的缓存系统，但是支持分布式和扩展性 gor：网络流量抓包和重放工具

## 生态卡位和隐性标准

除了打铁还需自身硬之外，还有些机遇和运势，让区块链选择的了Go语言。我们来看区块链2.0以来最成功的公链和联盟链代表，以太坊和超级账本Fabric，无一例外都选择使用Go作为开发语言（虽然以太坊其实也有其他语言的客户端版本，但进入到Homestead阶段以后，Go客户端占据了主导地位），这两大超级区块链的影响力可不是一般项目可以比拟的，不仅在生态中占据了大的坑位，事实上还隐性的制定了区块链的标准，不论是公链中的智能合约，还是联盟链的技术，都绕不开以太坊和Fabric。

Hyperledger Fabric是已部署的企业区块链网络中使用最多的协议框架，超级账本Hyperledger（其中Fabric作为旗舰协议）是集成商和软件开发平台最常支持的协议框架，比例达到了53%。 而在所有的区块链技术书籍里面，有关超级账本的书籍是卖的最为火爆这个事实也是侧面印证了超级账本Hyperledger的影响力。

## 实践

循环也只有for一种表示方法，就可以实现数值、键值等各种遍历。因此，Go语言上手非常容易。Go语言最有特色的特性莫过于goroutine。Go语言在语言层可以通过goroutine对函数实现并发执行。goroutine类似于线程但是并非线程，goroutine会在Go语言运行时进行自动调度。因此，Go语言非常适合用于高并发网络服务的编写。1．上手容易很多读者表示自己是在看了介绍后才开始了解这门语言的。他们一般也会使用两到三门编程语言。Go语言对于他们来说，也就是一到两天的熟悉过程，之后就可以开始使用Go语言解决具体问题了。大约一周左右已经可以使用Go语言完成既定的任务了。Go语言这种从零开始使用到解决问题的速度，在其他语言中是完全不可想象的。学过C++的朋友都知道，一到两年大强度的理论学习和实战操练也只能学到这门语言的皮毛，以及知道一些基本的避免错误的方法。那么，Go语言到底有多么简单？下面从实现一个HTTP服务器开始了解。HTTP文件服务器是常见的Web服务之一。开发阶段为了测试，需要自行安装Apache或Nginx服务器，下载安装配置需要大量的时间。使用Go语言实现一个简单的HTTP服务器只需要几行代码，

Go语言不仅可以输出可执行文件，还可以编译输出能导入C语言的静态库、动态库。同时从Go 1.7版本开始，Go语言支持将代码编译为插件。使用插件可以动态加载需要的模块，而不是一次性将所有的代码编译为一个可执行文件。3．工程结构简单Go语言的源码无须头文件，编译的文件都来自于后缀名为go的源码文件；Go语言无须解决方案、工程文件和Make File。只要将工程文件按照GOPATH的规则进行填充，即可使用go build/go install进行编译，编译安装的二进制可执行文件统一放在bin文件夹下。后面的章节会介绍GOPATH及go build/go install的详细使用方法。4．编译速度快Go语言可以利用自己的特性实现并发编译，并发编译的最小元素是包。从Go 1.9版本开始，最小并发编译元素缩小到函数，整体编译速度提高了20%。另外，Go语言语法简单，具有严谨的工程结构设计、没有头文件、不允许包的交叉依赖等规则，在很大程度上加速了编译的过程。5．高性能

6．原生支持并发Go语言的特性就是从语言层原生支持并发，无须第三方库、开发者的编程技巧及开发经验就可以轻松地在Go语言运行时来帮助开发者决定怎么使用CPU资源。Go语言的并发是基于goroutine，goroutine类似于线程，但并非线程。可以将goroutine理解为一种虚拟线程。Go语言运行时会参与调度goroutine，并将goroutine合理地分配到每个CPU中，最大限度地使用CPU性能。多个goroutine中，Go语言使用通道（channel）进行通信，程序可以将需要并发的程序设计为生产者和消费者的模式，将数据放入通道。通道的另外一端的代码将这些数据进行并发计算并返回结果，


使用Go语言工具链可以直接进行Go代码的性能分析。Go的性能分析工具将性能数据以二进制文件输出，配合Graphviz即可将性能分析数据以图形化的方式展现出来，如图1-2所示。[插图]图1-2 配合Graphviz工具生成的性能分析图图中每个方框代表一个函数的执行流程，Go语言会通过图连接和数据告知每个执行步骤的耗时，较为耗时的流程执行框会变大。开发人员根据这些直观的图表即可迅速定位问题代码的位置。8．强大的标准库Go语言的标准库覆盖网络、系统、加密、编码、图形等各个方面，可以直接使用标准库的http包进行HTTP协议的收发处理；网络库基于高性能的操作系统通信模型（Linux的epoll、Windows的IOCP）；所有的加密、编码都内建支持，不需要再从第三方开发者处获取。Go语言的编译器也是标准库的一部分，通过词法器扫描源码，使用语法树获得源码逻辑分支等。Go语言的周边工具也是建立在这些标准库上。在标准库上可以完成几乎大部分的需求。Go语言的标准库以包的方式提供支持


# Projects

etcd项目网址为https://github.com/coreos/etcd。介绍：一款分布式、可靠的KV存储系统，可以快速进行云配置。5．beego项目网址为https://github.com/astaxie/beego。介绍：beego是一个类似Python的Tornado框架，采用了RESTFul的设计思路，使用Go语言编写的一个极轻量级、高可伸缩性和高性能的Web应用框架。6．martini项目网址为https://github.com/go-martini/martini。介绍：一款快速构建模块化的Web应用的Web框架。7．codis项目网址为https://github.com/Codis Labs/codis。介绍：国产的优秀分布式Redis解决方案。8．delve项目网址为https://github.com/derekparker/delve。介绍：Go语言强大的调试器，被很多集成环境和编辑器整合

There are two Go compilers nowadays
* `go` interface to the set of compilation tools
  - fast compilation
  - official tools (go get, go doc, etc.)
  - cross-compilation
* `gccgo` frontend for `gcc` part of its compiler collection
  - goroutines becomes full flow
  - small size of the binary (dynamic linking)

## Hello Go

```go
//hello.go

package main

import "fmt"

func main() {
    fmt.Println("Hello, Go!")
}
```

```bash
# run go
$ go run hello.go

# Compilation with standard gc compiler (same as go build -compiler=gc hello.go)
$ go build hello.go

# Compilation with gccgo (same as go build -compiler=gccgo hello.go)
$ gccgo hello.go -o hello

```

### $GOPATH

Go dependencies, when used for example in statements, are searched for in the variable, and then - in (*go* installation directory, by default). If you expect to use external dependencies, not only basic from , you must specify workspace area in your (or equivalent):

`export GOPATH=~/go`

Create that workspace:

`$ mkdir -p ~/go/{bin,src}`

Directory is used to store sources of the project, and for executables.

Also you can add path to directory in [environment variable](environment_variable "wikilink") to run installed programs (written on Go language) anywhere (like, for example, ):

`export PATH="$PATH:$GOPATH/bin"`

Note that we also add the subdirectory to the so we can run any executables that be required.

Run for more information.

### Enable cross compilation for other platforms

The official package only supports Linux amd64, 386 and arm architectures. To support cross compilation for Darwin, FreeBSD and MS Windows, follow along as below.

You can not build of itself, ie if you set to you will get a warning like this.

` $ cd /usr/lib/go/src`
` $ GOROOT_BOOTSTRAP=/usr/lib/go GOOS=darwin GOARCH=amd64 ./make.bash --no-clean `
` ##### Building Go bootstrap tool.`
` cmd/dist`
` ERROR: $GOROOT_BOOTSTRAP must not be set to $GOROOT`
` Set $GOROOT_BOOTSTRAP to a working Go tree >= Go 1.4.`

To get around this, grab a source copy of Go from <https://golang.org/>.

Build your downloaded Go with your system GO.

` $ cd ~/downloads/go/src`
` $ GOROOT_BOOTSTRAP=/usr/lib/go GOOS=linux GOARCH=amd64 ./make.bash --no-clean`

You can now build your system Go using the downloaded Go as bootstrap with this command.

` $ cd /usr/lib/go/src; for os in darwin freebsd windows; do for arch in amd64 386; do sudo GOROOT_BOOTSTRAP="$HOME/downloads/go" GOOS=$os GOARCH=$arch ./make.bash --no-clean; done; done`


# 语言约定

所有的`Go`源文件都必须以`package 包名`开头，如果是独立运行的执行文件则必须是`package main`

一个`Go`源文件，首先是出现`package 包名`，紧跟着然后就是`import "库名"`，再然后才是程序的其他部分

和`C/C++`一样，每个`Go`程序都必须有一个`main`函数，且程序总是从`main`开始执行

`Go`语句不需要尾部的分号，除非是将多条语句书写在同一行，那就需要用到分号了

`Go`最大的不同在于，其他语言都是将类型放在变量名前面，而`Go`正好相反，类型位于变量名之后，如 `var a int`（`C语言`写作 `int a;`）

编译器相当严格，如果程序中存在声明了但未使用的变量，编译器直接报错而不是警告（导入的包没有使用也一样会报错）

原生支持复数

没有`逗号`表达式，没有三元运算符`? :`

同一源文件中，可以在一个函数还没定义的情况下调用执行，不再需要`C/C++`中的函数原型声明

控制结构强制使用大括号，而且大括号强制缩进，可以说，`Go`就是为了打造成一门具有高规范度的工业级语言

# 变量赋值

`Go`有两套赋值语法，一种是`var a int = 15`的形式，另一种是`a := 15`，但后一种形式只能用于函数里面

`:=`的形式是可以自行推导变量类型的，赋值时无需声明类型

`var`的形式允许同时声明多个变量，如 `var x, y int = 10, 20`，相当于其他语言里的 `int x = 10, y = 20;`

类似的，`:=`也支持多个变量的同时声明，如 `a, b := 10, 20`

多个变量也可以成组声明，语法形式如下（`const`和`import`也支持这样的用法）

{{{Go
var(
  x int
  y string
  z bool
)
}}}

`Go`有一个特殊的变量，`_`（下划线），任何赋给它的值都会被丢弃，如 `_, a := 1, 2`，`1`将被丢弃，`a`的值为`2`

### 数据类型

`C/C++`中，强制类型转换使用的形式是`(int)a`，而在`Go`中写法为`int32(a)`

#### 布尔型

布尔型（`bool`）有两个值，`true`和`false`。在格式化输出`bool`类型时，格式符为`%v`，`%v`的意思是使用默认格式

#### 数值类型

数值类型有以下种类：

`byte`、`rune`、`int`、`int8`、`int16`、`int32`、`int64`、`int64`、`uint8`、`uint16`、`uint32`、`uint64`、`float32`、`float64`

`byte`是`uint8`的别名，`rune`是`int32`的别名，需要注意的是，`Go`没有`float`类型，只有`float32`和`float64`

以上各种数据类型不能混用，这点`Go`表现得比其他语言严格得多

此外还支持`八进制`、`十六进制`和`科学计数法`

#### 常量

`Go`使用`const`关键字声明常量，声明语法如下：

// 第一种
const x = 20

// 第二种1
const(
  a = 1
  b = 2
)

// 第二种2，自动生成枚举值
const(
  a = iota  // a = 0
  b = iota  // b = 1
  c = iota  // c = 2
)

// 第二种3，使用自动枚举时，可以省略后续的符号
const(
  a = iota  // a = 0
  b         // b = 1
  c         // b = 2
)

// 第二种4，指定常量的类型
const(
  a = 4
  b string = "Ruchee"
)

#### 字符串

单引号包围的是字符，双引号包围的是字符串，`Go`语言的字符串是不可变的，不像`C语言`一样可以将字符串当数组来用

字符串声明示例：`var s string = "Ruchee"`、`s := "Ruchee"`

多行字符串使用`+`相连，但`+`号必须书写在上一行字符串的末尾，这样才能避免编译器识别错误，如下所示：

{{{Go
s := "Hello " +
     "World!"
}}}

多行字符串还可以使用`反引号`来包围（`反引号`一般位于数字键`1`的左边），这种方式可以将字符串里面的内容原封不动的传送，但换行符和其他转义字符依然有效

#### 复数

复数的变量类型有`complex64`和`complex128`两种，打印复数使用的格式符是`%v`

var c complex64 = 2 + 3i

fmt.Printf("c = %v\n", c)  // 输出结果为：c = (2+3i)

## 错误类型

`Go`专门为错误内建了一个数据类型`error`，其默认初始值为`nil`

# 操作符

`Go`支持常规的位运算与逻辑运算，使用的符号也与`C语言`一致

但`Go`除了支持`&`、`|`、`^`以外，还提供了一个`位清除`运算符`&^`，譬如`var a, b int = 3, 2`，则`a &^ b`则表示`a`中凡是与`b`中`1`对应的位都被清除为`0`，所以`11`被`10`清除为`01`，结果为`1`

支持常见的复合运算符，如 `+=`、`-=`等

支持自加、自减运算符，但`++`与`--`都只允许后置，不能放在变量前面，所以`++i`的写法是错误的，只能写成`i++`

## 控制结构

`Go`对控制结构进行了大幅缩减，没有了`do`，没有了`while`，只有`if`、`switch`和`for`，另外增加了一个用于多路通讯转接器的`select`

`if`和`switch`可以有初始化语句，就像`for`一样，这通常用于设置一个局部变量

`if-else`的条件部分不需要使用括号（用括号也`OK`，不会报错），且`if-else`强制缩进，各个选择分支也强制使用大括号包围

`switch`进行了扩展，其可以没有用于判别的表达式（这将默认匹配为`true`），且每条`case`分支会在匹配后自动中断执行，如果需要继续向下匹配就必须显式使用关键字`fallthrough`

每条`case`分支的匹配项不再仅限于一个数据，可以使用一个逗号分隔的列表，如下所示：

switch c{
  case 0:
    xxx
  case 1, 2, 3, 4, 5, 6, 7, 8, 9:
    xxx
  case 10:
    xxx
}

## `for`

```
// 第一种，和C语言的for差不多
for init; condition; post {}

// 第二种，相当于C语言的while
for condition {}

// 第三种，相当于C语言的for(;;)，死循环
for {}
```

支持`return`、`break`和`continue`这三个关键字，除了`break`支持自定义标签中断外，其他都与`C语言`别无二致

`Go`保留了`goto`关键字，只允许在函数内部跳转，不能跨越多个函数（使用方法和`C语言`一样）

`Go`另外增加了一个迭代器`range`，用于遍历`array`、`string`、`map`等数据结构，它可以很容易实现索引与内容的拆分
## golang/x/blog

- https://github.com/golang/blog

a web server for the Go blog that can run on App Engine or as a stand-alone HTTP server.

## go build

    go build -ldflags '-s -w'
    go build -gcflags -m

## macaron

    go get gopkg.in/macaron.v1


## Standard library (https://golang.org/pkg/)
○ io/ioutil/os
○ flag
○ net (http, rpc, smtp)
○ encoding (JSON, xml, hex, csv, binary, ...)
○ compress and archive (tar, zip, gzip, bzip2, zlib, lzw, ...)
○ crypto (aes, des, ecdsa, hmac, md5, rsa, sha1, sha256, sha512, tls, x509, ...)
○ database (sql)
○ regexp
○ sync and atomic
○ unsafe and syscall
○ fmt
○ test
○ cover
○ pprof
○ doc
○ get
○ vet
○ race detector
○ and many more


## Go compilers
- The original gc, the Go compiler, was written in C
- As of Go 1.5 the compiler is written in Go with a recursive descent parser
and uses a custom loader, based on the Plan 9 loader
- gccgo (frontend for GCC; https://golang.org/doc/install/gccgo)
  - gcc 7 supports Go 1.8.1
- Fast!, even with large modules

## Debugging
- Gdb
- Delve (https://github.com/derekparker/delve)

## Testing
● Unit tests
● Benchmarks
● All you need:
○ add “_test” to filename
○ add “Test” to function
○ import “testing”

## Basic types
○ bool
○ string
○ int, int8, int16, int32, int64
○ uint, uint8, uint16, uint32, uint64
○ byte //alias for uint8
○ rune //represents a Unicode point; alias for int32
○ float, float64
○ complex64, complex128


```
package main
var e, l, c bool
func main() {
  var prague int
  var elc string = “linux”
  var a, s, d = true, false, “data”
  f := 1
}
```

```
func div(x, y int) (int, error) {
  if y == 0 {
  return 0, errors.New("div by 0")
  }
  return x / y, nil
}
func main() {
  fmt.Println(div(4, 0))
}
```

## Interfaces
- Set of method signatures
- Implemented implicitly
■ no explicit declaration
■ no “implements”
- Decoupled definition and implementation
- Empty interface interface{}



## golang-go vs. gccgo

> The Go language has always been defined by a spec, not an implementation. The Go team has written two different compilers that implement that spec: gc and gccgo.
>
> Gc is the original compiler, and the go tool uses it by default.
> Gccgo is a different implementation with a different focus
> Compared to gc, gccgo is slower to compile code but supports more powerful optimizations, so a CPU-bound program built by gccgo will usually run faster.
>
> The gc compiler supports only the most popular processors: x86 (32-bit and 64-bit) and ARM.
> Gccgo, however, supports all the processors that GCC supports.
> Not all those processors have been thoroughly tested for gccgo, but many have, including x86 (32-bit and 64-bit), SPARC, MIPS, PowerPC and even Alpha.
> Gccgo has also been tested on operating systems that the gc compiler does not support, notably Solaris.
> if you install the go command from a standard Go release, it already supports gccgo via the -compiler option: go build -compiler gccgo myprog.
>


## faq

- https://golang.org/doc/faq

> Go was born out of frustration with existing languages and environments for
> systems programming.

> One had to choose either efficient compilation, efficient execution, or ease of
> programming; all three were not available in the same mainstream language.


## Native concurrent execution and communication
## stack and heap allocations ??
