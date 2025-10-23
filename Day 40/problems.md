# Day 40: Trie Data Structure & String Problems - Problems

## Problem List

### 1. Implement Trie with Insert and Search

- **Description**: Implement a Trie data structure with insert and search operations.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ word length ≤ 100
- **Example**:
  - Insert: "apple", "app"
  - Search: "apple" -> true, "app" -> true, "appl" -> false
- **Approach**: Use a tree where each node has children map and endOfWord flag.
- **Time Complexity**: Insert/Search O(L) where L is word length
- **Space Complexity**: O(L \* N)

### 2. Solve Word Break Problem

- **Description**: Check if a string can be segmented into words from a dictionary.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ dict size ≤ 1000
- **Example**:
  - Dict: ["i", "like", "sam", "sung"], String: "ilikesamsung"
  - Output: true ("i like sam sung")
- **Approach**: Use recursion with backtracking, check prefixes in Trie.
- **Time Complexity**: O(L \* N)
- **Space Complexity**: O(L)

### 3. Find Shortest Unique Prefix for Each Word

- **Description**: Find the shortest unique prefix for each word in a dictionary.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ word length ≤ 100
- **Example**:
  - Words: ["zebra", "dog", "duck", "dove"]
  - Output: ["z", "dog", "du", "dov"]
- **Approach**: Insert words with frequency, traverse until freq == 1.
- **Time Complexity**: O(L \* N)
- **Space Complexity**: O(L \* N)

### 4. Find Longest String with All Prefixes

- **Description**: Find the longest string such that all its prefixes exist in the dictionary.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ word length ≤ 100
- **Example**:
  - Dict: ["a", "banana", "app", "appl", "ap", "apply", "apple"]
  - Output: "apple"
- **Approach**: Use DFS to find longest word where all prefixes are endOfWord.
- **Time Complexity**: O(N \* L)
- **Space Complexity**: O(L)

### 5. Implement Autocomplete Using Trie

- **Description**: Implement autocomplete functionality to suggest words based on prefix.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ prefix length ≤ 100
- **Example**:
  - Dict: ["apple", "app", "application"], Prefix: "app"
  - Output: ["app", "apple", "application"]
- **Approach**: Traverse Trie for prefix, then collect all complete words.
- **Time Complexity**: O(L + K) where K is suggestions
- **Space Complexity**: O(L)

## Additional Challenges

- Count the number of words with a given prefix.
- Delete a word from the Trie.
- Find all words that start with a given prefix.
- Implement a spell checker using Trie.
- Find the longest common prefix of all words.

## Notes

- Trie is efficient for prefix-based operations.
- Each node represents a character, root is empty string.
- Use unordered_map for children to handle any character set.
- Track endOfWord for complete words and freq for prefix problems.
- DFS or recursion is common for traversing the Trie.
