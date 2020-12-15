#### Binary Heaps

> very similar to a binary search tree, but with some different rules

- in a MaxBinaryHeap, parent nodes are always larger than child nodes
- in a MinBinaryHeap, parent nodes are always smaller than child nodes

max binary heap

- each parent has at most two child nodes
- the value of each parent node is always greater than its child nodes
- the parent is greater than the children, but there are no guarantees between sibling nodes
- as compact as possible
- all children of each node are as full as they can be
- left children are filled out first

```js
class MaxBinaryHeap {
  constructor() {
    this.values = [41, 39, 33, 18, 27, 12];
  }

  insert(value) {
    this.values.push(value);
    return this.bubbleUp();
  }

  bubbleUp() {
    let index = this.values.length - 1;
    const value = this.values[index];

    while (index > 0) {
      let parentIndex = Math.floor((index - 1) / 2);
      let parent = this.values[parentIndex];
      if (value <= parent) break;
      this.values[parentIndex] = value;
      this.values[index] = parent;
      index = parentIndex;
    }
    return this;
  }
}
```
