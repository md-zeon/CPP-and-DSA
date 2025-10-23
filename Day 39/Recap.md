# Day 39: Advanced Hashing Problems & Applications

## Topics Covered

- Majority Element Problem
- String Anagram Validation
- Set Operations (Union & Intersection)
- Itinerary Planning
- Subarray Problems with Hashing
- Prefix Sum Technique

## 1. Majority Element Problem

### Problem:

Find all elements that appear more than `n/3` times in an array.

### Solution Approach:

- Use hash map to count frequency of each element
- Iterate through map to find elements with count > n/3

```cpp
void majorityElement(vector<int> elements) {
    unordered_map<int, int> map;
    for (auto num : elements) {
        map[num]++;
    }

    for (auto i : map) {
        if (i.second > elements.size() / 3) {
            cout << i.first << " ";
        }
    }
}
```

### Time Complexity: O(n)

### Space Complexity: O(n)

## 2. Valid Anagram Problem

### Problem:

Check if two strings are valid anagrams of each other.

### Solution Approach:

- Use hash map to count character frequencies in first string
- Decrement counts while traversing second string
- Check if all counts become zero

```cpp
bool validAnagram(string s1, string s2) {
    if (s1.size() != s2.size()) return false;

    unordered_map<char, int> map;
    for (char c : s1) map[c]++;

    for (char c : s2) {
        if (map.count(c)) {
            map[c]--;
            if (map[c] == 0) map.erase(c);
        } else {
            return false;
        }
    }

    return map.size() == 0;
}
```

### Time Complexity: O(n)

### Space Complexity: O(k) where k is distinct characters

## 3. Count Distinct Elements

### Problem:

Count and display distinct elements in an array.

### Solution Approach:

- Use unordered_set to store unique elements
- Set automatically handles duplicates

```cpp
void countDistinct(vector<int> arr) {
    unordered_set<int> set;
    for (int i = 0; i < arr.size(); i++) {
        set.insert(arr[i]);
    }
    cout << "Distinct = " << set.size() << endl;
}
```

## 4. Union and Intersection of Arrays

### Problem:

Find union and intersection of two arrays.

### Solution Approach:

- Use unordered_set for union (all unique elements)
- Track intersection elements that appear in both arrays

```cpp
void printUnionAndIntersection(vector<int> set1, vector<int> set2) {
    unordered_set<int> set;
    unordered_set<int> intersection;

    // Insert all elements from set1
    for (int i = 0; i < set1.size(); i++) {
        set.insert(set1[i]);
    }

    // Process set2
    for (int i = 0; i < set2.size(); i++) {
        if (set.count(set2[i])) {
            intersection.insert(set2[i]);
        } else {
            set.insert(set2[i]);
        }
    }
}
```

## 5. Itinerary from Tickets

### Problem:

Given a list of flight tickets, find the complete travel itinerary.

### Solution Approach:

- Use unordered_set to find all destination cities
- Find starting point (city that doesn't appear as destination)
- Follow the chain using map lookup

```cpp
void findItinerary(unordered_map<string, string> tickets) {
    // Find starting point
    unordered_set<string> to;
    for (auto ticket : tickets) {
        to.insert(ticket.second);
    }

    string start = "";
    for (auto ticket : tickets) {
        if (to.find(ticket.first) == to.end()) {
            start = ticket.first;
        }
    }

    // Print itinerary
    cout << start << " -> ";
    while (tickets.count(start)) {
        cout << tickets[start] << " -> ";
        start = tickets[start];
    }
}
```

## 6. Largest Subarray with Zero Sum

### Problem:

Find length of largest subarray with sum equal to zero.

### Solution Approach (Prefix Sum Technique):

- Maintain running sum and store first occurrence index
- When same sum appears again, calculate subarray length
- Update maximum length found

```cpp
int largestSubArrayWithZeroSum(vector<int> arr) {
    unordered_map<int, int> map; // sum, first_occurrence_index
    int sum = 0;
    int ans = 0;

    for (int j = 0; j < arr.size(); j++) {
        sum += arr[j];
        if (sum == 0) {
            ans = max(ans, j + 1);
        } else if (map.count(sum)) {
            int currLen = j - map[sum];
            ans = max(ans, currLen);
        } else {
            map[sum] = j;
        }
    }

    return ans;
}
```

## 7. Count Subarrays with Sum K

### Problem:

Count number of subarrays with sum equal to K.

### Solution Approach:

- Use prefix sum technique with count of each sum
- For each sum, add count of (sum - K) to answer
- Maintain frequency of each prefix sum

```cpp
int subArrayCountWithK(vector<int> arr, int k) {
    unordered_map<int, int> m; // sum, count
    int sum = 0;
    int ans = 0;

    for (int j = 0; j < arr.size(); j++) {
        sum += arr[j];

        // Subarray from 0 to j has sum K
        if (sum == k) ans++;

        // Subarrays from i+1 to j have sum K
        if (m.count(sum - k)) {
            ans += m[sum - k];
        }

        m[sum]++;
    }

    return ans;
}
```

## Key Hashing Techniques:

### 1. Frequency Counting

- Use unordered_map for element frequency
- Useful for majority element, anagrams, etc.

### 2. Prefix Sum Technique

- Store cumulative sums in hash map
- Find subarrays with specific sum properties
- Handle zero-sum and K-sum subarrays

### 3. Set Operations

- Use unordered_set for unique elements
- Efficient union, intersection, difference operations

### 4. Graph Traversal (Itinerary)

- Use maps to represent graph edges
- Find starting point and traverse path

## Applications of Advanced Hashing:

1. **Majority Element**: Election results, frequent items
2. **Anagram Detection**: Text processing, plagiarism detection
3. **Set Operations**: Database operations, data analysis
4. **Itinerary Planning**: Travel booking systems, route planning
5. **Subarray Problems**: Financial analysis, signal processing
6. **Prefix Sum**: Cumulative calculations, range queries

## Time & Space Complexity:

| Problem            | Time   | Space  |
| ------------------ | ------ | ------ |
| Majority Element   | O(n)   | O(n)   |
| Valid Anagram      | O(n)   | O(k)   |
| Count Distinct     | O(n)   | O(n)   |
| Union/Intersection | O(n+m) | O(n+m) |
| Itinerary          | O(n)   | O(n)   |
| Zero Sum Subarray  | O(n)   | O(n)   |
| K Sum Subarrays    | O(n)   | O(n)   |

## Common Patterns:

1. **Frequency Maps**: Count occurrences of elements
2. **Prefix Sums**: Track cumulative sums for subarray problems
3. **Set Operations**: Use sets for unique elements and membership testing
4. **Graph Representation**: Use maps to represent directed graphs

## Interview Problems:

- Find majority element (> n/3 times)
- Check if two strings are anagrams
- Find union and intersection of arrays
- Reconstruct itinerary from tickets
- Largest subarray with sum zero
- Count subarrays with sum K
- Longest substring without repeating characters
