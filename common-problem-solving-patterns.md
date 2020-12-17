---
title: Common Problem Solving Patterns for Technical Interviews
date: "2020-12-21T22:40:32.169Z"
description: "Interview Insights Pt 3 - Problem Solving Patterns"
---

In my last article, I shared my thoughts on [prepare for a software developer interview](https://www.martincartledge.io/prepare-for-software-developer-interview/). This week, I will share my thoughts on some common patterns you can use to solve problems in technical interviews.

## Frequency Counter

### What is the "Frequency Counter" pattern?

The Frequency Counter pattern uses an object or set to collect values and the frequency of those values.

This pattern is often used with an `array` or a `string`, and allows you to avoid nested loops (quadratic time complexity (`O(n^2)`)).

### When should I use the Frequency Counter pattern?

The Frequency Counter pattern is most helpful when you have multiple pieces of data that you want to compare with one another. Let me walk you through an example to see the Frequency Counter in action.

The problem we are trying to solve:

- write a function called `same` which accepts two arrays
- the function should return `true` if _every_ value in the first array has it's corresponding value squared in the second array
- the frequency of the values must be the same

After our function is written, we should expect our `same` function to return these values.

```js
same([1, 2, 3], [4, 1, 9]); // true
```

```js
same([1, 2, 3], [1, 9]); // false
```

```js
same([1, 2, 1], [4, 4, 1]); // false
```

```js
same([2, 3, 6, 8, 8], [64, 36, 4, 9, 64]); // true
```

First, using the `function` keyword, we create a function with the identifier `same`

```js
function same() {
```

Our function `same` needs two parameters, a first array and a second array.

```js
function same(firstArr, secondArr) {
```

Inside of our function block, we want to address a few edge cases. First, we need to check that both parameters have truthy values i.e. _not_ `null`, `undefined`, etc. We can check for a falsy value by using the `!` operator. If `firstArr` or `secondArr` is falsy, we return `false`;

```js
function same(firstArr, secondArr) {
  if (!firstArr || !secondArr) return false;
```

The next edge case we want to account for is to ensure that the length of both arrays are the same. If they are different, we know that they can _not_ contain an equal amount of shared values.

By checking the `length` property on both parameters, we can determine if they are the same. If they are not, we return `false`

```js
function same(firstArr, secondArr) {
  if (!firstArr || !secondArr) return false;
  if (firstArr.length !== secondArr.length) return false;
```

We need to keep track of all values in at least one of the arrays. To do this, and to avoid a nested loop, we can store these values in a hash table (object). I'll call mine `lookup`.

```js
function same(firstArr, secondArr) {
  if (!firstArr || !secondArr) return false;
  if (firstArr.length !== secondArr.length) return false;

  const lookup = {};
```

Using a `for of` loop, we iterate through the `firstArr`. Inside of the `for of` block, we assign the key to the result of `value * value`.

The value in this key/value pair will be a _frequency counter_ that reflects how many times a specific value is "seen" in the `firstArr`.

First, we check if `lookup` contains an entry for `value * value`, if it does, we add `1` to it. If it does not, we assign the value to `0` and then add `1`.

```js
function same(firstArr, secondArr) {
  if (!firstArr || !secondArr) return false;
  if (firstArr.length !== secondArr.length) return false;

  const lookup = {};

  for (value of firstArr) {
    lookup[value * value] = (lookup[value * value] || 0) + 1;
  }
```

Now that we have iterated through all of the values in the `firstArr` and stored them as their respective _squared_ value, we want to compare those values to the values in the `secondArr`.

We start by creating another `for of` loop. On the first line inside of our new `for of` block, we write an `if` condition statement to check if the current value from our `secondArr` is contained inside of our `lookup`.

If the value from the `secondArr` is also in our `lookup`, we want to decrement the value of that entry. We can do so by using the `-=` assignment operator.

If, at any point, we _do not_ find a match, we return `false`;

If we finish iterating through the `secondArr` without returning `false`, that means that our `firstArr` contains all values that are in a squared state in the `secondArr`; therefore, we return `true` outside of `for of` loop.

```js
function same(firstArr, secondArr) {
  if (!firstArr || !secondArr) return false;
  if (firstArr.length !== secondArr.length) return false;

  const lookup = {};
  for (value of firstArr) {
    lookup[value * value] = (lookup[value * value] || 0) + 1;
  }
  for (secondValue of secondArr) {
    if (lookup[secondValue]) {
      lookup[secondValue] -= 1;
    } else {
      return false;
    }
  }
  return true;
}
```

Let me show you another example, this one is used very commonly in coding assessments, so you might've seen this problem before.

The problem we are trying to solve:

- write a function called `isAnagram` which accepts two strings
- the function should return `true` if the two strings parameters are anagrams of each other

After our function is written, we should expect our `anagram` function to return these values.

```js
isAnagram("silent", "listen"); // true
```

```js
isAnagram("martin", "nitram"); // true
```

```js
isAnagram("cat", "tag"); // false
```

```js
isAnagram("rat", "tar"); // true
```

First, using the `function` keyword, we create a function with the identifier `isAnagram`

```js
function isAnagram() {
```

Our function `isAnagram` needs two parameters, a first `string` and a second `string`.

```js
function isAnagram(firstStr, secondStr) {
```

On the first few lines of our function block, we want to address a few edge cases, just like in the first example. Similar to `same`, we need to check that both parameters have truthy values i.e. _not_ `null`, `undefined`, etc. We can check for a falsy value by using the `!` operator. If `firstStr` or `secondStr` is falsy, we return `false`

```js
function same(firstStr, secondStr) {
  if (!firstStr || !secondStr) return false;
```

The next edge case we want to account for is to ensure that the length of both arrays are the same. If they are different, we know that they can _not_ contain an equal amount of shared values.

By checking the `length` property on both parameters, we can determine if they are the same. If they are not, we return `false`

```js
function same(firstStr, secondStr) {
  if (!firstStr || !secondStr) return false;
  if (firstStr.length !== secondStr.length) return false;
```

We need to keep track of all values in at least one of the arrays. To do this, and to avoid a nested loop, we can store these values in a hash table (object). I'll call mine `lookup`.

```js
function same(firstStr, secondStr) {
  if (!firstStr || !secondStr) return false;
  if (firstStr.length !== secondStr.length) return false;

  const lookup = {};
```

Using a `for of` loop, we iterate through the `firstStr`. Inside of the `for of` block, we assign the key to the result of `value * value`.

The value in this key/value pair will be a _frequency counter_ that reflects how many times a specific value is "seen" in the `firstStr`.

First, we check if `lookup` contains an entry for `value * value`, if it does, we add `1` to it. If it does not, we assign the value to `0` and then add `1`.

```js
function same(firstStr, secondStr) {
  if (!firstStr || !secondStr) return false;
  if (firstStr.length !== secondStr.length) return false;

  const lookup = {};

  for (value of firstStr) {
    lookup[value * value] = (lookup[value * value] || 0) + 1;
  }
```

Now that we have iterated through all of the values in the `firstStr` and stored their value, we want to compare those values to the values in the `secondStr`.

We start by creating another `for of` loop. On the first line inside of our new `for of` block, we write an `if` condition statement to check if the current value from our `secondStr` is contained inside of our `lookup`.

If the value from the `secondStr` is also in our `lookup`, we want to decrement the value of that entry. We can do so by using the `-=` assignment operator.

If, at any point, we _do not_ find a match, we return `false`;

If we finish iterating through the `secondStr` without returning `false`, that means that our `firstStr` contains all values that are in the `secondStr`; therefore, we return `true` outside of `for of` loop.

```js
function isAnagram(firstStr, secondStr) {
  if (!firstStr || !secondStr) return false;
  if (firstStr.length !== secondStr.length) return false;

  const lookup = {};

  for (first of firstStr) {
    lookup[first] = (lookup[first] || 0) + 1;
  }

  for (second of secondStr) {
    if (!lookup[second]) return false;

    hash[second] -= 1;
  }
  return true;
}
```

```js
// simplified

function isAnagram(str1, str2) {
  if (str1.length !== str2.length) return false;

  const hash = {};

  for (first of str1) {
    hash[first] ? (hash[first] += 1) : (hash[first] = 1);
  }

  for (second of str2) {
    if (!hash[second]) {
      return false;
    } else {
      hash[second] -= 1;
    }
  }
  return true;
}
```

## In Summary
