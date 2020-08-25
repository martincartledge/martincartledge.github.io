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

First, we use the `const` keyword to create a new variable with the identifier `jediCouncil`. The value assigned to `jediCouncil` is an `Array` of values that are of type `string`.

```js
const jediCouncil = ["yoda", "mace windu", "plo koon", "ki-adi-mundi"]
```

Next, we call the `push` method on the `jediCouncil` `Array` with a single argument `anakin`.

```js
jediCouncil.push("anakin")
```

When we log our `jediCouncil` on the next line, we see that the value `anakin` is now the last value in our `jediCouncil` `Array`.

```js
console.log(jediCouncil)
// 'yoda', 'mace windu', 'plo koon', 'ki-adi-mundi', 'anakin'
```

### Pop O(1)

> Removes the last value in array and returns that value

- If you call on an empty `Array`, `pop` returns `undefined`

For this example, we want `anakin` out of the `jediCouncil`, we can use the `pop` method for that:

```js
const jediCouncil = ["yoda", "mace windu", "plo koon", "ki-adi-mundi", "anakin"]

jediCouncil.pop()

console.log(jediCouncil)

// 'yoda', 'mace windu', 'plo koon', 'ki-adi-mundi'
```

First, we use the `const` keyword to create a new variable with the identifier `jediCouncil`. The value assigned to `jediCouncil` is an `Array` of values that are of type `string`.

```js
const jediCouncil = ["yoda", "mace windu", "plo koon", "ki-adi-mundi", "anakin"]
```

Next, we call the `pop` method on the `jediCouncil` `Array`, we do not need an argument when calling this method.

```js
jediCouncil.pop()
```

Now, when we log our `jediCouncil` on the next line, we should see that the value `anakin` is no longer in our `jediCouncil` `Array`

```js
console.log(jediCouncil)
// 'yoda', 'mace windu', 'plo koon', 'ki-adi-mundi'
```

Later, `anakin` 👋🏻

Using `pop` makes removing the last item from your `Array` very quick and painless.

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

> Remove, replace, or add new values to an array

```js
const jediCouncil = ["yoda", "mace windu", "plo koon", "ki-adi-mundi"]

jediCouncil.splice(4, 0, "obi wan")

console.log(jediCouncil)

// 'yoda', 'mace windu', 'plo koon', 'ki-adi-mundi', 'obi wan'
```

First, we use the `const` keyword to create a new variable with the identifier `jediCouncil`. The value assigned to `jediCouncil` is an `Array` of values that are of type `string`.

```js
const jediCouncil = ["yoda", "mace windu", "plo koon", "ki-adi-mundi"]
```

Next, we call the `splice` method on the `jediCouncil` `Array`.

> Note: the `splice` method takes 3 arguments:
> `start` - this is the index you would like to start changing the array
> `deleteCount` - this is the number of values you would like to remove from the array (starting from the `start` argument)
> `items` - this is the values you would like to add to the array, starting from the `start` argument
> If the `items` argument is empty, the `spice` method will only remove items

We pass 3 arguments to `splice`:

- `5`: we want to start changing the `jediCouncil` array at index position `5`
- `0`: we do not want to delete anything from `jediCouncil`; therefore, this value is `0`
- `"obi wan"`: this is the value we would like to add to index position `5`

```js
jediCouncil.splice(5, 0, "obi wan")
```

When we log our `jediCouncil` on the next line, we can see that `obi wan` has been added to `jediCouncil` in index position `5`; which, in this case, is the last position.

```js
console.log(jediCouncil)
// 'yoda', 'mace windu', 'plo koon', 'ki-adi-mundi', 'obi wan'
```

Welcome aboard, `obi wan` 👍🏻, I think you will fit in nicely

Although we did not `shift` any values or their index positions, we always take the worst case when determining Big O; therefore, the Big O of `splice` is `O(n)`

## Let's Create an Array Data Structure

This section assumes you have some knowledge of how classes work for JavaScript. If classes are new for you, fear not! I will be writing a post on those in the near future. In the meantime, you can read more about them [right here](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes).

We know how the core pieces of an `Array` work, so let's build our own `Array` data structure!

```js
class MyOwnArray {
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

const myOwnArray = new MyOwnArray()
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
