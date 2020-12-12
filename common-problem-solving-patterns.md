---
title: Common Problem Solving Patterns for Technical Interviews
date: "2020-12-21T22:40:32.169Z"
description: "Interview Insights Pt 3 - Problem Solving Patterns"
---

In my last article, I shared my thoughts on [prepare for a software developer interview](https://www.martincartledge.io/prepare-for-software-developer-interview/). This week, I will share my thoughts on some common patterns you can use to solve problems in technical interviews.

## Frequency Counter

- uses objects or sets to collect values / frequencies of values
- this can avoid the need for nested loops `O(n^2)` operations with arrays / strings

### What is the "Frequency Counter" pattern?

### When should I use a Frequency Counter?

### What are some common problems you can solve using the Frequency Counter pattern?

```js
/*
write a function called same which accepts two arrays. te function should return true if every value in the array has it's corresponding value squared in the second array. the frequency of values must be the same.

  Expected outcome:

  same([1,2,3], [4, 1, 9]) // true
  same([1,2,3], [1, 9]) // false
  same([1,2,1], [4,4,1]) // false
  same([2,3,6,8, 8], [64, 36,4,9,64]) // true

*/

same([1, 2, 3], [4, 1, 9]); // true
same([1, 2, 3], [1, 9]); // false
same([1, 2, 1], [4, 4, 1]); // false

function same(firstArr, secondArr) {
  if (!firstArr || !secondArr) return false;
  if (firstArr.length !== secondArr.length) return false;

  const hash = {};
  for (value of firstArr) {
    hash[value * value] = (hash[value * value] || 0) + 1;
  }
  for (secondValue of secondArr) {
    if (hash[secondValue]) {
      hash[secondValue] -= 1;
    } else {
      return false;
    }
  }
  return true;
}

function anagram(str1, str2) {
  if (str1.length !== str2.length) return false;

  const firstHash = {};
  const secondHash = {};

  for (first of str1) {
    firstHash[first] = (firstHash[first] || 0) + 1;
  }

  for (second of str2) {
    secondHash[second] = (secondHash[second] || 0) + 1;
  }

  for (letter in firstHash) {
    if (!secondHash[letter]) return false;
  }
  return true;
}

// simplified

function anagram(str1, str2) {
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

## Multiple Pointers

- creating pointers or values that correspond to an index or position and move towards the beginning, end, or middle based on a certain condition
- very efficient for solving problems with minimal space complexity

### What is the "Multiple Pointers" pattern?

### When should I use a Multiple Pointers?

### What are some common problems you can solve using the Multiple Pointers pattern?

```js
/*
  write a function called sumZero which accepts a sorted array of integers
  the function should find the first pair where the sum is 0
  return an array that includes both values that sum to zero or undefined if a pair does not exist

  Expected outcome:

  sumZero([-3, -2, -1, 0, 1, 2, 3]); // [-3, 3]
  sumZero([-2, 0, 1, 3]); // undefined
  sumZero([1, 2, 3]); // undefined
*/

function sumZero(arr) {
  let left = 0;
  let right = arr.length - 1;

  while (left < right) {
    let sum = arr[left] + arr[right];
    if (sum === 0) {
      return [arr[left], arr[right]];
    } else if (sum > 0) {
      right--;
    } else {
      left++;
    }
  }
}
```

```js
function countUniqueValues(arr) {
  let unique = [];

  for (value of arr) {
    if (!unique.includes(value)) {
      unique.push(value);
    }
  }
  return unique.length;
}

function countUniqueValues(arr) {
  if (arr.length === 0) return 0;
  let i = 0;
  for (let j = 1; j < arr.length; j++) {
    if (arr[i] !== arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}

countUniqueValues([1, 1, 2, 2, 3, 4, 4, 4, 5, 7]);
```

## Sliding Window

- this pattern involves creating a window which can either be an array or number from one position to another
- depending on a certain condition, the window either increases or closes (and a new window is created)
- very useful for keeping track of a subset of data in an array/string, etc

### What is the "Sliding Window" pattern?

### When should I use a Sliding Window?

### What are some common problems you can solve using the Sliding Window pattern?

```js
/*
  write a function called maxSubarraySum which accepts an array of integers and a number called n
  the function should calculate the maximum sum of n consecutive elements in the array

  Expected outcome:

  maxSubarraySum([1,2,5,2,8,1,5], 2) // 10
  maxSubarraySum([1,2,5,2,8,1,5], 4) // 17
  maxSubarraySum([4,2,1,6], 1) // 6
  maxSubarraySum([4,2,1,6,2], 4) // 13
  maxSubarraySum([], 4) // null
*/
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

## Divide and Conquer

- this pattern involves dividing a data set into smaller chunks and then repeating a process with a subset of data
- this pattern can tremendously decrease time complexity

### What is the "Divide and Conquer" pattern?

### When should I use a Divide and Conquer?

### What are some common problems you can solve using the Divide and Conquer pattern?

```js
/*
  given a sorted array of integers, write a function called search, that accepts a value and
  returns the index where the value passed to the function is located
  if the value is not found, return -1

  Expected outcome:

  search([1,2,3,4,5,6], 4) // 3
  search([1,2,3,4,5,6], 6) // 5
  search([1,2,3,4,5,6], 11) // -1
*/
// O(n) solution - linear search
function search(arr, n) {
  for (let i = 0; i < array.length; i++) {
    if (arr[i] === n) {
      return i;
    }
  }
  return -1;
}
// log(n) - binary search
function search(arr, n) {
  let min = 0;
  let max = arr.length - 1;

  while (min <= max) {
    let middle = Math.floor((min + max) / 2);
    let currentElement = arr[middle];

    if (arr[middle] < n) {
      min = middle + 1;
    } else if (arr[middle] > n) {
      max = middle - 1;
    } else {
      return middle;
    }
  }
  return -1;
}
```

## In Summary
