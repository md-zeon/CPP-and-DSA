# Day 38: Hashing & Hash Tables

## Topics Covered

- Custom Hash Table Implementation
- Hash Collisions & Chaining
- STL Map & Unordered Map
- STL Set & Unordered Set
- Two Sum Problem using Hashing

## 1. Custom Hash Table Implementation

### Key Components:

- **Node Class**: Stores key-value pairs with next pointer for chaining
- **HashTable Class**: Implements hash table with dynamic resizing
- **Hash Function**: Converts string keys to indices using polynomial rolling hash

### Hash Function:

```cpp
int hashFunction(string key) {
    int idx = 0;
    for (int i = 0; i < key.size(); i++) {
        idx = idx + (key[i] * key[i]) % totalSize;
    }
    return idx % totalSize;
}
```

### Collision Resolution - Chaining:

- Each bucket contains a linked list of key-value pairs
- New nodes are inserted at the beginning of the chain
- Handles collisions by maintaining multiple entries per bucket

## 2. Dynamic Resizing (Rehashing)

### Load Factor Management:

```cpp
double lambda = currentSize / (double)totalSize;
if (lambda > 1) {
    rehash();
}
```

### Rehashing Process:

1. Create new table with double the size
2. Re-insert all existing elements using new hash function
3. Delete old table and update references

### Time Complexity:

- **Average Case**: O(1) for insert, search, delete
- **Worst Case**: O(n) when λ > 1 (rehashing required)

## 3. STL Map vs Unordered Map

### Map (Ordered Map):

- **Implementation**: Red-Black Tree (self-balancing BST)
- **Ordering**: Keys are stored in sorted order
- **Operations**: O(log n) for insert, search, delete
- **Use Case**: When ordered traversal is needed

```cpp
map<string, int> m;
m["India"] = 150;  // Keys stored in sorted order
```

### Unordered Map (Hash Map):

- **Implementation**: Hash table with chaining
- **Ordering**: No specific order guarantee
- **Operations**: O(1) average case, O(n) worst case
- **Use Case**: Fast lookups without ordering requirement

```cpp
unordered_map<string, int> m;
m["India"] = 150;  // No ordering guarantee
```

## 4. STL Set vs Unordered Set

### Set (Ordered Set):

- **Implementation**: Red-Black Tree
- **Properties**: Unique elements in sorted order
- **Operations**: O(log n) for insert, search, delete
- **Use Case**: When ordered unique elements needed

```cpp
set<int> s;
s.insert(1);  // Duplicates automatically ignored
```

### Unordered Set (Hash Set):

- **Implementation**: Hash table
- **Properties**: Unique elements, no specific order
- **Operations**: O(1) average case, O(n) worst case
- **Use Case**: Fast membership testing

```cpp
unordered_set<int> s;
s.insert(1);  // Duplicates automatically ignored
```

## 5. Two Sum Problem - Hashing Approach

### Problem:

Find two indices in array such that `arr[i] + arr[j] = target`

### Hashing Solution:

```cpp
unordered_map<int, int> m;
for (int i = 0; i < arr.size(); i++) {
    if (m.count(target - arr[i])) {
        cout << "ANS = [" << m[target - arr[i]] << ", " << i << "]" << endl;
        break;
    } else {
        m[arr[i]] = i;
    }
}
```

### Time Complexity: O(n)

### Space Complexity: O(n)

## Key Operations & Methods:

### Hash Table Operations:

- `insert(key, value)`: Insert key-value pair
- `search(key)`: Find value for given key
- `exists(key)`: Check if key exists
- `remove(key)`: Delete key-value pair

### STL Container Methods:

- `insert()`: Add element
- `erase()`: Remove element
- `find()`: Search for element
- `count()`: Count occurrences (0 or 1 for sets)
- `size()`: Get number of elements

## Hash Table vs BST Comparison:

| Feature    | Hash Table           | BST (Map/Set) |
| ---------- | -------------------- | ------------- |
| **Order**  | Unordered            | Ordered       |
| **Insert** | O(1) avg, O(n) worst | O(log n)      |
| **Search** | O(1) avg, O(n) worst | O(log n)      |
| **Delete** | O(1) avg, O(n) worst | O(log n)      |
| **Memory** | More due to buckets  | Less overhead |

## Applications of Hashing:

1. **Databases**: Fast record lookup
2. **Caches**: Quick data retrieval
3. **Symbol Tables**: Compiler design
4. **Dictionaries**: Word frequency counting
5. **Duplicate Detection**: Finding repeated elements
6. **Two Sum Problems**: Finding pairs with target sum

## Best Practices:

1. **Choose appropriate data structure** based on requirements
2. **Handle collisions** properly (chaining vs open addressing)
3. **Monitor load factor** for hash table performance
4. **Use STL containers** when possible for production code
5. **Consider worst-case scenarios** for hash table operations

## Common Interview Problems:

- Two Sum (Hashing approach)
- Subarray with zero sum
- Largest subarray with equal 0s and 1s
- Count distinct elements in window
- Find first repeating element
