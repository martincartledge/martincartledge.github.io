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
var fe = function() {
  console.log('fe')
}
```

```js
//function declaration
function fd() {
  console.log('fd')
}
```

```js
var favFood = "pizza"

var foodThoughts = function() {
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

foodThoughts = function() {
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
  console.log('cold')
}

// function declaration
function india() {
  console.log('warm')
}

// function invoication/call/execution
canada()
india()

function marry(p1, p2) {
  console.log(arguments)
  // { 0: 'martin', 1: 'kristin' }
  return `${p1} is married to ${p2}`
}

marry('martin', 'kristin')
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
  var isValid; // undefined local(variable) environment
}

function one() {
  var isValid = true // local(variable) environment
  two(); // new EC
}

var isValid = false;

one();

// two() -- undefined
// one() -- true
// global() -- false
```