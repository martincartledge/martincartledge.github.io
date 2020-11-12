#### problem solving patterns

##### frequency counter pattern

- uses objects or sets to collect values / frequencies of values
- this can avoid the need for nested loops `O(n^2)` operations with arrays / strings

```js
write a function called same which accepts two arrays. te function should return true if every value in the array has it's corresponding value squared in the second array. the frequency of values must be the same.

same([1,2,3], [4, 1, 9]) // true
same([1,2,3], [1, 9]) // false
same([1,2,1], [4,4,1]) // false

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

// same([1,2,3], [4, 1, 9]) // true
// same([1,2,3], [1, 9]) // false
// same([1,2,1], [4,4,1]) // false
// same([2,3,6,8, 8], [64, 36,4,9,64]) // true
```

```js
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

// anagram('catd', 'tadc') // true

// anagram("car", "rat"); // false

// anagram("texttwisttime", "timetwisttext") // true
```

##### multiple pointers

- creating pointers or values that correspond to an index or position and move towards the beginning, end, or middle based on a certain condition
- very efficient for solving problems with minimal space complexity

```js
// write a function called sumZero which accepts a sorted array of integers
// the function should find the first pair where the sum is 0
// return an array that includes both values that sum to zero or undefined if a pair does not exist

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

// sumZero([-3, -2, -1, 0, 1, 2, 3]); // [-3, 3]
// sumZero([-2, 0, 1, 3]); // undefined
// sumZero([1, 2, 3]); // undefined
```

```js
/*
 WIP
*/
function countUniqueValues(arr) {
  let unique = [];

  for (value of arr) {
    if (!unique.includes(value)) {
      unique.push(value);
    }
  }
  return arr.length;
}
```
