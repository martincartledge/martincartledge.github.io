#### graphs

> collection of nodes

real-world examples:

- social networks
- recommendations
- location / mapping
- routing algorithms
- file system optimizations

terms:

- vertex: a node
- edge: connection between nodes

types of graphs:

- undirected graph: no direction assigned to an edge
- directed graph: direction assigned to an edge
- weighted graph: edges have a value
- unweighted graph: edges do not have a value

##### adjacency matrix

- takes up more space in sparse graphs
- slower to iterate over all edges
- faster to lookup specific edge

##### adjacency list

- can take up less pace in sparse graphs
- faster to iterate over all edges
- can be slower to lookup specific edge

##### create an adjacency list

```js
class Graph {
  constructor() {
    this.adjacencyList = {};
  }

  addVertex(vertex) {
    if (!this.adjacencyList[vertex]) this.adjacencyList[vertex] = [];
  }

  addEdge(vertex1, vertex2) {
    this.adjacencyList[vertex1].push(vertex2);
    this.adjacencyList[vertex2].push(vertex1);
  }

  removeEdge(vertex1, vertex2) {
    this.adjacencyList[vertex1] = this.adjacencyList[vertex1].filter(
      (v1) => v1 !== vertex2
    );
    this.adjacencyList[vertex2] = this.adjacencyList[vertex2].filter(
      (v2) => v2 !== vertex1
    );
  }

  removeVertex(vertex) {
    while (this.adjacencyList[vertex].length) {
      const adjacentVertex = this.adjacencyList[vertex].pop();
      this.removeEdge(vertex, adjacentVertex);
    }
    delete this.adjacencyList[vertex];
  }
}
```
