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

> Puts new value at the end of an array

```js
const jediCouncil = ["yoda", "mace windu", "plo koon", "ki-adi-mundi"]

jediCouncil.push("anakin")

console.log(jediCouncil)

// 'yoda', 'mace windu', 'plo koon', 'ki-adi-mundi', 'anakin'
```

### Pop O(1)

> Remove last item in array

```js
const jediCouncil = ["yoda", "mace windu", "plo koon", "ki-adi-mundi", "anakin"]

jediCouncil.pop()

console.log(jediCouncil)

// 'yoda', 'mace windu', 'plo koon', 'ki-adi-mundi'
```

### Unshift O(n)

> A defintion goes here

```js
const jediCouncil = ["yoda", "mace windu", "plo koon", "ki-adi-mundi"]

jediCouncil.unshift("anakin")

console.log(jediCouncil)

// 'yoda', 'mace windu', 'plo koon', 'ki-adi-mundi', 'anakin'
```

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
