#### searching algorithms

##### linear search

- look through every item in the collection, starting from the beginning
- used most commonly with _unsorted_ data
- time complexity of `O(n)`

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

- eliminate half of remaining elements at a time
- can only be used with _sorted_ data
- use _divide and conquer_ (split collection into pieces)
- time complexity of `O(log n)`

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

##### naive string search

- loop over longer string
- loop over shorter string
- if characters don't match, break out of inner loop
- if characters don't match keep going
- if you complete the inner loop and find a match increment count of matches
- return the count

```js
function naiveSearch(long, short) {
  let count = 0;
  for (let i = 0; i < long.length; i++) {
    for (let j = 0; j < short.length; j++) {
      if (short[j] !== long[i + j]) break;
      if (j === short.length - 1) count++;
    }
  }
  return count;
}

// naiveSearch('lorie loled', 'lol') // 1
// naiveSearch('wowomgzomg', 'omg') // 2
```
