# Advanced JS

### execution context

- broke down into two phases: creation phase and execution phase
- each function has a new execution context (function execution context)
- global execution context:
  - global object
  - this keyword

### lexical environment

- at compile time - where is the code written
- available data / variables where the function was defined determines our available variables

### hoisting

- behavior of moving variables / function declarations
- creation phase: allocating memory for variables and function declarations
- will only hoist when `function` or `var` keywords are used
- function declarations are fully hoisted
- variables are partially hoisted (identifer only)

```js
// function expression
var fe = function () {
  console.log("fe")
}
```

```js
//function declaration
function fd() {
  console.log("fd")
}
```

```js
var favFood = "pizza"

var foodThoughts = function () {
  console.log(favFood)

  favFood = "burgers"

  console.log(favFood)
}

foodThoughts()
```

// hoisting - creation phase

```js
var favFood = undefined
var foodThoughts = undefined

foodThoughts = function () {
  console.log(favFood)
  // undefined

  favFood = "burgers"

  console.log(favFood)
  // burgers
}

foodThoughts()
```

### function invocation

```js
// function expression
var canada = () => {
  console.log("cold")
}

// function declaration
function india() {
  console.log("warm")
}

// function invoication/call/execution
canada()
india()

function marry(p1, p2) {
  console.log(arguments)
  // { 0: 'martin', 1: 'kristin' }
  return `${p1} is married to ${p2}`
}

marry("martin", "kristin")
// martin is married to kristin
```

### arguments keyword

```js
function marry(...args) {
  console.log(arguments)
  // { 0: 'martin', 1: 'kristin' }
  console.log(Array.from(arguments))
  // ['martin', 'kristin']
  return `${args[0]]} is married to ${args[1]}`
}

marry('martin', 'kristin')
// martin is married to kristin
```

### variable environment

- each execution context has its own variable environment

```js
function two() {
  var isValid // undefined local(variable) environment
}

function one() {
  var isValid = true // local(variable) environment
  two() // new EC
}

var isValid = false

one()

// two() -- undefined
// one() -- true
// global() -- false
```

### scope chain

- global scope is outermost scope

```js
function sayMyName() {
  var a = "a"
  return function findName() {
    var b = "b"
    return function printName() {
      var c = "c"
      return "martin"
    }
  }
}

sayMyName()()()
```

```js
function weird() {
  height = 50
  return height
}

weird()

var hey = function doodle() {
  return "hey"
}

hey()
// hey

doodle()
// reference error, undefined
```

### function scope

```js
function a() {
  var secret = "12345"
}

secret
// not defined
```

### block scope

```js
if (5 > 4) {
  const secret = "12345"
}

secret
// not defined
```

### IIFE Immediately Invoked Function Expression

(function() {

})()

### `this` Keyword

this is the object that the function is a propety of

- gives methods access to their object
- execute same code for multiple objects
- dynamically scoped (where it is called)

```js
const obj = {
  name: "martin",
  sing() {
    return "lalala" + this.name
  },
  singAgain() {
    return this.sing() + "!"
  },
}
```

```js
function importantPerson() {
  console.log(this.name)
}

const name = "martin"

const obj1 = {
  name: "kristin",
  importantPerson: importantPerson,
}

const obj2 = {
  name: "nikita",
  importantPerson: importantPerson,
}

importantPerson()
// martin

obj1.importantPerson()
// kristin

obj2.importantPerson()
// nikita
```

```js
const obj = {
  name: "kristin",
  a() {
    console.log("a", this)
    // {name: kristin, a: F}
    var b = function () {
      console.log("b", this)
      // global execution context
    }
  },
}
```

es6 - lexically scoped

```js
const obj = {
  name: "kristin",
  a() {
    console.log("a", this)
    // {name: kristin, a: F}
    var b = () => {
      console.log("b", this)
      // {name: kristin, a: F}
    }
  },
}
```

### call()

- useful for borrowing methods

```js
function a() {
  console.log("hi")
}

a.call()
// hi
```

```js
const wizard = {
  name: "martin",
  health: 100,
  heal(num1, num2) {
    this.health += num1 + num2
  },
}

const archer = {
  name: "kristin",
  health: 30,
}

wizard.heal.call(archer, 50, 30)
```

### apply()

- take an array of params
- useful for borrowing methods

```js
const wizard = {
  name: "martin",
  health: 100,
  heal(num1, num2) {
    this.health += num1 + num2
  },
}

const archer = {
  name: "kristin",
  health: 30,
}

wizard.heal.apply(archer, [50, 30])
```

### bind()

- returns a new function with certain context and params
- allows us to store this keyword for later use

```js
const wizard = {
  name: "martin",
  health: 100,
  heal(num1, num2) {
    this.health += num1 + num2
  },
}

const archer = {
  name: "kristin",
  health: 30,
}

const healArcher = wizard.heal.bind(archer, 50, 30)

healArcher()
```

### function currying

```js
function multiply(a, b) {
  return a * b
}

let multiplyByTwo = multiply.bind(this, 2)

multiplyByTwo(4)
// 8
```

### Context vs Scope

// Scope - function based
// Context - how a function is invoked
