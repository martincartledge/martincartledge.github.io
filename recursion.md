#### recursion

> a process (a function) that calls itself

commonly used in:

- JSON.parse / JSON.stringify
- document.getElementById and DOM traversal
- object traversal
- various complex data structures

##### the call stack

- there is a built in data structure that manages what happens when functions are invoked
- when a function is invoked it is placed it is _pushed_ on top of the call stack
- when the `return` keyword is seen or a function ends, the compiler will _pop_ the function off the stack

##### writing a recursive function

- invoke the same function with a different input until you reach your base case
- every recursive function needs two things:
  - base case
    - a condition when the recursion ends
  - different input

```js
function countDown(num) {
  if (num <= 0) {
    console.log("all done");
    return;
  }
  console.log(num);
  num--;
  countDown(num);
}

// countDown(3)
// print 3
// countDown(2)
// print 2
// countDown(1)
// print 1
// countDown(0)
// all done
```

```js
function sumRange(num) {
  if (num === 1) return 1;
  return num + sumRange(num - 1);
}

// sumRange(3) // returns 6
// return 3 + sumRange(2) (returns 3)
// return 2 + sumRange(1) (returns 1)
// return 1
```

##### factorial iteratively

```js
function factorial(num) {
  let total = 1;
  for (let i = 0; i > 1; i--) {
    total *= i;
  }
  return total;
}
```

##### factorial recursively

```js
function factorial(num) {
  if (num === 1) return 1;
  return num * factorial(num - 1);
}
```

##### common recursion pitfalls

- no base case
- forgetting to return or returning the wrong thing
- stack overflow

##### helper method recursion

```js
function collectOdds(arr) {
  let result = [];

  function helper(helperInput) {
    if (helperInput.length === 0) return;

    if (helperInput[0] % 2 !== 0) {
      result.push(helperInput[0]);
    }
    helper(helperInput.slice(1));
  }

  helper(arr);

  return result;
}
```

##### pure recursion

- for arrays use methods like _slice_, _the spread operator_, and _concat_ that make copies of arrays so you do not mutate them
- for strings use methods like _slice_, _substr_, or _substring_ to make copies
- for objects use methods like _Object.assign_ or _the spread operator_ to make copies

```js
function collectOdds(arr) {
  let newArr = [];

  if (arr.length === 0) return newArr;

  if (arr[0] % 2 !== 0) {
    newArr.push(arr[0]);
  }

  newArr = newArr.concat(collectOdds(arr.slice(1)));

  return newArr;
}
// collectOdds([1,2,3,4,5])
// [1].concat(collectOdds([2,3,4,5]))
//// [].concat(collectOdds([3,4,5]))
////// [3].concat(collectOdds(4,5))
//////// [].concat(collectOdds([5]))
////////// [5].concat(collectOdds([]))
//////////// []
```
