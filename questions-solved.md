### hash maps

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
