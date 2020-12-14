#### Tree traversal

breadth vs depth

breadth:

- if wider tree, could take up more space (worse space complexity)

depth:

- if more narrow tree, could take up more space (worse space complexity)

use cases:

InOrder - used commonly in binary search trees, get all nodes in a tree in their underlying order
PreOrder - can be used to "Export" a tree structure so that it it easily restructured or copied

##### breadth first search

> visit every sibling node before you visit a child (work horizontally ----->)

```js
bfs() {
  let queue = [];
  let data = [];
  let current = this.root;

  queue.push(current);

  while (queue.length) {
    current = queue.shift();
    data.push(current);
    if (current.left) queue.push(current.left)
    if (current.right) queue.push(current.right)
  }
  return data;
}
```

##### depth first search

> work vertically ^

preorder

```js
dfsPreOrder() {
  let data = [];
  function traverse(node) {
    data.push(node);
    if (node.left) traverse(node.left);
    if (node.right) traverse(node.right);
  }
  traverse(this.root);
  return data;
}
```

postorder

```js
dfsPostOrder() {
  let data = [];
  function traverse(node) {
    if (node.left) traverse(node.left);
    if (node.right) traverse(node.right);
    data.push(node);
  }
  traverse(this.root);
  return data;
}
```

inorder

```js
dfsInOrder() {
  let data = [];
  function traverse(node) {
    node.left && traverse(node.left);
    data.push(node);
    node.right && traverse(node.right);
  }
  traverse(node);
  return data;
}
```
