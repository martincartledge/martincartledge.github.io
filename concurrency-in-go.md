---
title: Concurrency in Go
date: "2020-07-29T22:40:32.169Z"
description: "Learning Go - Week 11"
---

This is the eleveneth entry of my weekly series *Learning Go*. Last week I talked about [Sorting Data in Go](). This week I will be talking about how Concurrency works in Go. Before I really dive into the topic of Concurrency, I feel that I need to make some differences between Concurrency and Parallelism since they often times are confused with eachother. I will also explain a few pieces of the Go language that allows for us to use Concurrency. These pieces are Go Routines and Go Statements.

## Concurrency vs. Parallelism

- Natively takes advantage of multiple core processors
- Open sourced in 2012
- Writing code on one CPU will *not* run your code in parallel
- Concurrency is a pattern to allow code to execute in parallel

## Concurrency

> the ability for various parts of a program to be ran (executed) out-of-order, or in partial order without affecting the final result

- Concurrency is made difficult by the subtleties required to implement correctly across shared variables
- Shared values are passed around on Channels
- Never shared on seperate threads of execution
- Does not communicate by sharing memory, share memory by communicating

## Go Routines

- Multiplexed
- Used with functions or methods
- Used with the `go` keyword

## Go Statements

- Starts with the execution of a function call as an independent concurrent thread of control or Go routine within the same address space
- Must be a function or a method call
- If the function has return values they are discarded when the function completes

Before we jump into how to use *Concurrency* in Go, I think we should discuss a few of the pillars around writing *Concurrent* code in Go. A few of these pillars are *Go Routines* and *Channels*

## Goroutines

> a lightweight thread of execution

So, what is a *goroutine* and why should I care about them? Here's a few things to consider:

- Goroutines are non-blocking (*asyncronous*)
- Due to being asyncronous, multiple goroutines can run *concurrently* (multiple pieces ran at the same time without affecting the final result)
- If you wish to wait for your *goroutine* to finish before you continue, you can use a *WaitGroup* (we will cover this later in the post)

Let's take a look at an example of using a traditional function (blocking) with a few *goroutines* (non-blocking) to better illustrate their place in our Go code

```go
package main

import (
	"fmt"
	"time"
)

func countToFive(wasCalledBy string) {
	for i := 0; i < 5; i++ {
		fmt.Println(wasCalledBy, i)
	}
}

func countToThree(wasCalledBy string) {
	for i := 0; i < 3; i++ {
		fmt.Println(wasCalledBy, i)
	}
}

func main() {
	countToFive("direct - blocking")

	go countToFive("I am a goroutine!")

	go countToThree("I am another goroutine!")

	time.Sleep(time.Second)
	fmt.Println("exit program")
}
// direct - blocking 0
// direct - blocking 1
// direct - blocking 2
// direct - blocking 3
// direct - blocking 4
// using another goroutine! 0
// using a goroutine 0
// using a goroutine 1
// using a goroutine 2
// using a goroutine 3
// using a goroutine 4
// using another goroutine! 1
// using another goroutine! 2
```

Let's walk through what is happening:

> Quick note: we are importing the `time` package because we need to *wait* for a second in order to allow our *goroutines* to finish. Remember, they are not blocking (syncronous); therefore, we need to wait for them to finsih their computations.

We import the `time` package that we will use in this example just to wait for our *goroutines* to finish. I have found it is much more common to use a [WaitGroup](), we will discuss these later in the post

```go
import (
	"fmt"
	"time"
)
```

Next, we create two functions, `countToFive` and `countToThree`, both of these expect a single paramter `wasCalledBy` which is of type `string`.
```go
func countToFive(wasCalledBy string) {
	for i := 0; i < 5; i++ {
		fmt.Println(wasCalledBy, i)
	}
}

func countToThree(wasCalledBy string) {
	for i := 0; i < 3; i++ {
		fmt.Println(wasCalledBy, i)
	}
}
```

Calling our *goroutine* with the `wasCalledBy` argument will help illustrate how Go executes these *goroutines*

Inside of `func` `main` I call the `countToFive` function directly, without making use of a *goroutine*

```go
func main() {
	countToFive("direct - blocking")
```

As the argument says, because I am not using the `go` keyword and creating a *goroutine*, this code will be syncronous and block our thread of execution

On the next line I create a *goroutine*. I do so very easily by calling the same function and placing the `go` keyword in front of the function identifier

```go
go countToFive("I am a goroutine!")
```
