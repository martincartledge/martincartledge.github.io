#### doubly linked lists

> almost identical to singly linked lists, except every node has another pointer, to the previous node

- more flexibility
- more memory

Node

- val
- next
- prev

DoublyLinkedList

- head
- tail
- length

```js
class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
    this.prev = null;
  }
}

class DoublyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }

  push(val) {
    const newNode = new Node(val);

    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.tail.next = newNode;
      newNode.prev = this.tail;
      this.tail = newNode;
    }
    this.length++;
    return this;
  }

  pop() {
    if (!this.head) return undefined;

    let removedNode = this.tail;

    if (this.length === 1) {
      this.head = null;
      this.tail = null;
    } else {
      this.tail = removedNode.prev;

      this.tail.next = null;

      removedNode.prev = null;
    }

    this.length--;

    return removedNode;
  }

  shift() {
    if (!this.head) return undefined;

    let removedHead = this.head;

    if (this.length === 1) {
      this.head = null;
      this.tail = null;
    } else {
      this.head = removedHead.next;
      this.head.prev = null;
      removedHead.next = null;
    }

    this.length--;
    return removedHead;
  }

  unshift(val) {
    let newNode = new Node(val);

    if (this.length === 0) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.head.prev = newNode;
      newNode.next = this.head;
      this.head = newNode;
    }
    this.length++;
    return this;
  }
}
```

##### push

- add a node to the end of a doubly linked list

```js
  push(val) {
    const newNode = new Node(val);

    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.tail.next = newNode;
      newNode.prev = this.tail;
      this.tail = newNode;
    }
    this.length++;
    return this;
  }
```

##### pop

- remove the last node of a doubly linked list

```js
  pop() {
    if (!this.head) return undefined;

    let removedNode = this.tail;

    if (this.length === 1) {
      this.head = null;
      this.tail = null;
    } else {
      this.tail = removedNode.prev;

      this.tail.next = null;

      removedNode.prev = null;
    }

    this.length--;

    return removedNode;
  }
```

##### shift

- removes the node at the beginning of a doubly linked list

```js
  shift() {
    if (!this.head) return undefined;

    let removedHead = this.head;

    if (this.length === 1) {
      this.head = null;
      this.tail = null;
    } else {
      this.head = removedHead.next;
      this.head.prev = null;
      removedHead.next = null;
    }

    this.length--;
    return removedHead;
  }
```

##### unshift

- adds a new node to the beginning of a doubly linked list

```js
  unshift(val) {
    let newNode = new Node(val);

    if (this.length === 0) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.head.prev = newNode;
      newNode.next = this.head;
      this.head = newNode;
    }
    this.length++;
    return this;
  }
```
