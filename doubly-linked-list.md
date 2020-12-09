#### doubly linked lists

> almost identical to singly linked lists, except every node has another pointer, to the previous node

- more flexibility
- more memory

Time complexity

- insertion O(1)
- removal - O(1)
- searching - O(n)
- access - O(n)

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

  get(index) {
    if (index < 0 || index >= this.length) return null;

    const middle = Math.floor(this.length / 2);

    let currentNode;
    let counter;
    if (index <= middle) {
      counter = 0;
      currentNode = this.head;
      while (counter !== index) {
        counter++;
        currentNode = currentNode.next;
      }
    } else {
      counter = this.length - 1;
      currentNode = this.tail;
      while (counter !== index) {
        counter--;
        currentNode = currentNode.prev;
      }
    }
    return currentNode;
  }

  set(index, val) {
    let targetNode = this.get(index);
    if (targetNode !== null) {
      targetNode.val = val;
      return true;
    }
    return false;
  }

  insert(index, val) {
    if (index < 0 || index > this.length) return false;

    if (index === 0) return !!this.unshift(val);
    if (index === this.length) return !!this.push(val);

    let beforeNode = this.get(index - 1);

    let afterNode = beforeNode.next;

    let newNode = new Node(val);
    // update next pointer in previous to point to new node
    beforeNode.next = newNode;
    // update new node to point to prev node
    newNode.prev = beforeNode;
    // update newNode to pointer to next item after new node
    newNode.next = beforeNode.next;
    // update item after new prev to point to new node
    afterNode.prev = newNode;

    this.length++;

    return true;
  }

  remove(index) {
    if (index < 0 || index >= this.length) return undefined;
    if (index === 0) return this.shift();
    if (index === this.length - 1) return this.pop();

    let removedNode = this.get(index);

    let beforeNode = removedNode.prev;

    let afterNode = removedNode.next;

    beforeNode.next = afterNode;
    afterNode.prev = beforeNode;
    removedNode.next = null;
    removedNode.prev = null;

    this.length--;

    return removedNode;
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

##### get

- get a specified node from a doubly linked list

```js
  get(index) {
    if (index < 0 || index >= this.length) return null;

    const middle = Math.floor(this.length / 2);

    let currentNode;
    let counter;
    if (index <= middle) {
      counter = 0;
      currentNode = this.head;
      while (counter !== index) {
        counter++;
        currentNode = currentNode.next;
      }
    } else {
      counter = this.length - 1;
      currentNode = this.tail;
      while (counter !== index) {
        counter--;
        currentNode = currentNode.prev;
      }
    }
    return currentNode;
  }
```

##### set

- update the value of a specified node in a doubly linked list

```js
  set(index, val) {
    let targetNode = this.get(index);
    if (targetNode !== null) {
      targetNode.val = val;
      return true;
    }
    return false;
  }
```

##### insert

- insert a new node into a doubly linked list

```js
  insert(index, val) {
    if (index < 0 || index > this.length) return false;

    if (index === 0) return !!this.unshift(val);
    if (index === this.length) return !!this.push(val);

    let beforeNode = this.get(index - 1);

    let afterNode = beforeNode.next;

    let newNode = new Node(val);
    // update next pointer in previous to point to new node
    beforeNode.next = newNode;
    // update new node to point to prev node
    newNode.prev = beforeNode;
    // update newNode to pointer to next item after new node
    newNode.next = beforeNode.next;
    // update item after new prev to point to new node
    afterNode.prev = newNode;

    this.length++;

    return true;
  }
```

##### remove

- remove a node from a doubly linked list

```js
  remove(index) {
    if (index < 0 || index >= this.length) return undefined;
    if (index === 0) return this.shift();
    if (index === this.length - 1) return this.pop();

    let removedNode = this.get(index);

    let beforeNode = removedNode.prev;

    let afterNode = removedNode.next;

    beforeNode.next = afterNode;
    afterNode.prev = beforeNode;
    removedNode.next = null;
    removedNode.prev = null;

    this.length--;

    return removedNode;
  }
```
