### frequency counter pattern

#### sameFrequency

- write a function called `sameFrequency`
- given two positive integers, find out if the two numbers have the same frequency of digits
- solution must have an time complexity of `O(n)`

```js
function sameFrequency(one, two) {
  if (!one || !two) return false;

  const oneArr = one.toString().split("");
  const twoArr = two.toString().split("");

  if (oneArr.length !== twoArr.length) return false;

  const hash = {};

  for (let value of oneArr) {
    if (hash[value]) {
      hash[value] += 1;
    } else {
      hash[value] = 1;
    }
  }

  for (let value of twoArr) {
    if (!hash[value]) {
      return false;
    } else {
      hash[value] = hash[value] -= 1;
    }
  }
  return true;
}

// sameFrequency(123, 312) // true
// sameFrequency(34, 14) // false
// sameFrequency(3589578, 5879385) // true
```

#### areThereDuplicates

- write a function called `areThereDuplicates`
- accepts a _variable number of arguments_
- checks whether there are any duplicates among arguments passed in
- solution must have a time and space complexity of `O(n)`

```js
function areThereDuplicates(...args) {
  const arr = [...args];
  const hash = {};

  for (let value of arr) {
    if (hash[value]) return true;
    hash[value] = (hash[value] += 1) || 1;
  }
  return false;
}

// areThereDuplicates(1,2,3) // false

// areThereDuplicates(1,2,2) // true

// areThereDuplicates('a','b','c','a') // true
```

### multiple pointers pattern

##### averagePair

- write a function called `averagePair`
- given a sorted array of integers and a target average, determine if there is a pair of values in the array where the average of the pair equals the target average
- solution must have a time complexity of `O(n)`

```js
function averagePair(sortedArr, target) {
  // if there is not at least two values, we can not take average
  if (sortedArr.length <= 1) return false;

  let left = 0;
  let right = sortedArr.length - 1;

  while (left < right) {
    let sum = (sortedArr[left] + sortedArr[right]) / 2;
    if (sum === target) {
      return true;
    } else if (sum > target) {
      right--;
    } else {
      left++;
    }
  }

  return false;
}

// averagePair([1,2,3], 2.5); // true

// averagePair([1,2,3], 5); // false

// averagePair([1,3,3,5,6,7,10,12,19], 8); // true

// averagePair([-1, 0, 3,4,5,6], 4.1); // false

// averagePair([], 5); // false
```

##### isSubSequence

- write a function called `isSubsequence`
- takes two strings and checks whether the characters in the first string form a subsequence of the characters in the second string
- solution must have a time complexity of `O(n)`
- solution must have a space complexity of `O(1)`

```js
function isSubsequence(firstStr, secondStr) {
  const firstArr = firstStr.split("");
  const secondArr = secondStr.split("");
  if (firstArr.length === 0 || secondArr.length === 0) return false;

  let firstIndex = 0;

  let secondIndex = 0;

  const secondArrLength = secondArr.length;

  const matchAmount = firstArr.length;

  let counter = 0;

  while (secondIndex <= secondArrLength) {
    if (counter === matchAmount) {
      return true;
    } else if (firstArr[firstIndex] === secondArr[secondIndex]) {
      counter++;
      firstIndex++;
      secondIndex++;
    } else if (firstArr[firstIndex] !== secondArr[secondIndex]) {
      secondIndex++;
    }
  }
  return false;
}
```

### recursion

##### power

- write a function called `power` which accepts a base and an exponent
- the function should return the power of the base to the exponent

```js
function power(base, exponent) {
  if (exponent === 0) return 1;
  if (exponent === 1) return base;
  exponent--;
  return power(base * 2, exponent);
}

// power(2,0) // 1
// power(2,2) // 4
// power(2,4) // 16
```

##### factorial

- write a function called `factorial` which accepts a number and returns the factorial of that number
- a factorial is the product of an integer and all integers below it

```js
function factorial(num) {
  if (num === 0) return 1;
  return num * factorial(num - 1);
}

//factorial(1) // 1
// factorial(2) // 2
// factorial(4) // 24
// factorial(7) // 5040
```

##### productOfArray

- write a function called `productOfArray` which takes in an array of numbers and returns the product of them all

```js
function productOfArray(arr) {
  if (arr.length === 0) return;
  if (arr.length === 1) return arr[0];

  let sumResult = arr[0];

  function add(helperList) {
    if (helperList.length === 0) return;
    sumResult *= helperList[0];
    return add(helperList.slice(1));
  }

  add(arr);

  return sumResult;
}

// productOfArray([1,2,3]) // 6
// productOfArray([1,2,3,10]) // 60
```

### searching algorithms

##### linear search

- write a function called `linearSearch` which takes in an array and a value
- return the index at which the value exists, if the value does not exist return `-1`

```js
function linearSearch(arr, val) {
  if (arr.length === 0) return -1;
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === val) return i;
  }
  return -1;
}
```

##### binary search

- write a function called `binarySearch` which takes in a sorted array and a value
- return the index at which the value exists, if the value does not exist return `-1`

```js
function binarySearch(arr, val) {
  let start = 0;
  let end = arr.length - 1;
  let middle = Math.round((start + end) / 2);

  while (arr[middle] !== val && start <= end) {
    if (val < arr[middle]) end = middle - 1;
    else start = middle + 1;
    middle = Math.round((start + end) / 2);
  }
  return arr[middle] === val ? middle : -1;
}

// binarySearch([1,2,3,4,5,6,7,8,9,10,11,12,13, 14, 15,16,17,18,19,20], 19) // 18
// binarySearch([1,2,3,4,5], 7) // -1
// binarySearch([1,2,3,4,5], 2) // 1
// binarySearch([1,2,3,4,5], 3) // 2
// binarySearch([5,6,10,13,14,18,30,35,37,40,44,64,79,84,86,95,96,98,99], 10) // 2
```

##### sliding window

- Given an array of integers and a number, write a function called `maxSubarraySum`, which finds the maximum sum of a subarray with the length of the number passed to the function.

```js
function maxSubarraySum(arr, count) {
  if (arr.length < count) return null;

  let currMax = 0;

  for (let i = 0; i < count; i++) {
    currMax += arr[i];
  }

  let maxSoFar = currMax;

  for (let j = count; j < arr.length; j++) {
    currMax += arr[j] - arr[j - count];
    maxSoFar = Math.max(currMax, maxSoFar);
  }

  return maxSoFar;
}

//   maxSubarraySum([1,2,5,2,8,1,5], 2) // 10
//   maxSubarraySum([1,2,5,2,8,1,5], 4) // 17
//   maxSubarraySum([4,2,1,6], 1) // 6
//   maxSubarraySum([4,2,1,6,2], 4) // 13
//   maxSubarraySum([], 4) // null
```
