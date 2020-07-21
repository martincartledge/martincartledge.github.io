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

