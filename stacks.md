##### Stacks

> A stack is a data structure that only allows data to be added (pushed) or removed (popped) from the “top” of the stack.

In Stack, the array itself is stored as `_array`, so it’s a signal to other developers that to use the Stack as intended, they shouldn’t need to access it directly. From there, we can implement the `.push()` and `.pop()` methods:

```js
class Stack {
  constructor() {
    this._array = [];
  }

  push(newValue) {
    this._array.push(newValue);
  }

  pop() {
    return this._array.pop();
  }
}
```
