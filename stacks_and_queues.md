#### Stacks

> a collection of data organized in LIFO (last in, first out)

- managing function invocations (call stack)
- for operations like undo/redo
- routing (the history object)

Time complexity

- insertion `O(1)`
- removal `O(1)`
- searching `O(n)`
- access `O(n)`

##### Creating a stack with an array

```js
// first implementation O(1)
let stack = [];

stack.push("google");

stack.push("instagram");

stack.push("youtube");

stack.pop(); // youtube

// second implementation O(n)
let stack = [];

stack.unshift("create new file");

stack.unshift("resized file");

stack.unshift("clone out wrinkle");

stack.shift(); // clone out wrinkle
```

##### Creating a stack with a linked list

```js
class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class Stack {
  constructor() {
    this.first = null;
    this.last = null;
    this.size = 0;
  }

  push(val) {
    let newNode = new Node(val);
    if (!this.first) {
      this.first = newNode;
      this.last = newNode;
    } else {
      let temp = this.first;
      this.first = newNode;
      this.first.next = temp;
    }
    return ++this.size;
  }

  pop() {
    if (!this.first) return null;
    let temp = this.first;
    if (this.first === this.last) {
      this.last = null;
    }
    this.first = this.first.next;
    this.size--;
    return temp.val;
  }
}
```

#### Queues

> a collection of data organized in FIFO (first in, first out)

- background tasks (uploading/downloading files)
- uploading resources
- printing / task processing

time complexity

- insertion `O(1)`
- removal `O(1)`
- searching `O(n)`
- access `O(n)`

##### Creating a queue with an array

```js
// first implementation O(n)
let q = [];

q.push("first");
q.push("second");
q.push("third");

q.shift(); // first

// second implementation O(n)
let q = [];

q.unshift("first");
q.unshift("second");
q.unshift("third");

q.pop(); // first
```

##### Creating a queue with a linked list

```js
class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class Queue {
  constructor() {
    this.first = null;
    this.last = null;
    this.size = 0;
  }

  enqueue(val) {
    let newNode = new Node(val);
    if (!this.first) {
      this.first = newNode;
      this.last = newNode;
    } else {
      this.last.next = newNode;
      this.last = newNode;
    }
    return ++this.size;
  }

  dequeue() {
    if (!this.first) return null;
    let temp = this.first;
    if (this.first === this.last) {
      this.last = null;
    }
    this.first = this.first.next;
    this.size--;
    return temp.value;
  }
}
```
