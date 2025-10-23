# Day 16: Bit Manipulation

## Topics Covered

- **Bitwise Operators**: AND, OR, XOR, NOT operations
- **Bit Shifting**: Left shift (multiplication) and right shift (division)
- **Bit Checking**: Getting, setting, and clearing individual bits
- **Power of 2**: Checking if a number is power of 2
- **Bit Updates**: Modifying specific bits in numbers
- **Set Bit Counting**: Counting 1s in binary representation
- **Fast Exponentiation**: Efficient power calculation using bits

## Key Concepts

1. **Binary Representation**: Understanding numbers in base-2
2. **Bit Operations**: Direct manipulation of binary digits
3. **Bit Masks**: Using powers of 2 for bit operations
4. **Bit Shifting**: Efficient multiplication and division by 2
5. **Binary Properties**: Leveraging binary characteristics for optimization

## Code Examples

### 1. Basic Bitwise Operations

```cpp
// Bitwise AND (&) - Sets bit if both bits are 1
cout << (3 & 5) << endl;  // 0011 & 0101 = 0001 (1)

// Bitwise OR (|) - Sets bit if either bit is 1
cout << (3 | 5) << endl;  // 0011 | 0101 = 0111 (7)

// Bitwise XOR (^) - Sets bit if bits are different
cout << (3 ^ 5) << endl;  // 0011 ^ 0101 = 0110 (6)

// Bitwise NOT (~) - Flips all bits
cout << (~6) << endl;     // ~0110 = 1001 (in 2's complement)
```

### 2. Bit Shifting Operations

```cpp
// Left Shift (<<) - Equivalent to multiplication by 2^n
cout << (7 << 2) << endl;  // 0111 << 2 = 11100 (28) = 7 * 4

// Right Shift (>>) - Equivalent to division by 2^n
cout << (7 >> 2) << endl;  // 0111 >> 2 = 0001 (1) = 7 / 4
```

### 3. Check Odd/Even using Bit Manipulation

```cpp
void oddOrEven(int num) {
    if(num & 1) {
        cout << "Odd" << endl;
    } else {
        cout << "Even" << endl;
    }
}

// Principle: Even numbers end with 0, odd numbers end with 1
// Any number & 1 gives the least significant bit
```

### 4. Get ith Bit

```cpp
int getIthBit(int num, int pos) {
    int bitMask = 1 << pos;

    if(!(num & bitMask)) {
        return 0;
    } else {
        return 1;
    }
}

// Example: getIthBit(6, 1) -> 6 in binary is 110, 1st bit is 1
// 6 & (1 << 1) = 110 & 010 = 010 (true)
```

### 5. Set ith Bit

```cpp
int setIthBit(int num, int pos) {
    int bitMask = 1 << pos;
    return num | bitMask;
}

// Example: setIthBit(6, 0) -> 6 | 1 = 7 (111 in binary)
// Sets the bit at position 'pos' to 1
```

### 6. Clear ith Bit

```cpp
int clearIthBit(int num, int pos) {
    int bitMask = ~(1 << pos);
    return num & bitMask;
}

// Example: clearIthBit(7, 0) -> 7 & ~1 = 111 & 110 = 110 (6)
// Sets the bit at position 'pos' to 0
```

### 7. Check Power of 2

```cpp
bool isPowerOf2(int num) {
    if(num & (num-1)) {
        return false;
    } else {
        return true;
    }
}

// Power of 2 in binary: 1, 10, 100, 1000, etc.
// Power of 2 - 1: 0, 1, 11, 111, etc.
// Power of 2 & (Power of 2 - 1) = 0
```

### 8. Update ith Bit

```cpp
void updateIthBit(int num, int i, int val) {
    num = num & ~(1 << i); // Clear ith bit
    num = num | (val << i); // Set ith bit to val
    cout << num << endl;
}

// Example: updateIthBit(7, 1, 0) -> Clear bit 1: 101, Result: 5
```

### 9. Clear Last i Bits

```cpp
void clearIBits(int num, int i) {
    int bitMask = (~0) << i;
    num = num & bitMask;
    cout << num << endl;
}

// Example: clearIBits(15, 2) -> 15 is 1111, clear last 2 bits: 1100 (12)
// (~0) << 2 = 11111100, 1111 & 11111100 = 1100
```

### 10. Count Set Bits (Brian Kernighan Algorithm)

```cpp
void countSetBits(int num) {
    int count = 0;
    while(num > 0) {
        int lastDigit = num & 1;
        count += lastDigit;
        num = num >> 1;
    }
    cout << count << endl;
}

// Example: 10 in binary is 1010, set bits: 2
// More efficient: while(num) { count++; num &= (num-1); }
```

### 11. Fast Exponentiation

```cpp
void fastExpo(int x, int n) {
    int ans = 1;

    while(n > 0) {
        int lastBit = n & 1;
        if(lastBit) {
            ans *= x;
        }
        x = x * x;
        n = n >> 1;
    }

    cout << ans << endl;
}

// Example: 3^4 = 81
// Binary of 4: 100, so only multiply by 3^4 (since 2^2 bit is set)
```

## Bit Manipulation Tricks

### Check if Number is Odd/Even

```cpp
if(num & 1) // Odd
if(!(num & 1)) // Even
```

### Get/Set/Clear Bit

```cpp
// Get: (num & (1 << pos)) != 0
// Set: num | (1 << pos)
// Clear: num & ~(1 << pos)
```

### Power of 2 Check

```cpp
if(!(num & (num-1)) && num > 0) // Power of 2
```

### Multiply/Divide by 2

```cpp
num << 1;  // Multiply by 2
num >> 1;  // Divide by 2 (integer division)
```

## Key Takeaways

- **Bit Operations**: Much faster than arithmetic operations
- **Bit Masks**: Use powers of 2 (1, 2, 4, 8, 16...) for bit manipulation
- **Left Shift**: Equivalent to multiplication by 2^n
- **Right Shift**: Equivalent to division by 2^n
- **Bit Counting**: Brian Kernighan algorithm is most efficient
- **Fast Exponentiation**: O(log n) time complexity

## Common Mistakes to Avoid

- Forgetting that bit positions start from 0 (rightmost bit)
- Using signed vs unsigned integers for bit operations
- Not handling edge cases (negative numbers, zero)
- Confusing left and right shift operations
- Forgetting operator precedence in complex expressions

## Applications of Bit Manipulation

- **Flags and Permissions**: Using bits to represent multiple boolean values
- **Graphics Programming**: Pixel manipulation, color channels
- **Networking**: IP addresses, subnet masks
- **Cryptography**: Bit-level encryption algorithms
- **Embedded Systems**: Memory-constrained environments
- **Performance Optimization**: Replacing expensive operations with bit operations

## Time Complexities

- **Bit Operations**: O(1) - constant time
- **Set Bit Counting**: O(number of set bits) - usually much faster than O(log n)
- **Fast Exponentiation**: O(log n) - logarithmic time
