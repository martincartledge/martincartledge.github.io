## Sliding Window

- this pattern involves creating a window which can either be an array or number from one position to another
- depending on a certain condition, the window either increases or closes (and a new window is created)
- very useful for keeping track of a subset of data in an array/string, etc

### What is the "Sliding Window" pattern?

### When should I use a Sliding Window?

### What are some common problems you can solve using the Sliding Window pattern?

```js
/*
  write a function called maxSubarraySum which accepts an array of integers and a number called n
  the function should calculate the maximum sum of n consecutive elements in the array

  Expected outcome:

  maxSubarraySum([1,2,5,2,8,1,5], 2) // 10
  maxSubarraySum([1,2,5,2,8,1,5], 4) // 17
  maxSubarraySum([4,2,1,6], 1) // 6
  maxSubarraySum([4,2,1,6,2], 4) // 13
  maxSubarraySum([], 4) // null
*/
function maxSubarraySum(arr, num) {
  let maxSum = 0;
  let tempSum = 0;
  if (arr.length < num) return null;
  for (let i = 0; i < num; i++) {
    maxSum += arr[i];
  }
  tempSum = maxSum;
  for (let i = num; i < array.length; i++) {
    tempSum = tempSum -= arr[i - num] + arr[i];
    maxSum = Math.max(maxSum, tempSum);
  }
  return maxSum;
}
```
