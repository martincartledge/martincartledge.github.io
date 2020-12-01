#### Linked list

> a list comprised of a series of nodes

- the `head` node is the node at the beginning of the list
- each node contains data or a link (pointer) to the next node in the list
- the list is terminated when a node's link is `null` (called the `tail` node)
- nodes are not required to be sequentially located in memory
- linked lists allow for quick insertion and removal of nodes
- can be unidirectional or bidirectional

common operations

- adding nodes
- removing nodes
- finding a node
- traversing (travelling through) the linked list

##### sub topic

> a definition of the sub topic

- list item to describe sub topic
- list item to describe sub topic
- list item to describe sub topic
- list item to describe sub topic

> linked lists are made up of what elements

`nodes`

> linked list nodes do not contain which of the following?

`roots`

> consider the linked list: `a -> b -> c`
>
> when removing `b` from the list, which node(s) need to be updated?

`a`

> what is the head node in a linked list?

`the first node in the list`

#### Constructor and Adding to Head

```js
/*
The only property we need our linked list to have is a head, which we will add in our constructor. Inside the LinkedList class, define the constructor. It should take no parameters, and should set the list’s head to null.

Define an .addToHead() method that takes one parameter called data. Inside the method, create a Node const variable named newHead, and pass data as an argument.

Still inside your .addToHead() method, create a const variable named currentHead, and set it equal to the list’s head. Then change the list’s head to equal newHead.

Finally, still in your .addToHead() method, check if there is a current head to the list. If there is, set the list’s head’s next node to currentHead.
*/

const Node = require("./Node");

class LinkedList {
  constructor() {
    this.head = null;
    this.next = null;
  }

  addToHead(data) {
    const newHead = new Node(data);

    const currentHead = this.head;

    if (currentHead) {
      this.head = setNextNode(currentHead);
    }

    this.head = newHead;
  }
}

module.exports = LinkedList;
```

#### Adding to Tail

```js
/*
Define an .addToTail() method for the LinkedList that has one parameter called data. Create a variable named tail, and set it equal to the list’s head. tail is going to change throughout the method, so make it a let variable.


Now that tail is equal to the head of the list, we want to check if it has any value. If tail has no value, then that means the list was empty, and we will be creating the head and tail with the data passed in.

To do this, check if tail has no value. If so, set the list’s head equal to a new Node that takes data as an argument.

If tail does have a value, that means the list is not empty. In that case, we want to iterate through the list until we find the end, so we can add tail to the end of the list.

To do this, create an else after your if statement. Inside it, make a while loop that runs while tail has a next node. Inside the loop, set tail equal to its next node.

(If you accidentally create an infinite loop and your code won’t stop running, you can reload the page to stop it.)

Finally, inside the same else block, but outside the while loop, set tail‘s next node equal to a new Node that takes data as an argument.
*/

const Node = require("./Node");

class LinkedList {
  constructor() {
    this.head = null;
  }

  addToHead(data) {
    const newHead = new Node(data);
    const currentHead = this.head;
    this.head = newHead;
    if (currentHead) {
      this.head.setNextNode(currentHead);
    }
  }

  addToTail(data) {
    let tail = this.head;

    if (!tail) {
      this.head = new Node(data);
    } else {
      while (tail.getNextNode()) {
        tail = tail.getNextNode(data);
      }
      tail.setNextNode(new Node(data));
    }
  }
}

module.exports = LinkedList;
```
