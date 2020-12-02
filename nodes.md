##### Nodes

> Nodes are the fundamental building blocks of many computer science data structures. They form the basis for linked lists, stacks, queues, trees, and more.

> An individual node contains data and links to other nodes. Each data structure adds additional constraints or behavior to these features to create the desired structure.

> The link or links within the node are sometimes referred to as pointers. This is because they “point” to another node.

> Typically, data structures implement nodes with one or more links. If these links are `null`, it denotes that you have reached the end of the particular node or link path you were previously following.

> If you inadvertently remove the single link to a node, that node’s data and any linked nodes could be “lost” to your application. When this happens to a node, it is called an orphaned node.

Which two features do most nodes contain?

- data and links to other nodes

A node containing only null pointers indicates what?

- you are at the end of the node path you were following

Consider the following nodes and links: `a->n->t`, if you want to remove the node `n`, but preserve `t`, what should the resulting structure look like?

- `a->t`

##### creating a node in javascript

```js
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }

  setNextNode(node) {
    if (node instanceof Node || node === null) {
      this.next = node;
    } else {
      throw new Error("Next node must be a member of the Node class.");
    }
  }

  getNextNode() {
    return this.next;
  }
}

const vanillaNode = new Node("Vanilla");

const strawberryNode = new Node("Berry Tasty");

const coconutNode = new Node("Coconuts for Coconut");

vanillaNode.setNextNode(strawberryNode);

strawberryNode.setNextNode(coconutNode);

let currentNode = vanillaNode;

while (currentNode !== null) {
  console.log(currentNode.data);
  currentNode = currentNode.getNextNode();
}

module.exports = Node;
```

How do you determine if `node1` is an orphan Node?

- there are no nodes that point to it

What properties make a Node useful?

- `data` helps store information, and `next` is a link to other Nodes for easier traversal

Given the following code, what would be the output of line 3 and why?

```js
const node1 = new Node(5);
const node2 = new Node(node1);
node2.getNextNode();
```

- `null`, when `node2` is initialized, it contains no links to the `next` node

Given that `node1` is a `Node` instance and links to `node2`, which is another `Node` instance, how would you remove `node1`'s link to `node2`?

```js
node1.setNextNode(null);
```

Fill in the code to link together the 3 sibling nodes: `youngest -> middle -> oldest`

Then, iterate through the nodes, starting at `youngest` to get `oldest`'s name

```js
const oldest = new Node("martin");
const middle = new Node("miranda/lexi");
const youngest = new Node("noah");

youngest.setNextNode(middle);

middle.setNextNode(oldest);

let currentSibling = youngest;

let oldestName = "";

while (currentSibling !== null) {
  oldestName = currentSibling.data;

  currentSibling = currentSibling.getNextNode();
}

console.log(`the oldest is ${oldestName}`);
```
