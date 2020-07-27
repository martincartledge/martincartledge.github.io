---
title: Concurrency in Go - Using Channels, Mutex, and Handling Race Conditions
date: "2020-08-05T22:40:32.169Z"
description: "Learning Go - Week 12"
---

This is the twelth entry of my weekly series _Learning Go_. Last week I talked about [using Goroutines and WaitGroups]() to make use of concurrent patterns in Go. This week I will continue to expand on the topic of concurrency by showung you how to use a few more useful features of Go: _Channels and Mutex_. I will also walk you through how you can idenitfy and fix potential race conditions in your code. Let's get to it!

## Channels

> a "pipe" that allows you to send and receive values in your concurrent Goroutines

Essentially, _Channels_ can be thought of as messengers that you can send to various Goroutines to deliver or retrieve values

- Channels block
- They are syncronized
- They have to pass or receieve the value at the same time

Channels have two important pieces of syntax `<-` and `->`

When you want to send data _onto a Channel_ you use this syntax `<-`

When you want to retrieve data _from a Channel_ you use this syntax `->`

Let me show you a quick example to see Channels in action

```go
package main

import (
	"fmt"
)

func main() {
	c := make(chan int)

	go func() {
		c <- 29
	}()

	fmt.Println(<-c)
}
```
