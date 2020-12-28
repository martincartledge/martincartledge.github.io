# graphs

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

## adjacency matrix

- takes up more space in sparse graphs
- slower to iterate over all edges
- faster to lookup specific edge

## adjacency list

- can take up less pace in sparse graphs
- faster to iterate over all edges
- can be slower to lookup specific edge

## create an adjacency list

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

  depthFirstRecursive(start) {
    const results = [];
    const visited = {};
    const adjacencyList = this.adjacencyList;
    function dfs(vertex) {
      if (!vertex) return null;
      visited[vertex] = true;
      results.push(vertex);
      adjacencyList[vertex].forEach((neighbor) => {
        if (!visited[neighbor]) {
          return dfs(neighbor);
        }
      });
    }
    dfs(start);
    return results;
  }

  depthFirstIterative(start) {
    const stack = [start];
    const results = [];
    const visited = {};

    visited[start] = true;
    let current;
    while (stack.length > 0) {
      current = stack.pop();
      results.push(current);
      this.adjacencyList[current].forEach((neighbor) => {
        if (!visited[neighbor]) {
          visited[current] = true;
          stack.push(neighbor);
        }
      });
    }

    return results;
  }

  breadthFirst(start) {
    const queue = [start];
    const results = [];
    const visited = {};
    let current;

    visited[start] = true;

    while (queue.length) {
      current = queue.shift();
      results.push(current);

      this.adjacencyList[current].forEach((neighbor) => {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          queue.push(neighbor);
        }
      });
    }

    return results;
  }
}
```

## Visiting, Updating, Checking each vertex in a graph

Graph Traversal Uses:

- peer to peer networking
- web crawlers
- finding "closest" matches / recommendations
- shortest path problems
  - gps navigation
  - solving mazes
  - AI (shortest path to win the game)

### Depth First Graph Traversal

#### Depth first search recursively:

```js
  depthFirstRecursive(start) {
    const results = [];
    const visited = {};
    const adjacencyList = this.adjacencyList;
    function dfs(vertex) {
      if (!vertex) return null;
      visited[vertex] = true;
      results.push(vertex);
      adjacencyList[vertex].forEach((neighbor) => {
        if (!visited[neighbor]) {
          return dfs(neighbor);
        }
      });
    }
    dfs(start);
    return results;
  }
```

#### Depth first search iteratively:

```js
  depthFirstIterative(start) {
    const stack = [start];
    const results = [];
    const visited = {};

    visited[start] = true;
    let current;
    while (stack.length > 0) {
      current = stack.pop();
      results.push(current);
      this.adjacencyList[current].forEach((neighbor) => {
        if (!visited[neighbor]) {
          visited[current] = true;
          stack.push(neighbor);
        }
      });
    }

    return results;
  }
```
