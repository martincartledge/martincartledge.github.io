#### technical questions

##### how to prepare

- try to solve the problem on your own
- write the code on paper
- test your code on paper (general, base, and error cases)
- type your paper as-is into a computer, note what mistakes you made
- do as many mock interviews as possible

##### core data structures, algorithms, and concepts

###### data structures

- linked lists
- trees, tries, graphs
- stacks and queues
- heaps
- vectors/arraylists
- hash tables

###### algorithms

- breadth-first search
- depth-first search
- binary search
- merge sort
- quick sort

###### concepts

- bit manipulation
- memory (stack vs heap)
- recursion
- dynamic programming
- big O time and space

| power of 2 | exact value (x)   | approx value | x bytes into mb, gb, etc |
| ---------- | ----------------- | ------------ | ------------------------ |
| 7          | 128               |              |                          |
| 8          | 256               |              |                          |
| 10         | 1024              | 1 thousand   | 1 kb                     |
| 16         | 65,536            |              | 64 kb                    |
| 20         | 1,048,576         | 1 million    | 1 mb                     |
| 30         | 1,073,741,824     | 1 billion    | 1 gb                     |
| 32         | 4,294,967,296     |              | 4 gb                     |
| 40         | 1,099,511,627,776 | 1 trillion   | 1 tb                     |

##### walking through a problem

- listen carefully
- draw an example
  - be specific, use real numbers or strings (applicable to the problem)
  - not special case
- state a brute force
  - explain time and space complexity
  - valuable to discuss (starting point for optimizations)
- optimize
  - look for unused information
  - use a fresh example
  - solve it incorrectly
  - make time vs space tradeoff
  - precompute information
  - use a hash table
  - think about best conceivable runtime
- walk through
  - take a moment to solidify your understanding of the algorithm
  - walk through your algorithm to feel out structure (know what variables are and when they change)
- implement
  - write beautiful code
    - modularized code `1,2,3,4,5,6` -> `initIncrementalMatrix(int size)`
    - error checks (add `todo` and explain what you would like to test)
    - use other classes/structs where appropriate
    - good variable names
- test
  - start with a conceptual test
  - weird looking code
  - hot spots (recursive code, division, null nodes, etc)
  - small test cases
  - special cases (test against nulls, single element values, extreme cases, etc)

bud optimization
b - bottlenecks
u - unnecessary work
d - duplicated work
