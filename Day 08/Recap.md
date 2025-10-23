# Day 08: Binary Number System

## Topics Covered

- **Binary to Decimal Conversion**: Converting binary numbers to decimal system
- **Decimal to Binary Conversion**: Converting decimal numbers to binary system
- **Positional Number Systems**: Understanding place values in different bases
- **Power Operations**: Using exponents for place value calculations
- **Number System Fundamentals**: Base-2 vs Base-10 systems

## Key Concepts

1. **Binary System**: Base-2 number system using only 0s and 1s
2. **Decimal System**: Base-10 number system (0-9 digits)
3. **Place Values**: Each position represents a power of the base
4. **Conversion Algorithms**: Step-by-step conversion between systems
5. **Power Calculation**: Using pow() function for mathematical operations

## Code Examples

### 1. Binary to Decimal Conversion

```cpp
int binaryToDecimal(int n) {
    int binaryNum = n;
    int decimalNum = 0;
    int power = 0;

    while(binaryNum != 0) {
        int lastDigit = binaryNum % 10;
        decimalNum += (lastDigit * (int)pow(2, power));
        power++;
        binaryNum /= 10;
    }
    return decimalNum;
}

// Example: 100 (binary) = 4 (decimal)
// Calculation: 1*2^2 + 0*2^1 + 0*2^0 = 4 + 0 + 0 = 4
```

### 2. Decimal to Binary Conversion

```cpp
int decimalToBinary(int n) {
    if(n == 0) {
        return 0;
    }

    int decimalNum = n;
    int binaryNum = 0;
    int power = 1;

    while(decimalNum > 0) {
        int remainder = decimalNum % 2;
        binaryNum += (remainder * power);
        decimalNum /= 2;
        power *= 10;
    }
    return binaryNum;
}

// Example: 4 (decimal) = 100 (binary)
// Calculation:
// 4 / 2 = 2 remainder 0 (least significant bit)
// 2 / 2 = 1 remainder 0
// 1 / 2 = 0 remainder 1 (most significant bit)
// Result: 100 (binary)
```

## Binary Number System Rules

### Binary to Decimal Formula:

```
Decimal = d₀ × 2⁰ + d₁ × 2¹ + d₂ × 2² + ... + dₙ × 2ⁿ
```

Where d₀, d₁, d₂, ... are the binary digits (0 or 1)

### Decimal to Binary Algorithm:

1. Divide the decimal number by 2
2. Record the remainder (0 or 1)
3. Divide the quotient by 2
4. Repeat until quotient is 0
5. Read remainders from bottom to top

## Key Takeaways

- **Binary Digits**: Only 0 and 1 are used in binary system
- **Place Values**: Each position represents a power of 2
- **Right to Left**: Binary digits are processed from right to left (LSB to MSB)
- **Power Growth**: Each position's value doubles from right to left
- **Conversion Direction**: Binary to decimal uses multiplication, decimal to binary uses division

## Common Mistakes to Avoid

- Forgetting that binary digits are processed from right to left
- Incorrect power calculation (should start from 0)
- Not handling the case when decimal number is 0
- Confusing the direction of conversion algorithms
- Forgetting to cast pow() return value to int

## Test Cases

- Binary 101 = Decimal 5 (1×2² + 0×2¹ + 1×2⁰)
- Binary 1111 = Decimal 15 (1×2³ + 1×2² + 1×2¹ + 1×2⁰)
- Decimal 7 = Binary 111 (7÷2=3 r1, 3÷2=1 r1, 1÷2=0 r1)
- Decimal 0 = Binary 0 (edge case)
