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
