#### problem solving approach

> algorithm: a process or set of steps to accomplish a certain task

how do you improve:

- devise a plan for solving problems
- master common problem solving patterns

##### understand the problem

- can I restate the problem in my own words?
- what are the inputs that go into the problem?
- what are the outputs that should come from the solution to the problem?
- can the outputs be determined from the inputs? do I have enough information o solve the problem?
- how should I label the important pieces of data that are a part of the problem?

`write a function which takes two numbers and returns their sum`

- can I restate the problem in my own words?
  - implement addition
- what are the inputs that go into the problem?
  - int?
  - floats?
  - what about string for large numbers?
- what are the outputs that should come from the solution to the problem?
  - int? float? string?
- can the outputs be determined from the inputs? do I have enough information o solve the problem?
- how should I label the important pieces of data that are a part of the problem?

##### explore concrete examples

- coming up with examples can help you understand the problem better
- provides sanity checks that your eventual solution works how it should
- user stories: given an input, what is the output?
- unit tests
- start with simple examples
- progress to more complex examples
- explore examples with empty inputs
- explore invalid input

`write a function which takes in a string and returns counts of each character in the string`

```js
charCount("aaaa"); // {a: 4}

charCount("hello"); // {h: 1, e: 1, l: 2, o: 1}

charCount("my phone number is 123145"); // what about spaces? numbers?

charCount("Hello hi"); // store upper case letters, what about spaces?

charCount(); // what do we return? {}? null? error?

charCount(""); // what do we return? {}? null? error?
```

##### break it down

> explicitly write out the steps you need to take, this forces you to think about the code before you write it and helps catch any lingering issues or misunderstandings about the problem

```js
function charCount(str) {
  // do something
  // return an object with keys that are lowercase alphanumeric values
}

function charCount(str) {
  // make object to return at end
  // loop over string, for each character
  // if char is a number/letter AND key in object add one to count
  // if char is number/letter AND IS not in object add it and set value to 1
  // if char is something else (space, period, etc) don't do anything
  // return object at end
}
```

##### solve / simplify

> solve the problem, if you can't solve a simpler problem

- find the core difficulty in what you're trying to do
- temporarily ignore that difficulty
- write a simplified solution

```js
function charCount(str) {
  // make object to return at end
  const result = {};
  // loop over string, for each character
  for (let i = 0; i < str.length; i++) {
    const char = str[i].toLowerCase();
    if (result[char] > 0) {
      // if char is a number/letter AND key in object add one to count
      result[char]++;
    } else {
      // if char is number/letter AND IS not in object add it and set value to 1
      result[char] = 1;
    }
    // if char is something else (space, period, etc) don't do anything
    // return object at end
    return result;
  }
}
```

##### look back and refactor

- can you check the result?
- can you derive the result differently?
- can you understand it at a glance?
- can you use the result or method for some other problem?
- can you improve the performance of your solution?
- can you think of other ways to refactor?
- how have other people solved this problem?

```js
function charCount(str) {
  const obj = {};
  for (let char of str) {
    char = str[i].toLowerCase();
    if (isAlphaNumeric(char)) {
      obj[char] = ++obj[char] || 1;
    }
    return obj;
  }
}

function isAlphaNumeric(char) {
  const code = char.charCodeAt(0);
  if (
    !(code > 47 && code < 58) && // numeric (0-9)
    !(code > 64 && code < 91) && // upper alpha (A-Z)
    !(code > 96 && code < 123) // lower alpha (a-z)
  ) {
    return false;
  }
  return true;
}
```
