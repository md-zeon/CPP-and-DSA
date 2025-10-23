# Day 40: Trie Data Structure & String Problems

## Topics Covered

- Trie Implementation
- Insert and Search Operations
- Word Break Problem
- Prefix Problems
- Longest String with All Prefixes

## 1. Trie Data Structure

### What is a Trie?

- **Trie** (prefix tree) is a tree-like data structure
- Used for storing collection of strings
- Each node represents a character
- Root represents empty string
- Each path from root to leaf represents a word

### Node Structure:

```cpp
class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    int freq; // for prefix problems

    Node() {
        endOfWord = false;
        freq = 0;
    }
};
```

### Trie Class:

```cpp
class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
};
```

## 2. Basic Operations

### Insert Operation - O(L) where L is word length

```cpp
void insert(string key) {
    Node* temp = root;
    for (int i = 0; i < key.size(); i++) {
        if (temp->children.count(key[i]) == 0) {
            temp->children[key[i]] = new Node();
        }
        temp = temp->children[key[i]];
    }
    temp->endOfWord = true;
}
```

### Search Operation - O(L) where L is word length

```cpp
bool search(string key) {
    Node* temp = root;
    for (int i = 0; i < key.size(); i++) {
        if (temp->children.count(key[i]) == 0) {
            return false;
        }
        temp = temp->children[key[i]];
    }
    return temp->endOfWord;
}
```

### Starts With Operation - O(L)

```cpp
bool startsWith(string prefix) {
    Node* temp = root;
    for (int i = 0; i < prefix.size(); i++) {
        if (temp->children[prefix[i]]) {
            temp = temp->children[prefix[i]];
        } else {
            return false;
        }
    }
    return true;
}
```

## 3. Word Break Problem

### Problem:

Check if a given string can be segmented into words from dictionary.

### Example:

- Dictionary: ["i", "like", "sam", "sung", "samsung", "mobile", "ice"]
- String: "ilikesamsung"
- Result: Can be broken as "i like sam sung"

### Solution Approach:

- Use recursion with backtracking
- Try all possible prefixes that exist in trie
- Recursively check remaining string

```cpp
bool wordBreakFunc(string key, Trie &trie) {
    if (key.size() == 0) return true;

    for (int i = 0; i < key.size(); i++) {
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);
        if (trie.search(first) && wordBreakFunc(second, trie)) {
            return true;
        }
    }
    return false;
}
```

## 4. Prefix Problem (Shortest Unique Prefix)

### Problem:

Find shortest unique prefix for each word in dictionary where no word is prefix of another.

### Example:

- Words: ["zebra", "dog", "duck", "dove"]
- Result: ["z", "dog", "du", "dov"]

### Solution Approach:

- Insert all words in trie with frequency count
- For each word, traverse until frequency becomes 1
- That position gives the unique prefix

```cpp
void insert(string key) {
    Node* temp = root;
    for (int i = 0; i < key.size(); i++) {
        if (temp->children.count(key[i]) == 0) {
            temp->children[key[i]] = new Node();
            temp->children[key[i]]->freq = 1;
        } else {
            temp->children[key[i]]->freq++;
        }
        temp = temp->children[key[i]];
    }
    temp->endOfWord = true;
}

string getPrefix(string key) {
    Node* temp = root;
    string prefix = "";
    for (int i = 0; i < key.size(); i++) {
        prefix += key[i];
        if (temp->children[key[i]]->freq == 1) {
            break;
        }
        temp = temp->children[key[i]];
    }
    return prefix;
}
```

## 5. Longest String with All Prefixes

### Problem:

Find the longest string such that all its prefixes exist in the dictionary.

### Example:

- Dictionary: ["a", "banana", "app", "appl", "ap", "apply", "apple"]
- Result: "apple" (all prefixes: "a", "ap", "app", "appl", "apple" exist)

### Solution Approach:

- Insert all words in trie
- Use DFS to find longest word where all prefixes are marked as endOfWord
- Compare lexicographically for same length

```cpp
void longestHelper(Node* root, string &ans, string temp) {
    for (pair<char, Node*> child : root->children) {
        if (child.second->endOfWord) {
            temp += child.first;
            if ((temp.size() == ans.size() && temp < ans) ||
                (temp.size() > ans.size())) {
                ans = temp;
            }
            longestHelper(child.second, ans, temp);
            temp = temp.substr(0, temp.size()-1);
        }
    }
}
```

## Applications of Trie:

1. **Autocomplete Systems**: Suggest words based on prefix
2. **Spell Checkers**: Check if word exists in dictionary
3. **Word Break Problems**: Break text into valid words
4. **IP Routing**: Longest prefix matching in networking
5. **Dictionary Operations**: Fast prefix-based operations
6. **Text Compression**: Dictionary-based compression

## Time Complexity Analysis:

| Operation     | Time Complexity | Space Complexity |
| ------------- | --------------- | ---------------- |
| Insert        | O(L)            | O(L \* N)        |
| Search        | O(L)            | O(1)             |
| Starts With   | O(L)            | O(1)             |
| Word Break    | O(L \* N)       | O(L) recursion   |
| Unique Prefix | O(L)            | O(L \* N)        |

Where:

- L = Length of word/string
- N = Number of words in dictionary

## Key Advantages of Trie:

1. **Fast Prefix Operations**: All operations starting with prefix are fast
2. **Space Efficient**: Common prefixes share nodes
3. **No Hash Collisions**: Unlike hash tables
4. **Ordered Traversal**: Can traverse in lexicographical order

## Comparison with Other Data Structures:

| Feature           | Trie      | Hash Table | BST           |
| ----------------- | --------- | ---------- | ------------- |
| **Prefix Search** | O(L)      | O(L)       | O(L \* log N) |
| **Exact Search**  | O(L)      | O(L) avg   | O(L \* log N) |
| **Memory**        | O(L \* N) | O(L \* N)  | O(L \* N)     |
| **Ordered**       | Yes       | No         | Yes           |

## Common Interview Problems:

1. **Word Break**: Check if string can be segmented into dictionary words
2. **Unique Prefixes**: Find shortest unique prefix for each word
3. **Longest Word**: Find longest word where all prefixes exist
4. **Autocomplete**: Implement autocomplete functionality
5. **Spell Checker**: Check spelling and suggest corrections
6. **Count Distinct Substrings**: Count unique substrings in string

## Advanced Trie Applications:

1. **Suffix Trees**: Special trie for all suffixes of string
2. **Compressed Tries**: Reduce space by compressing single-child chains
3. **Ternary Search Trees**: Hybrid between trie and BST
4. **Multi-way Tries**: Each node can have more than 2 children

## Implementation Tips:

1. **Use unordered_map** for children to handle any character set
2. **Track frequency** for prefix-related problems
3. **Mark endOfWord** properly for complete word detection
4. **Handle memory management** carefully in C++
5. **Consider recursion depth** for very long strings
