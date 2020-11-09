### big o notation

a system of classifying code to determine which is best (fastest)

a numeric representation of the performance of our code

it's important to have a precise vocabulary to talk about how our code performs

useful for discussing trade-offs between different approaches

when your code slows down or crashes, identifying parts of the code that are inefficient cant help us find pain points in our applications

#### timing our code

using `for` loop

```js
function upToN(n) {
  let total = 0;
  for (let i = 1; i <= n; i++) {
    total += i;
  }
  return total;
}

let t1 = performance.now();

addUpTo(1000000000);

let t2 = performance.now();

console.log(`time elapsed: ${(t2 - t1) / 1000} seconds`);
```

using an expression

```js
function upToN(n) {
  return (n * (n + 1)) / 2;
}

let t1 = performance.now();

addUpTo(1000000000);

let t2 = performance.now();

console.log(`time elapsed: ${(t2 - t1) / 1000} seconds`);
```

##### what does better mean?

- faster?
- less memory-intensive?
- more readable?

##### the problem with time

- different machines will record different time
- the same machine will record different times
- for fast algorithms, speed measurements may not be precise enough

##### if not time, then what?

- count the number of operations the computer has to perform

##### counting operations

```js
function upToN(n) {
  return (n * (n + 1)) / 2;
}
```

Always 3 operations: `O(1)`

3 operations:

- multiplication
- addition
- division

```js
function upToN(n) {
  let total = 0;
  for (let i = 1; i <= n; i++) {
    total += i;
  }
  return total;
}
```

Number of inputs is bound by a multiple of `n`: `O(n)`

`total`

- 1 assignment

`i`

- 1 assignment

`i <= n`

- `n` comparisons

`total` in loop

- `n` additions
- `n` assignments

`i` in loop

- `n` additions
- `n` assignments

#### big o definition

- a way to formalize fuzzy counting
- it allows us to talk formally about how the runtime of an algorithm grows as the inputs grow

#### simplifying big o operations

- constants don't matter `O(2n)` -> `O(n)`, `O(500)` -> `O(1)`, `O(13n^2)` -> `O(n^2)`
- smaller terms don't matter `O(n + 1000)` -> `O(n)`, `O(n^2 + 5n + 8)` -> `O(n^2)`

- arithmetic operations are constant
- variable assignment is constant
- accessing elements in an array by index or object by key is constant
- in a loop, the complexity is the length of the loop times the complexity of whatever happens inside the loop

#### space complexity

auxiliary space complexity

- space required by the algorithm, not the space taken up by the inputs

- most primitives (booleans, numbers, `undefined`,`null`) are constant space
- strings require `O(n)` space (`n` is the string length)
- reference types are generally `O(n)` where `n` is the length (for arrays) or number of keys (for objects)

`O(1)` space

```js
function total(int) {
  let total = 0;
  for (let i = 0; i < int; i++) {
    total += i;
  }
  return total;
}
```

`O(n)` space

```js
function double(arr) {
  let newArr = [];
  for (let i = 0; i < arr.length; i++) {
    newArr.push(2 * arr[i]);
  }
  return newArr;
}
```

#### logarithms

the logarithm of a number roughly measures the number of times you can divide that number by 2 _before you get a value that's less than or equal to one_

```js
8 / 2; //1
4 / 2; //2
2 / 2; //3
0;
```

answer: `log = 3`

#### multi-part algorithms

- if your algorithm is in the form "do this, then, when you're all done, do that" you _ADD_ the runtimes
- if your algorithm is in the form "do this for each time you do that" then you _MULTIPLY_ the runtimes

```js
for (let i = 0; i < arrayA.length; i++) {
  console.log(i);
}

for (let i = 0; j < arrayB.length; j++) {
  console.log(j);
}
```

we do `arrayA` chunks of work then `arrayB` chunks of work, therefore the total amount of work is `O(A + B)`

```js
for (let i = 0; i < arrayA.length; i++) {
  for (let j = 0; j < arrayB.length; j++) {
    console.log(`${i}, ${j}`);
  }
}
```

we do `arrayB` chunks of work for each element in `arrayA`, therefore the total amount of work is `O(A * B)`

#### log n runtimes

when you see a problem where the number of elements in the problem space gets halved each time, that will likely be a `O(log N)` runtime

What is `k` in this expression?

`2^k = N`

```js
N = 16;
N / 2; // 8
N / 2; // 4
N / 2; // 2
N / 2; // 1
```

The log expresses `2^4` -> `log^2 16 = 4`
`log^2 N = k` -> `2^k = N`
