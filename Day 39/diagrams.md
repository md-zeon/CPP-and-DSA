# Day 39: Advanced Hashing Problems & Applications - Diagrams

## 1. Majority Element Flowchart

This shows finding majority elements (> n/3 times).

```mermaid
graph TD
    A[majorityElement] --> B[Create unordered_map for counts]
    B --> C[Loop through array, map[num]++]
    C --> D[Loop through map]
    D --> E{i.second > n/3?}
    E -->|Yes| F[Print i.first]
    E -->|No| G[Continue loop]
```

## 2. Valid Anagram Flowchart

This illustrates checking if two strings are anagrams.

```mermaid
graph TD
    A[validAnagram] --> B{s1.size() != s2.size()?}
    B -->|Yes| C[Return false]
    B -->|No| D[Create map for s1 frequencies]
    D --> E[Loop through s2, decrement map]
    E --> F{map[c] == 0?}
    F -->|Yes| G[map.erase(c)]
    F -->|No| H{map.count(c)?}
    H -->|Yes| I[Return false]
    H -->|No| J[Continue]
    I --> K[Return map.size() == 0]
```

## 3. Count Distinct Elements Flowchart

This depicts counting distinct elements.

```mermaid
graph TD
    A[countDistinct] --> B[Create unordered_set]
    B --> C[Loop through array]
    C --> D[set.insert(arr[i])]
    D --> E[Continue loop]
    E --> F[Print set.size()]
```

## 4. Union and Intersection Flowchart

This shows finding union and intersection of arrays.

```mermaid
graph TD
    A[unionAndIntersection] --> B[Create unordered_set for set1]
    B --> C[Loop through set2]
    C --> D{set.count(set2[i])?}
    D -->|Yes| E[intersection.insert(set2[i])]
    D -->|No| F[set.insert(set2[i])]
    E --> G[Continue loop]
    F --> G
```

## 5. Itinerary from Tickets Flowchart

This illustrates reconstructing itinerary.

```mermaid
graph TD
    A[findItinerary] --> B[Create unordered_set for destinations]
    B --> C[Find starting point (not in destinations)]
    C --> D[Print start]
    D --> E{map.count(start)?}
    E -->|Yes| F[Print map[start], start = map[start]]
    E -->|No| G[Done]
    F --> H[Continue loop]
```

## 6. Largest Subarray with Zero Sum Flowchart

This depicts finding largest zero-sum subarray.

```mermaid
graph TD
    A[largestSubArrayWithZeroSum] --> B[Initialize map, sum=0, ans=0]
    B --> C[Loop through array]
    C --> D[sum += arr[j]]
    D --> E{sum == 0?}
    E -->|Yes| F[ans = max(ans, j+1)]
    E -->|No| G{map.count(sum)?}
    G -->|Yes| H[ans = max(ans, j - map[sum])]
    G -->|No| I[map[sum] = j]
    H --> J[Continue loop]
    I --> J
```

## 7. Count Subarrays with Sum K Flowchart

This shows counting subarrays with sum K.

```mermaid
graph TD
    A[subArrayCountWithK] --> B[Initialize map, sum=0, ans=0]
    B --> C[Loop through array]
    C --> D[sum += arr[j]]
    D --> E{sum == k?}
    E -->|Yes| F[ans++]
    E -->|No| G{map.count(sum - k)?}
    G -->|Yes| H[ans += map[sum - k]]
    G -->|No| I[map[sum]++]
    H --> J[Continue loop]
    I --> J
```

## Notes

- These diagrams use Mermaid syntax for GitHub compatibility.
- Flowcharts visualize advanced hashing techniques.
- For majority and anagram, frequency maps are key.
- For distinct and union, sets handle uniqueness.
- For itinerary, maps represent graph edges.
- For subarray problems, prefix sums are essential.
- Use these to understand hashing applications.
