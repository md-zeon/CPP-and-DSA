# Day 14: Character Arrays and Strings

## Topics Covered

- **Character Arrays**: C-style strings using char arrays
- **String Input/Output**: Using cin, getline for string input
- **String Manipulation**: Case conversion, reversal, palindrome check
- **C++ String Class**: Modern string handling with std::string
- **String Member Functions**: Built-in string operations
- **Anagram Detection**: Checking if two strings are anagrams

## Key Concepts

1. **C-Style Strings**: Null-terminated character arrays
2. **String Length**: Using strlen() vs string.length()
3. **String Operations**: Case conversion, reversal, comparison
4. **C++ Strings**: Dynamic strings with member functions
5. **Frequency Arrays**: For character counting and anagram detection

## Code Examples

### 1. Character Array Input and Length

```cpp
char word[30];
cin >> word;
cout << "Word: " << word << endl;
cout << "Length: " << strlen(word) << endl;

// For sentences with spaces
char sentence[100];
cin.getline(sentence, 100);
cout << "Sentence: " << sentence << endl;
```

### 2. Case Conversion Functions

```cpp
void convertToUppercase(char word[]) {
    for(int i = 0; i < strlen(word); i++) {
        if(word[i] >= 'a' && word[i] <= 'z') {
            word[i] = word[i] - 'a' + 'A';
        }
    }
}

void convertToLowercase(char word[]) {
    for(int i = 0; i < strlen(word); i++) {
        if(word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = word[i] - 'A' + 'a';
        }
    }
}
```

### 3. String Reversal

```cpp
void reverse(char word[], int n) {
    int st = 0, end = n-1;
    while(st < end) {
        swap(word[st], word[end]);
        st++;
        end--;
    }
}
```

### 4. Palindrome Check

```cpp
bool isPalindrome(char word[], int n) {
    int st = 0, end = n-1;
    while(st < end) {
        if(word[st++] != word[end--]) {
            return false;
        }
    }
    return true;
}
```

### 5. C++ String Class Usage

```cpp
string str = "hello";
cout << str << endl;

// Member functions
cout << str.length() << endl;           // Length of string
cout << str.at(3) << endl;              // Character at index
cout << str.substr(5, 7) << endl;       // Substring
cout << str.find("college") << endl;    // Find substring

// For-each loop with strings
for(char ch : str) {
    cout << ch << " ";
}
```

### 6. Anagram Detection

```cpp
bool isAnagram(string str1, string str2) {
    if(str1.length() != str2.length()) {
        return false;
    }

    int count[26] = {0};

    // Count frequency of characters in str1
    for(int i = 0; i < str1.length(); i++) {
        int idx = str1[i] - 'a';
        count[idx]++;
    }

    // Decrement frequency for str2
    for(int i = 0; i < str2.length(); i++) {
        int idx = str2[i] - 'a';
        count[idx]--;
        if(count[idx] < 0) {
            return false;
        }
    }

    return true;
}
```

## C vs C++ Strings

### C-Style Strings (char arrays)

- **Declaration**: `char str[100]`
- **Null-terminated**: Must end with '\0'
- **Fixed size**: Cannot grow dynamically
- **Functions**: `strlen()`, `strcpy()`, `strcat()`, `strcmp()`
- **Memory**: Stored in stack or global memory

### C++ Strings (std::string)

- **Declaration**: `string str`
- **Dynamic**: Can grow and shrink
- **Member functions**: `.length()`, `.at()`, `.substr()`, `.find()`
- **Operators**: `+`, `==`, `>`, `<`, etc.
- **Memory**: Managed automatically

## Key Takeaways

- **Null Terminator**: C-strings must end with '\0'
- **Buffer Overflow**: Be careful with array bounds in C-strings
- **String Length**: Use `strlen()` for C-strings, `.length()` for C++ strings
- **Case Conversion**: ASCII values differ by 32 between upper and lower case
- **Frequency Counting**: Use arrays of size 26 for lowercase letters
- **String Comparison**: Use `strcmp()` for C-strings, `==` for C++ strings

## Common Mistakes to Avoid

- Forgetting null terminator in C-strings
- Buffer overflow when using cin with char arrays
- Using `sizeof()` instead of `strlen()` for string length
- Not checking string lengths before operations
- Mixing C-strings and C++ strings incorrectly

## String Functions Reference

### C-String Functions (<cstring>)

- `strlen(str)`: Returns length of string
- `strcpy(dest, src)`: Copies src to dest
- `strcat(str1, str2)`: Concatenates str2 to str1
- `strcmp(str1, str2)`: Compares two strings

### C++ String Member Functions

- `str.length()`: Returns length of string
- `str.at(index)`: Returns character at index
- `str.substr(start, length)`: Returns substring
- `str.find(substring)`: Returns index of first occurrence
- `str.empty()`: Checks if string is empty
- `str.clear()`: Clears the string

## ASCII Value Manipulation

- **Upper to Lower**: `char lower = upper + 32;`
- **Lower to Upper**: `char upper = lower - 32;`
- **Character to Index**: `int index = ch - 'a';` (for lowercase)
- **Index to Character**: `char ch = index + 'a';`
