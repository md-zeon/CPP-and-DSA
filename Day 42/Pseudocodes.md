# 📝 Pseudocodes: Graphs

## 🎯 Purpose

Pseudocode provides a high-level description of algorithms for Graphs without worrying about syntax.

## 📚 What is Pseudocode?

Pseudocode uses:
- Plain English with programming structure
- Logical flow without syntax constraints
- Focus on algorithm logic

## 🔍 Main Algorithms

### Algorithm 1: Basic Implementation

```
ALGORITHM BasicAlgorithm
INPUT: data
OUTPUT: result

BEGIN
    INITIALIZE variables
    
    FOR each element IN data
        PROCESS element
        UPDATE state
    END FOR
    
    RETURN result
END
```

**Complexity:**
- Time: O(n)
- Space: O(1)

### Algorithm 2: Optimized Approach

```
ALGORITHM OptimizedAlgorithm
INPUT: arr[], n
OUTPUT: optimized_result

BEGIN
    IF n == 0 THEN
        RETURN null
    END IF
    
    SET left = 0
    SET right = n - 1
    
    WHILE left < right DO
        IF condition THEN
            INCREMENT left
        ELSE
            DECREMENT right
        END IF
    END WHILE
    
    RETURN result
END
```

## 🎯 Helper Functions

### Helper Function

```
FUNCTION helper(param)
BEGIN
    IF base_condition THEN
        RETURN base_value
    END IF
    
    COMPUTE result
    RETURN result
END FUNCTION
```

## 🔄 Common Patterns

### Pattern 1: Two Pointers

```
SET left = 0
SET right = length - 1

WHILE left < right DO
    PROCESS elements
    UPDATE pointers
END WHILE
```

### Pattern 2: Sliding Window

```
SET start = 0
SET sum = 0

FOR end = 0 TO n-1 DO
    ADD arr[end] to sum
    
    WHILE sum >= target DO
        UPDATE result
        SUBTRACT arr[start]
        INCREMENT start
    END WHILE
END FOR
```

### Pattern 3: Recursion

```
FUNCTION recursive(n)
BEGIN
    IF n == 0 THEN
        RETURN base_value
    END IF
    
    RETURN operation(recursive(n-1))
END FUNCTION
```

## 🔍 Edge Cases

```
ALGORITHM HandleEdgeCases(input)
BEGIN
    IF input is NULL THEN
        RETURN default
    END IF
    
    IF size == 1 THEN
        RETURN single_element_case
    END IF
    
    PROCEED with main logic
END
```

## 💡 Tips for Pseudocode

1. **Keep it simple** - Focus on logic
2. **Be consistent** - Use same style
3. **Comment complex parts**
4. **Use proper indentation**
5. **Test with examples**

---
📅 *Last Updated: October 22, 2025*
