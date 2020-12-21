#### hash tables

> used to store key-value pairs

- keys are not ordered
- fast for finding values, adding new values, and removing values

time complexity:

- insert `O(1)`
- deletion `O(1)`
- access `O(1)`

##### hash functions

> any function that can be used to map data of an arbitrary size

- fast (constant time `O(1)`)
- doesn't cluster outputs at specific indices, but distributes uniformly
- deterministic (same input yields same output)

```js
// hash function for strings
function hash(key, arrLength) {
  let total = 0;
  for (let char of key) {
    // map "a" to 1, "b" to 2, "c" to 3, etc.
    let value = char.charCodeAt(0) - 96;
    total = (total + value) % arrLength;
  }
  return total;
}
```

- prime numbers in a hash function is helpful in spreading out the keys more uniformly

```js
// hash function for strings using a prime number
function hash(key, arrLength) {
  let total = 0;
  let PRIME = 31;
  for (let i; i < Math.min(key.length, 100); i++) {
    let char = key[i];
    let value = char.charCodeAt(0) - 96;
    total = (total * PRIME + value) % arrLength;
  }
  return total;
}
```

#### dealing with collisions

methods to handle collisions:

- separate chaining
  - at each index in our array we store values using a more sophisticated data structure (array, linked list, etc)
- linear probing
  - when we find a collision, we search through the array to find the next empty slot

```js
// building a hash table class

class HashTable {
  constructor(size = 53) {
    this.keyMap = new Array(size);
  }

  _hash(key) {
    let total = 0;
    let PRIME = 31;
    for (let i; i < Math.min(key.length, 100); i++) {
      let char = key[i];
      let value = char.charCodeAt(0) - 96;
      total = (total * PRIME + value) % this.keyMap.length;
    }
    return total;
  }

  set(key, value) {
    const index = this._hash(key);
    if (!this.keyMap[index]) {
      this.keyMap[index] = [];
    }
    this.keyMap[index].push([key, value]);
    return this;
  }

  get(key) {
    const index = this._hash(key);
    if (this.keyMap[index]) {
      for (let i = 0; i < this.keyMap[index].length; i++) {
        if (this.keyMap[index][i][0] === key) {
          return this.keyMap[index][i][1];
        }
      }
    }
    return undefined;
  }

  keys() {
    let result = [];
    for (let i = 0; i < this.keyMap.length; i++) {
      if (this.keyMap[i]) {
        for (let j = 0; j < this.keyMap[i].length; j++) {
          if (!result.includes(this.keyMap[i][j][0])) {
            result.push(this.keyMap[i][j][0]);
          }
        }
      }
      return result;
    }
  }

  values() {
    let result = [];
    for (let i = 0; i < this.keyMap.length; i++) {
      if (this.keyMap[i]) {
        for (let j = 0; j < this.keyMap[i].length; j++) {
          if (!result.includes(this.keyMap[i][j][1])) {
            result.push(this.keyMap[i][j][1]);
          }
        }
      }
      return result;
    }
  }
}
```
