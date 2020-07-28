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

When you want to send data _onto a Channel_ you use this syntax `channel <-`

When you want to retrieve data _from a Channel_ you use this syntax `<- channel`

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

Inside of our `func` `main` we use the short declaration operator to create a new variable with the identifier `c`. We use the `make` keyword to create a new `chan` which will be of type `int`

```go
c := make(chan int)
```

Next, we create an annoymous _Goroutine_. Inside of this _Goroutine_, using the `c <-` syntax we are sending the value `29` onto our `c` _channel_. We use the `()` to immeaditely run this _Goroutine_

```go
go func() {
	c <- 29
}()
```

We use the `<- c` syntax to get the value off of our channel and print the value of `c`. When we go, it should be no surpirse that we get the value `29`. Cool! We have successfully sent data to a _channel_ and receieved a value from a _channel_.

```go
fmt.Println(<-c)
// 29
```

What if we want to limit the amount of data that can be sent onto a _Channel_ we create? Go makes this possible by using a feature called _Channel Buffering_

By default, _Channels_ are unbuffered, meaning that there is not limit to the amount of data that can be sent and stored on a _Channel_. As you can imagine, this could get out of hand fairly quickly. Whenever possible, it is always a good idea to use _Channel Buffering_.

Let me show you an example:

```go
package main

import (
	"fmt"
)

func main() {
	chat := make(chan string, 5)

	chat <- "Hey!"
	chat <- "How's it going?"
	chat <- "Doing well"
	chat <- "I started watching Dark"
	chat <- "It's so good"
	chat <- "No spoilers please!"

	fmt.Println(<- chat)
	fmt.Println(<- chat)
	fmt.Println(<- chat)
	fmt.Println(<- chat)
	fmt.Println(<- chat)
	fmt.Println(<- chat)

	// Hey!
	// How's it going?
	// Doing well
	// I started watching Dark
	// It's so good
}
```

This should right be a surpirse right? As you can see we have 5 messages sent to `chat` and have successfully used `fmt.Println()` to print out each entry. But what happens if we try to add another entry to `chat`?
