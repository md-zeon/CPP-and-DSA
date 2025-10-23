# Day 25: Linked List Part 1 - Practice Problems

## Problem 1: Linked List Creation and Basic Operations

**Difficulty:** Easy

### Description

Create a singly linked list and implement basic operations like insertion at front and back.

### Input Format

- First line: number of elements to insert at front
- Next lines: elements to insert at front
- Next line: number of elements to insert at back
- Next lines: elements to insert at back

### Output Format

- Print the final linked list in the format: "data -> data -> ... -> NULL"

### Sample Input

```text
3
1
2
3
2
4
5
```

### Sample Output

```text
3 -> 2 -> 1 -> 4 -> 5 -> NULL
```

### Operations to Implement

1. `push_front(val)` - Insert element at the beginning
2. `push_back(val)` - Insert element at the end
3. `printList()` - Display the linked list

---

## Problem 2: Insert at Specific Position

**Difficulty:** Easy

### Description

Insert a new element at a specific position in the linked list.

### Input Format

- First line: number of elements for initial list
- Next lines: initial elements
- Next line: element to insert and position (format: "element position")

### Output Format

- Print the linked list before and after insertion

### Sample Input

```text
5
1
2
3
4
5
100 3
```

### Sample Output

```text
Original List: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
After Insertion: 1 -> 2 -> 100 -> 3 -> 4 -> 5 -> NULL
```

### Note

- Position is 1-based (1 = first position)
- Handle invalid positions gracefully

---

## Problem 3: Delete from Front and Back

**Difficulty:** Easy

### Description

Delete elements from the front and back of the linked list.

### Input Format

- First line: number of elements for initial list
- Next lines: initial elements
- Next line: number of front deletions
- Next line: number of back deletions

### Output Format

- Print the linked list after each deletion

### Sample Input

```text
5
1
2
3
4
5
2
1
```

### Sample Output

```text
After deleting 2 from front: 3 -> 4 -> 5 -> NULL
After deleting 1 from back: 3 -> 4 -> NULL
```

### Operations to Implement

1. `pop_front()` - Delete element from beginning
2. `pop_back()` - Delete element from end

---

## Problem 4: Search in Linked List

**Difficulty:** Easy

### Description

Search for an element in the linked list using both iterative and recursive approaches.

### Input Format

- First line: number of elements in linked list
- Next lines: elements for the linked list
- Next line: element to search

### Output Format

- Print the index (0-based) using iterative search
- Print the index (0-based) using recursive search
- Print -1 if element not found

### Sample Input

```text
6
1
2
100
3
4
5
100
```

### Sample Output

```text
Iterative Search: 2
Recursive Search: 2
```

### Sample Input (Not Found)

```text
6
1
2
3
4
5
6
100
```

### Sample Output

```text
Iterative Search: -1
Recursive Search: -1
```

---

## Problem 5: Reverse Linked List

**Difficulty:** Medium

### Description

Reverse the linked list using iterative approach (three pointers).

### Input Format

- First line: number of elements in linked list
- Next lines: elements for the linked list

### Output Format

- Print original linked list
- Print reversed linked list

### Sample Input

```text
5
1
2
3
4
5
```

### Sample Output

```text
Original List: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
Reversed List: 5 -> 4 -> 3 -> 2 -> 1 -> NULL
```

### Algorithm

1. Initialize prev = NULL, curr = head, next = NULL
2. While curr != NULL:
   - next = curr->next
   - curr->next = prev
   - prev = curr
   - curr = next
3. head = prev

### Time Complexity

- O(n) - traverse entire list once
- Space Complexity: O(1) - only three pointers

---

## Problem 6: Remove Nth Node from End

**Difficulty:** Medium

### Description

Remove the nth node from the end of the linked list.

### Input Format

- First line: number of elements in linked list
- Next lines: elements for the linked list
- Last line: n (1-based position from end)

### Output Format

- Print the linked list before and after removal

### Sample Input

```text
5
1
2
3
4
5
2
```

### Sample Output

```text
Original List: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
After Removing 2nd from end: 1 -> 2 -> 3 -> 5 -> NULL
```

### Algorithm

1. First pass: find the size of the linked list
2. Calculate position from beginning: size - n
3. Traverse to (size - n)th node
4. Remove that node

### Edge Cases

- n = 1 (remove last node)
- n = size (remove first node)
- n > size (invalid, do nothing)

---

## Additional Practice Problems

### Problem 7: Find Middle Element

Find the middle element of the linked list.

**Hint:** Use slow and fast pointer technique.

### Problem 8: Detect Cycle

Check if the linked list has a cycle.

### Problem 9: Find Length of Linked List

Calculate the total number of nodes in the linked list.

### Problem 10: Check if Linked List is Palindrome

Check if the linked list reads the same forwards and backwards.

### Problem 11: Remove Duplicates from Sorted Linked List

Remove duplicate elements from a sorted linked list.

### Problem 12: Merge Two Sorted Linked Lists

Merge two sorted linked lists into one sorted list.

### Problem 13: Find Intersection Point of Two Linked Lists

Find the node where two linked lists intersect (if they do).

### Problem 14: Swap Nodes in Pairs

Swap every two adjacent nodes in the linked list.

### Problem 15: Rotate Linked List

Rotate the linked list to the right by k positions.
