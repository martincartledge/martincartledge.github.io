#### sorting algorithms

> the process of rearranging the items in a collection so that items are in some kind of order

- sorting is an incredibly common task, so it is good to know how it works
- there are many different ways to sort things, and different techniques have their own advantages and disadvantages

##### time / space complexity

- bubble sort
  - best: `O(n)`
  - average: `O(n^2)`
  - worst: `O(n^2)`
  - space complexity: `O(1)`
- insertion sort
  - best: `O(n)`
  - average: `O(n^2)`
  - worst: `O(n^2)`
  - space complexity: `O(1)`
- selection sort
  - best: `O(n^2)`
  - average: `O(n^2)`
  - worst: `O(n^2)`
  - space complexity: `O(1)`

##### built in javascript sorting

> using the built in `sort` method

- the built in method accepts an option comparator function
- you can use this comparator function to tell javascript how you want it to sort

```js
function numberCompare(num1, num2) {
  return num1 - num2;
}

numberCompare([6, 4, 15, 10]);

// [4,6,`0,`5]
```

##### bubble sort

> a sorting algorithm where the largest values bubble up to the top

```js
// optimized
function bubbleSort(arr) {
  for (let i = arr.length; i > 0; i--) {
    for (let j = 0; j < i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        let temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  return arr;
}

bubbleSort([2, 1, 7, 3]);

// [1, 2, 3, 7]

// optimized more (using `noSwaps` variable)
function bubbleSort(arr) {
  let noSwaps;
  for (let i = arr.length; i > 0; i--) {
    noSwaps = true;
    for (let j = 0; j < i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        let temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        noSwaps = false;
      }
    }
    if (noSwaps) break;
  }
  return arr;
}

bubbleSort([8, 1, 2, 3, 4, 5, 6, 7]);

// [1, 2, 3, 4, 5, 6, 7, 8]
```

##### selection sort

> similar to bubble sort, but instead of first placing large values into sorted position, it places small values into sorted position

```js
function selectionSort(arr) {
  for (let i = 0; i < arr.length; i++) {
    let lowest = i;
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[j] < arr[lowest]) {
        lowest = j;
      }
    }
    if (i !== lowest) {
      let temp = arr[i];
      arr[i] = arr[lowest];
      arr[lowest] = temp;
    }
  }
  return arr;
}

selectionSort([34, 22, 10, 19, 17]);
```

##### insertion sort

> builds up the sort by gradually creating a larger left half which is always sorted

```js
function insertionSort(arr) {
  var currentVal;
  for (var i = 1; i < arr.length; i++) {
    currentVal = arr[i];
    for (var j = i - 1; j >= 0 && arr[j] > currentVal; j--) {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = currentVal;
  }
  return arr;
}

insertionSort([2, 1, 9, 76, 4]);

// [1, 2, 4, 9, 76]
```

##### merge sort

> a combination of two things - merging and sorting

- exploits the fact that arrays of 0 or 1 elements are always sorted
- works by decomposing an array into smaller arrays of 0 or 1 elements, then building up a newly sorted array
- in order to implement merge sort, it's useful to first implement a function responsible for merging two sorted arrays
- given two arrays which are sorted, this helper function should create a new array which is also sorted, and consists of all the elements in the two input arrays
- this function should run in `O(n + m)` time and `O(n + m)` space and _should not_ modify the parameters passed to it

```js
// merging arrays
// create an empty array you will return
// take a look at the smallest values in each input array
// while there are still values we haven't looked at
// if the value in the first array is smaller than the value in the second array, push the value in the first array into our results and move on to the next value in the first array
// if the value in the first array is larger than the value in the second array, push the value in the second array into our results and move on to the next value in the second array
// once we exhaust one array, push all remaining values from the other array
function merge(one, two) {
  let results = [];

  let i = 0;
  let j = 0;

  while (i < one.length && j < two.length) {
    if (two[j] > one[i]) {
      results.push(two[i]);
      i++;
    } else {
      results.push(two[j]);
      j++;
    }
  }

  while (i < one.length) {
    results.push(one[i]);
    i++;
  }
  while (j < two.length) {
    results.push(two[j]);
    j++;
  }

  return results;
}
```

```js
// mergeSort pseudo code
// break up the array into halves until you have arrays that are empty or have one element
// once you have smaller sorted arrays, merge those arrays with other sorted arrays until are you back at the full length of the array
// once the arrays have been merged back together, return the merged (and sorted) array
function mergeSort(arr) {
  if (arr.length <= 1) return arr;
  let mid = Math.floor(arr.length / 2);
  let left = mergeSort(arr.slice(0, mid));
  let right = mergeSort(arr.slice(mid));
  return merge(left, right);
}

mergeSort([10, 24, 76, 73]);
```

##### quick sort

> works by selecting one element (called the pivot) and finding the index where the pivot should end up in the sorted array

- like merge sort, exploits the fact that arrays of 0 or 1 element are always sorted
- once the pivot is positioned appropriately, quick sort can be applied on either side of the pivot
- in order to implement merge sort, it's useful to first implement a function responsible arranging elements in an array on either side of a pivot
- given an array, this helper function should designate an elements as the pivot
- it should then rearrange elements in the array so that all values less than the pivot are moved to the left of the pivot, and all values greater than the pivot are moved to the right of the pivot
- the order of elements on either side of the pivot does not matter
- the helper should do this _in place_, that is, it should _not_ create a new array

picking a pivot

- the runtime of quick sort depends in part on how one selects the pivot
- ideally, the pivot should be chosen so that it's roughly the median value in the data set you are using
- for simplicity, we will always choose the pivot to be the first element

```js
// pivot helper
// when complete, the helper should return the index of the pivot
// it will help to accept three arguments: an array, a start index, and an end index (these default to 0 and the array length minus 1)
// grab the pivot from the start of the array
// store the current pivot index in a variable (this will keep track of where the pivot should end up)
// loop through the array from the start until the end
// if the pivot is greater than the current element, increment the pivot index variable and then swap the current element with the element at the pivot index
// swap the starting element (i.e. the pivot) with the pivot index
// return the pivot index

function pivot(arr, start = 0, end = arr.length + 1) {
  function swap(array, i, j) {
    let temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }

  let pivot = arr[start];

  let swapIndex = start;

  for (let i = start + 1; i < array.length; i++) {
    if (pivot > arr[i]) {
      swapIndex++;
      swap(arr, swapIndex, i);
    }
  }
  swap(arr, start, swapIndex);
  return swapIndex;
}

pivot([4, 8, 2, 1, 5, 7, 6, 3]);
// [4,8,2,1,5,7,6,3]
// [4,2,8,1,5,7,6,3]
// [4,2,1,8,5,7,6,3]
// [4,2,1,3,5,7,6,8]
// [3,2,1,4,5,7,6,8]
// 3
```

```js
// call the pivot helper on the array
// when the helper returns the updated pivot index, recursively call the pivot helper on the subarray to the left of that index, and the subarray to the right of that index
// your base case occurs when you consider a subarray with less than 2 elements
function quickSort(arr, left = 0, right = arr.length - 1) {
  if (left < right) {
    let pivotIndex = pivot(arr, left, right);
    // left
    quickSort(arr, left, pivotIndex - 1);
    // right
    quickSort(arr, pivotIndex + 1, right);
  }
  return arr;
}

quickSort([4, 6, 9, 1, 2, 5, 3]);
```
