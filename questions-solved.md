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
