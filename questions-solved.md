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
