#### trees

> a data structure that consists of nodes in a parent /child relationship

- nonlinear
- a node can only point to a child (not a child or parent)
- can only have one entry point (root)
- root: top node in a tree
- child: a node directly connected to another node when moving away from the root
- parent: the converse notion of a child
- siblings: a group of nodes with the same parent
- leaf: a node with no children
- edge: the connection between one node and another

use cases:

- DOM (document object model)
- network routing (broadcast, multi-cast, etc)
- abstract syntax tree
- artificial intelligence (decision trees)
- folders in operating systems
- computer file systems

#### binary search trees

- every parent node has at most two children
- every node to the left of a parent node is always less than the parent
- every node to the right of a parent node is always greater than the parent

time complexity

- insertion `O(log n)`
- searching `O(log n)`

binary search tree class

```js
class Node {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }
}

class BinarySearchTree {
  constructor() {
    this.root = null;
  }

  insert(val) {
    let newNode = new Node(val);

    if (this.root === null) {
      this.root = newNode;
      return this;
    }
    let currentNode = this.root;
    while (true) {
      if (currentNode.value === val) return undefined;
      if (val < currentNode.value) {
        // move to the left
        if (currentNode.left === null) {
          currentNode.left = newNode;
          return this;
        }
        currentNode = currentNode.left;
      } else if (val > currentNode.value) {
        // move to the right
        if (currentNode.right === null) {
          currentNode.right = newNode;
          return this;
        }
        currentNode = currentNode.right;
      }
    }
    return this;
  }

  find(val) {
    if (!this.root) return false;
    let currentNode = this.root;
    let found = false;

    while (currentNode && !found) {
      if (currentNode.val === val) {
        found = true;
        return true;
      } else if (val < currentNode.value) {
        // move to the left
        if (currentNode.left === null) return false;
        currentNode = currentNode.left;
      } else if (val > currentNode.value) {
        // move to the right
        if (currentNode.right === null) return false;
        currentNode = currentNode.right;
      }
    }
    return false;
  }
}
```
