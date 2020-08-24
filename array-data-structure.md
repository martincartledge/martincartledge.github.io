---
title: The Array Data Structure
date: "2020-08-26T22:40:32.169Z"
description: "Data Structures and Algorithms using JavaScript - Arrays"
---

This is the second post in my series _Data Structures and Algorithims using JavaScript_. Last week, I discussed [_Time Complexity, Space Complexity, and Big O Notation_](https://www.martincartledge.io/time-complexity-Space-complexity-and-big-o-notation/). This week I am going to talk about a very popular data structure that most programmers use on a daily basis, the _Array_. In this post, I will cover the Big O of common array actions (`push`, `delete`, etc) and we will also walk through the process of creating our very own _Array_ data structure! Let's get started.

## What is an Array?

> A collection of multiple values that can be stored using a single variable

- The length can not be fixed
- The types of values can not be fixed
- Can not use strings as an index to an element, must use an integer

> Note: using bracket notation (`[]`) will not set or retrieve an element from the array, instead it will set or retrieve a variable that is associated with that array's object property collection. You can read more about that [right here](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Data_structures#Properties)

## Static vs Dynamic Arrays

### Static

> Fixed in size

### Dynamic

> Copy and rebuild array in new location with more memory, expands as you add elements

## Common Array actions

### Push O(1)

> Appends a new value at the end of an array and returns the new lenth

- Relies on the `length` property to know where to insert new values
- If `length` does not exist or can not be converted to a number, `0` is used

```js
const jediCouncil = ["yoda", "mace windu", "plo koon", "ki-adi-mundi"]

jediCouncil.push("anakin")

console.log(jediCouncil)

// 'yoda', 'mace windu', 'plo koon', 'ki-adi-mundi', 'anakin'
```

### Pop O(1)

> Removes the last value in array and returns that value

- If you call on an empty `Array`, `pop` returns `undefined`

```js
const jediCouncil = ["yoda", "mace windu", "plo koon", "ki-adi-mundi", "anakin"]

jediCouncil.pop()

console.log(jediCouncil)

// 'yoda', 'mace windu', 'plo koon', 'ki-adi-mundi'
```

### Shift O(n)

> Removes the first value in array and returns that value

- Shifts the values and their indexes consecutively

```js
const jediCouncil = ["yoda", "mace windu", "plo koon", "ki-adi-mundi"]

jediCouncil.shift()

console.log(jediCouncil)

// 'mace windu', 'plo koon', 'ki-adi-mundi'
```

First, we use the `const` keyword to delclare a new variable with the identifier `jediCouncil`. The value assigned to `jediCouncil` is an array of values that are of type `string`.

> Note: I am noting the index position of each value, this will help illustrate what `shift` does under the hood later

```js
const jediCouncil = ["yoda", "mace windu", "plo koon", "ki-adi-mundi"]
//index: 0 //index: 1    //index: 2  //index: 3
```

Next, I call the `shift` method on our `jediCouncil` variable.

```js
jediCouncil.shift()
```

On the next line I use `console.log` to log the new value of `jediCouncil`. Notice how the index positions have changed. Why is that?

When `shift` is called on our `jediCouncil` array, the value `yoda` is removed. Since this value was in index position `0`, we have to iterate through the array and update each value's index position. This is why the `shift` method has a Big O of `O(n)`.

```js
console.log(jediCouncil)
// 'mace windu', 'plo koon', 'ki-adi-mundi'
// index: 0       index: 1     index: 2
```

Now we can see that `yoda` has been removed and all of the other values in `jediCouncil` have been _shifted_ over to `1` less index position.

### Splice O(n)

> A defintion goes here

```js
const jediCouncil = ["yoda", "mace windu", "plo koon", "ki-adi-mundi"]

jediCouncil.push("anakin")

console.log(jediCouncil)

// 'yoda', 'mace windu', 'plo koon', 'ki-adi-mundi', 'anakin'
```

### Insert O(n)

> A defintion goes here

```js
const jediCouncil = ["yoda", "mace windu", "plo koon", "ki-adi-mundi"]

jediCouncil.push("anakin")

console.log(jediCouncil)

// 'yoda', 'mace windu', 'plo koon', 'ki-adi-mundi', 'anakin'
```

### Delete O(n)

> A defintion goes here

```js
const jediCouncil = ["yoda", "mace windu", "plo koon", "ki-adi-mundi"]

jediCouncil.push("anakin")

console.log(jediCouncil)

// 'yoda', 'mace windu', 'plo koon', 'ki-adi-mundi', 'anakin'
```

## Classes

> A defintion goes here

### Context (this)

> What object are you inside of

```js
const obj = {
  a: function () {
    console.log(this)
  },
}
```

### Instantiation

> Make a copy of an object and reuse the code

```js
class Player {
  constructor(name, type) {
    this.name = name
    this.type = type
  }
  introduce() {
    console.log(`hi I am ${this.name}, I am a ${this.type}`)
  }
}
```

### super()

> How you get access to class you are extending

```js
class Wizard extends Player {
  constructor(name, type) {
    super(name, type)
  }
  play() {
    console.log(`I am a ${this.type}`)
  }
}

const wizard = new Wizard("martin", "jedi")

wizard.introduce()
```

## Let's Create an Array Data Structure

```js
class MyArray {
  constructor() {
    this.length = 0
    this.data = {}
  }

  get(index) {
    return this.data[index]
  }

  push(item) {
    this.data[this.length] = item
    this.length++
    return this.length
  }

  pop() {
    const lastItem = this.data[this.length - 1]
    delete this.data[this.length - 1]
    this.length--
    return lastItem
  }

  delete(index) {
    const item = this.data[index]
    this.shiftItems(index)
  }

  shiftItems(index) {
    for (let i = index; i < this.length; i++) {
      this.data[i] = this.data[i + 1]
    }
    delete this.data[this.length - 1]
    this.length--
  }
}

const newArray = new MyArray()
```

Talking about the contructor

```js
constructor() {
  this.length = 0;
  this.data = {};
}
```

Talking about the `get` method

```js
get(index) {
  return this.data[index];
}
```

Talking about the `push` method

```js
push(item) {
  this.data[this.length] = item;
  this.length++;
  return this.length;
}
```

Talking about the `pop` method

```js
pop() {
  const lastItem = this.data[this.length - 1];
  delete this.data[this.length-1];
  this.length--;
  return lastItem;
}
```

Talking about the `delete` method

```js
delete(index) {
  const item = this.data[index];
  this.shiftItems(index);
}
```

Talking about the `shiftItems` method

```js
shiftItems(index) {
  for (let i = index; i < this.length; i++) {
    this.data[i] = this.data[i+1]
  }
  delete this.data[this.length-1];
  this.length--;
}
```

## In Summary

### 🦹‍♂️

- Fast data lookups
- Fast when appending data in `Array` (`push`)
- Fast when removing last item in `Array` (`pop`)
- Ordered data

### 🧟‍♂️

- Slow when inserting items
- Slow when deleteing items
