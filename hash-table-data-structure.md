---
title: The Hash Table Data Structure
date: "2020-09-02T22:40:32.169Z"
description: "Data Structures and Algorithms using JavaScript - Hash Tables"
---

This is the third post in my series _Data Structures and Algorithms using JavaScript_. Last week, I discussed [_The Array Data Structure_](https://www.martincartledge.io/array-data-structure/). This week I am going to talk about another popular data structure, the _Hash Table_. Much like in my previous post, I will cover the Big O of common `Hash Table` actions (`insert`, `lookup`, `delete`, `search`). We will also create our own _Hash Table_ data structure! Let's get to it.

## What is a Hash Table?

> A defintion of a hash Table

- some notes about hash tables
- some notes about hash tables
- some notes about hash tables

## Common Hash Table Actions

### Insert O(1)

> A definition of Insert

```js
```

### Lookup O(1)

> A definition of Lookup

```js
```

### Delete O(1)

> A definition of Delete

```js
```

### Search O(1)

> A definition of Search

```js
```

## Hash Collision

> A definition of Hash Collision

```js
```

## Let's Create a Hash Table Data Structure

```js
class HashTable {
  constructor(size){
    this.data = new Array(size);
  }

  _hash(key) {
    let hash = 0;
    for (let i =0; i < key.length; i++){
        hash = (hash + key.charCodeAt(i) * i) % this.data.length
    }
    return hash;
  }

  get(key) {
    let address = this._hash(key);
    const currentBucket = this.data[address];
    if (currentBucket) {
      for(let i = 0; i < currentBucket.length; i++) {
        if (currentBucket[i][0] === key) {
          return currentBucket[i][1]
        }
      }
    } 
		// O(n)
    return undefined
  }

  set(key, value) {
    let address = this._hash(key)
    if (!this.data[address]) {
      this.data[address] = [];
    }
    this.data[address].push([key, value]);
		// O(1)
    return this.data
  }
}

const myHashTable = new HashTable(50);
myHashTable.set('grapes', 10000)
// myHashTable.get('grapes')
// myHashTable.set('apples', 9)
// myHashTable.get('apples')
```