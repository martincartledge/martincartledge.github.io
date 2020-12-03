#### Singly Linked List

> a data structure that contains a head, tail, and length property

- consists of nodes, and each node has a value and a pointer to another node or null

##### time and space complexity

- insertion `O(1)`
- removal - `O(n)`
- searching `O(n)`
- access `O(n)`

##### linked lists vs arrays

###### lists

- do not have indexes
- connected via nodes with a next pointer
- random access is not allowed

###### arrays

- indexed in order
- insertion and deletion can be expensive
- can quickly be accessed at a specific index

##### push

> adds a new node to the tail of the linked list

```js
  push(val) {
    const newNode = new Node(val);
    if (!this.head) {
      this.head = newNode;
      this.tail = this.head;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
    }
    length++;
    return this;
  }
```

##### pop

> removes the tail node from the linked list

```js
  pop() {
    if (!this.head) return undefined;

    let prev = this.head;
    let current = this.head.next;

    while (current) {
      prev = current;
      current = current.next;
    }
    length--;
    return current;
  }
```

##### shifting

> removing a new node from the beginning of the linked list

```js
  shift() {
    if (!this.head) return undefined;
    let current = this.head;
    this.head = current.next;
    this.length--;
    if (this.length === 0) {
      this.tail = null;
    }
    return current;
  }
```

##### unshifting

> adding a new node to the beginning of the linked list

```js
  unshift(val) {
    const newNode = new Node(val);
    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      newNode.next = this.head;
      this.head = newNode;
    }
    this.length++;
    return this;
  }
```

##### get

> retrieving a node by it's position in a linked list

```js
  get(index) {
    if (index < 0 || index >= this.length) return null;
    let counter = 0;
    let current = this.head;
    while(counter !== index) {
      current = current.next;
      counter++;
    }
    return current;
  }
```

##### set

> changes the value of a node based on it's position in the linked list

```js
  set(index,value) {
    const target = this.get(index);
    if (!target) return false;
    target.val = value;
    return true;
  }
```

##### insert

> inserts a new node between existing nodes in a linked list

```js
  insert(index, value) {
    if (index < 0 || index > this.length) return false;

    if (index === this.length) return !!this.push(value);

    if (index === 0) return !!this.unshift(value);

    let newNode = new Node(value);

    let prevNode = this.get(index-1);

    const temp = prevNode.next;

    prevNode.next = newNode;

    newNode.next = temp;

    this.length++;

    return true;
  }
```

##### remove

> removes a node from the linked list at a specific position

```js
  remove(index) {
    if (index < 0 || index >= this.length) return null;
    if (index === this.length - 1) return this.pop();
    if (index === 0) return this.shift();

    let prevNode = this.get(index-1);

    let removedNode = prevNode.next;

    prevNode.next = removedNode.next;

    this.length--;

    return removedNode;
  }
```

##### reverse

> reveres all nodes in a linked list in place

```js
  reverse() {
    let current = this.head;
    this.head = this.tail;
    this.tail = current;

    let next;

    let prev = null;

    for (let i = 0; i < this.length; i++) {
      next = current.next;
      current.next = prev;
      prev = current;
      current = next;
    }
  return this;
  }
```

##### complete singly linked list

```js
class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}

class SinglyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }

  push(val) {
    const newNode = new Node(val);
    if (!this.head) {
      this.head = newNode;
      this.tail = this.head;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
    }
    this.length++;
    return this;
  }

  pop() {
    if (!this.head) return undefined;

    let current = this.head;
    let newTail = current;

    while (current.next) {
      newTail = current;
      current = current.next;
    }
    this.tail = newTail;
    this.tail.next = null;
    this.length--;
    if (this.length === 0) {
      this.head = null;
      this.tail = null;
    }
    return current;
  }

  shift() {
    if (!this.head) return undefined;
    let current = this.head;
    this.head = current.next;
    this.length--;
    if (this.length === 0) {
      this.tail = null;
    }
    return current;
  }

  unshift(val) {
    const newNode = new Node(val);
    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      newNode.next = this.head;
      this.head = newNode;
    }
    this.length++;
    return this;
  }

  get(index) {
    if (index < 0 || index >= this.length) return null;
    let counter = 0;
    let current = this.head;
    while (counter !== index) {
      current = current.next;
      counter++;
    }
    return current;
  }

  set(index, value) {
    const target = this.get(index);
    if (!target) return false;
    target.val = value;
    return true;
  }

  insert(index, value) {
    if (index < 0 || index > this.length) return false;

    if (index === this.length) return !!this.push(value);

    if (index === 0) return !!this.unshift(value);

    let newNode = new Node(value);

    let prevNode = this.get(index - 1);

    const temp = prevNode.next;

    prevNode.next = newNode;

    newNode.next = temp;

    this.length++;

    return true;
  }

  remove(index) {
    if (index < 0 || index >= this.length) return null;
    if (index === this.length - 1) return this.pop();
    if (index === 0) return this.shift();

    let prevNode = this.get(index - 1);

    let removedNode = prevNode.next;

    prevNode.next = removedNode.next;

    this.length--;

    return removedNode;
  }

  reverse() {
    let current = this.head;
    this.head = this.tail;
    this.tail = current;

    let next;

    let prev = null;

    for (let i = 0; i < this.length; i++) {
      next = current.next;
      current.next = prev;
      prev = current;
      current = next;
    }
    return this;
  }
}

var l = new SinglyLinkedList();
```
