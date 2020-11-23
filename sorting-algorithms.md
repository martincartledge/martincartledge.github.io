#### sorting algorithms

> the process of rearranging the items in a collection so that items are in some kind of order

- sorting is an incredibly common task, so it is good to know how it works
- there are many different ways to sort things, and different techniques have their own advantages and disadvantages

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
