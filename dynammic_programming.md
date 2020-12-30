# dynamic programming

> a method for solving a complex problem by breaking it down into a collection of simpler subproblems, solving each of those subproblems just once, and storing their solution

> using past knowledge to make solving a future problem easier

## overlapping subproblems

> a problem is said to have overlapping subproblems if it can be broken down into subproblems which are reused several times

## optimal substructure

> a problem is said to have optimal substructure if an optimal solution can be constructed from optimal solutions of its subproblems

## write a recursive solution

fibonacci sequence

```js
function fibonacci(n) {
  if (n <= 2) return 1;
  return fibonacci(n - 1) + fibonacci(n - 2);
}
```

## big o of recursive fibonacci solution (not memoized)

`O(2^n)`

## memoization - improve recursive fibonacci solution

> storing the results of expensive function calls and returning the cached result when the same inputs occur again

```js
function fib(n, memo = []) {
  if (memo[n] !== undefined) return memo[n];
  if (n <= 2) return 1;
  let res = fib(n - 1, memo) + fib(n - 2, memo);

  memo[n] = res;

  return res;
}
```

## big o of recursive fibonacci solution (memoized)

`O(n)`

## tabulation - improve recursive fibonacci solution

> storing the result of a previous result in a "table" (usually an array)

- usually done using iteration
- better space complexity can be achieved

```js
function fib(n) {
  if (n <= 2) return 1;
  let fibNums = [0, 1, 1];
  for (let i = 3; i <= n; i++) {
    fibNums[i] = fibNums[n - 1] + fibNums[n - 2];
  }
  return fibNums[n];
}
```
