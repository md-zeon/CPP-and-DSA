# Day 29: Queues and Deque - Diagrams

## 1. Queue Using Two Stacks Flowchart

This shows implementing a queue using two stacks.

```mermaid
graph TD
    A[push(data)] --> B[While !s1.empty()]
    B --> C[s2.push(s1.top()), s1.pop()]
    C --> D[s1.push(data)]
    D --> E[While !s2.empty()]
    E --> F[s1.push(s2.top()), s2.pop()]
    F --> G[pop(): s1.pop()]
    G --> H[front(): s1.top()]
```

## 2. Stack Using Two Queues Flowchart

This illustrates implementing a stack using two queues.

```mermaid
graph TD
    A[push(data)] --> B[While !q1.empty()]
    B --> C[q2.push(q1.front()), q1.pop()]
    C --> D[q1.push(data)]
    D --> E[While !q2.empty()]
    E --> F[q1.push(q2.front()), q2.pop()]
    F --> G[pop(): q1.pop()]
    G --> H[top(): q1.front()]
```

## 3. First Non-Repeating Character Flowchart

This depicts finding the first non-repeating character.

```mermaid
graph TD
    A[firstNonRepeating] --> B[Initialize Q, freq[26]=0]
    B --> C[Loop through each char]
    C --> D[Q.push(ch), freq[ch-'a']++]
    D --> E[While !Q.empty() and freq[Q.front()-'a'] > 1]
    E --> F[Q.pop()]
    F --> G{Q.empty()?}
    G -->|Yes| H[Print -1]
    G -->|No| I[Print Q.front()]
```

## 4. Queue Interleaving Flowchart

This shows interleaving queue elements.

```mermaid
graph TD
    A[interLeaveTwoQueues] --> B[Move first half to another queue]
    B --> C[While !first.empty()]
    C --> D[org.push(first.front()), first.pop()]
    D --> E[org.push(org.front()), org.pop()]
    E --> F[Continue until first.empty()]
```

## 5. Queue Reversal Flowchart

This illustrates reversing a queue using a stack.

```mermaid
graph TD
    A[reverseQueue] --> B[While !q.empty()]
    B --> C[s.push(q.front()), q.pop()]
    C --> D[While !s.empty()]
    D --> E[q.push(s.top()), s.pop()]
    E --> F[Queue is now reversed]
```

## 6. Deque Operations Flowchart

This shows basic deque operations.

```mermaid
graph TD
    A[Deque Operations] --> B[push_front: Add to front]
    B --> C[push_back: Add to back]
    C --> D[pop_front: Remove from front]
    D --> E[pop_back: Remove from back]
    E --> F[front: Access first element]
    F --> G[back: Access last element]
    G --> H[All O(1) operations]
```

## Notes

- These diagrams use Mermaid syntax for GitHub compatibility.
- Flowcharts visualize the FIFO behavior and operations.
- For two-stack implementations, note the transfer steps.
- For first non-repeating, the queue and frequency array are key.
- For interleaving and reversal, auxiliary data structures are used.
- Use these to understand queue-based problem-solving patterns.
