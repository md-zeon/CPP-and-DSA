# Day 39: Advanced Hashing Problems & Applications - Problems

## Problem List

### 1. Find Majority Element (> n/3 times)

- **Description**: Find all elements that appear more than n/3 times in the array.
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ arr[i] ≤ 10^9
- **Example**:
  - Array: [3,2,3]
  - Output: 3 (appears 2 > 3/3 times)
- **Approach**: Use unordered_map to count frequencies, check > n/3.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

### 2. Check if Two Strings are Valid Anagrams

- **Description**: Check if two strings are anagrams (same characters with same frequencies).
- **Constraints**: 1 ≤ length ≤ 10^5
- **Example**:
  - s1: "listen", s2: "silent"
  - Output: true
- **Approach**: Use unordered_map to count frequencies in one string, decrement in the other.
- **Time Complexity**: O(n)
- **Space Complexity**: O(k) where k is distinct characters

### 3. Count Distinct Elements in Array

- **Description**: Count the number of distinct elements in the array.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ arr[i] ≤ 10^9
- **Example**:
  - Array: [1,2,1,3,4,2,3]
  - Output: 4 (1,2,3,4)
- **Approach**: Use unordered_set to store unique elements.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

### 4. Find Union and Intersection of Two Arrays

- **Description**: Find the union and intersection of two arrays.
- **Constraints**: 1 ≤ n, m ≤ 10^5
- **Example**:
  - Array1: [1,2,3], Array2: [2,3,4]
  - Union: [1,2,3,4], Intersection: [2,3]
- **Approach**: Use unordered_set for union and intersection tracking.
- **Time Complexity**: O(n + m)
- **Space Complexity**: O(n + m)

### 5. Reconstruct Itinerary from Tickets

- **Description**: Given flight tickets, reconstruct the complete travel itinerary.
- **Constraints**: 1 ≤ n ≤ 10^5, string cities
- **Example**:
  - Tickets: Delhi->Mumbai, Mumbai->Chennai
  - Output: Delhi -> Mumbai -> Chennai
- **Approach**: Use unordered_map for tickets, find start, follow chain.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

## Additional Challenges

- Find the largest subarray with sum zero.
- Count subarrays with sum K.
- Find the first non-repeating character in a string.
- Check if a string is a valid palindrome using hashing.
- Find the longest substring without repeating characters.

## Notes

- Hashing provides efficient solutions for frequency and membership problems.
- Use unordered_map for frequency counting and unordered_set for uniqueness.
- Prefix sum technique is powerful for subarray problems.
- Always handle edge cases like empty arrays or strings.
- Hashing is ideal for problems requiring O(1) lookups.
