---
title: What is Big O Notation?
date: "2020-08-19T22:40:32.169Z"
description: "Data Structures & Algorithims"
---

## What is Big O Notation?

> the language we use for talking about how long it takes for an algorithm to run
> 
What is good code?

- readable
- scalable

## O(n) Linear Time

> depends on the number of inputs

```js
const large = new Array(10000).fill('nemo')

function findNemo(array) {
  for (let i = 0; i < array.length; i++) {
    if (array[i] === 'nemo') {
      console.log('found nemo');
    }
  }
}

findNemo(large)
```


## O(1) Constant Time

```js
const boxes = [0,1,2,3,4,5]

function logTwoBoxes(boxes) {
  console.log(boxes[0]) // O(1)
  console.log(boxes[1]) // O(1)
}

logTwoBoxes(boxes) // O(2)
```

## O(n²) Quadratic Time

```js

```


## Simplifying Big O

- Always assume worst-case scenario 
- Remove constants
- Different terms for inputs
- Drop non-dominants

### Remove constants

```js
function iterate(items) {
  items.forEach((item) => {
    console.log(item)
  }
  // O(n)

  items.forEach((item) => {
    console.log(item)
  }
  // O(n)
}

// O(n) + O(n) = O(2n)
```


```js

function carBuilder(pieces) {
  let totalPieces = 0; // O(1)
  // add tires
  totalPieces = 4; // O(1)

  for (let i = 0; i < pieces.length; i++) { // O(n)
    fillUpGas(); // O(n)
    const fast = true; // O(n)
    totalPieces++; // O(n)
  }
  return totalPieces; // O(1)
}

BIG O(3 + 4n) -> simplified -> O(n)
```

### Different terms for inputs

```js
function printTwoLists(listOne, listTwo) {
  listOne.forEach(firstListItem => console.log(firstListItem))
  
  listTwo.forEach(secondListItem => console.log(secondListItem))
}

// O(a + b)
```