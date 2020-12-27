---
title: Problem Solving Patterns for Technical Interviews - the Sliding Window Pattern Explained
date: "2021-01-04T22:40:32.169Z"
description: "Interview Insights Pt 4 - Problem Solving Patterns - Sliding Window"
---

In my last article, I shared my thoughts on [solving technical interview questions using the Frequency Counter pattern](https://www.martincartledge.io/solve-technical-interview-questions-using-frequency-counter/).

In this article, I am going to switch gears a bit and talk about common patterns you can use to solve problems in technical interviews. We'll discuss the _Sliding Window_ pattern in depth to help you tackle it effectively.

### What is the "Sliding Window" pattern?

- this pattern involves creating a window which can either be an array or number from one position to another
- depending on a certain condition, the window either increases or closes (and a new window is created)

```js
/*
  write a function called maxSubarraySum which accepts an array of integers and a number called n
  the function should calculate the maximum sum of n consecutive elements in the array
*/
```

### When should I use the Sliding Window pattern?

- very useful for keeping track of a subset of data in an array/string, etc

#### The "maxSubarraySum" exercise

- Write a function called `maxSubarraySum` which accepts an array (`arr`) and a single integer (`n`)
- The function should calculate the maximum sum of `n` consecutive elements in the array (`arr`)

#### What is the optimal outcome?

After our function is written, we should expect our `maxSubarraySum` function to return these values.

```js
maxSubarraySum([1, 2, 5, 2, 8, 1, 5], 2); // 10
```

```js
maxSubarraySum([1, 2, 5, 2, 8, 1, 5], 4); // 17
```

```js
maxSubarraySum([4, 2, 1, 6], 1); // 6
```

```js
maxSubarraySum([4, 2, 1, 6, 2], 4); // 13
```

```js
maxSubarraySum([], 4); // null
```

#### Getting started

First, using the `function` keyword, we create a function with the identifier `maxSubarraySum`:

```js
function maxSubarraySum() {
```

Our function `maxSubarraySum` needs two parameters, a first array and a single integer. In this example, we are passing these values `[1, 2, 3]` and `2`.

```js
function maxSubarraySum(arr, num) {
```

#### Wrapping up our "maxSubarraySum" function

```js
function maxSubarraySum(arr, num) {
  let maxSum = 0;
  let tempSum = 0;
  if (arr.length < num) return null;
  for (let i = 0; i < num; i++) {
    maxSum += arr[i];
  }
  tempSum = maxSum;
  for (let i = num; i < array.length; i++) {
    tempSum = tempSum -= arr[i - num] + arr[i];
    maxSum = Math.max(maxSum, tempSum);
  }
  return maxSum;
}
```

## In Summary

I hope this in-depth overview of the Sliding Window pattern was helpful. Now that you know how the pattern works, I am confident that you will be able to impress your interviewer by showcasing your skills at an even higher level.

In my next article, I will be discussing another common problem-solving pattern called the Multiple Pointer pattern. Thanks for reading, and happy interviewing!
