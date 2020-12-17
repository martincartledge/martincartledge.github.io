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
