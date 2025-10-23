# Day 38: Hashing & Hash Tables - Problems

## Problem List

### 1. Implement Custom Hash Table with Chaining

- **Description**: Implement a hash table with chaining for collision resolution.
- **Constraints**: 1 ≤ n ≤ 10^5, string keys
- **Example**:
  - Insert: "India" -> 150, "China" -> 200
  - Search: "India" -> 150
- **Approach**: Use array of linked lists, hash function for index, chaining for collisions.
- **Time Complexity**: O(1) average, O(n) worst
- **Space Complexity**: O(n)

### 2. Solve Two Sum Problem Using Hashing

- **Description**: Find two indices in an array such that arr[i] + arr[j] = target.
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ arr[i], target ≤ 10^9
- **Example**:
  - Array: [2,7,11,15], target=9
  - Output: [0,1] (2+7=9)
- **Approach**: Use unordered_map to store indices, check for complement.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

### 3. Find First Repeating Element in Array

- **Description**: Find the first element that repeats in the array.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ arr[i] ≤ 10^9
- **Example**:
  - Array: [1,5,3,4,3,5,6]
  - Output: 5 (first repeating)
- **Approach**: Use unordered_map to track first occurrence.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

### 4. Count Distinct Elements in Window of Size K

- **Description**: Count the number of distinct elements in each window of size K.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ k ≤ n
- **Example**:
  - Array: [1,2,1,3,4,2,3], k=4
  - Output: 3,4,4,3
- **Approach**: Use unordered_map to track frequency in sliding window.
- **Time Complexity**: O(n)
- **Space Complexity**: O(k)

### 5. Check if Two Arrays are Equal Using Hashing

- **Description**: Check if two arrays have the same elements with same frequencies.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ arr[i] ≤ 10^9
- **Example**:
  - Array1: [1,2,5,4,0], Array2: [2,4,5,0,1]
  - Output: true
- **Approach**: Use unordered_map to count frequencies in both arrays.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

## Additional Challenges

- Find the intersection of two arrays using hashing.
- Count the frequency of each element in an array.
- Find the longest subarray with equal 0s and 1s.
- Implement a hash table with open addressing.
- Solve the anagram problem using hashing.

## Notes

- Hash tables provide O(1) average time for insert, search, delete.
- Handle collisions using chaining or open addressing.
- STL unordered_map and unordered_set are hash-based.
- Monitor load factor for performance.
- Hashing is useful for fast lookups and frequency counting.
