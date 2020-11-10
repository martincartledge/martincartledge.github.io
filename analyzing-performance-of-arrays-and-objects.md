#### analyzing performance of arrays and objects

##### objects

- unordered, key value pairs
- when you don't need order
- when you need fast access for insertion and removal
  - insertion `O(1)`
  - removal `O(1)`
  - searching `O(n)`
  - access `O(1)`
- object methods
  - `Object.keys()` `O(n)`
  - `Object.values()` `O(n)`
  - `Object.entries()` `O(n)`
  - `hasOwnProperty()` `O(1)`

##### arrays

- ordered lists
- use when you need order
- when you need access for insertion and removal
  - insertion at end (`push`) `O(1)`
  - insertion anywhere else (`unshift`) `O(n)`
  - removal at end (`pop`) `O(1)`
  - removal anywhere else (`shift`) `O(n)`
  - searching `O(n)`
  - access `O(1)`
  - array methods
    - push `O(1)`
    - pop `O(1)`
    - shift `O(n)`
    - unshift `O(n)`
    - concat `O(n)`
    - slice `O(n)`
    - splice `O(n)`
    - sort `O(n * log n)`
    - forEach, map, filter, reduce `O(n)`
