# Day 14: Character Arrays and Strings - Practice Problems

## Problem 1: String Input and Length

**Difficulty:** Easy

### Description

Take a string input and calculate its length.

### Input Format

- A single string (word)

### Output Format

- Print the string and its length

### Sample Input

```
hello
```

### Sample Output

```
String: hello
Length: 5
```

### Code Example

```cpp
char str[100];
cin >> str;
cout << "String: " << str << endl;
cout << "Length: " << strlen(str) << endl;
```

### Constraints

- String length ≤ 100

---

## Problem 2: Sentence Input with Spaces

**Difficulty:** Easy

### Description

Take a sentence input (including spaces) and calculate its length.

### Input Format

- A sentence (may contain spaces)

### Output Format

- Print the sentence and its length

### Sample Input

```
Hello World
```

### Sample Output

```
Sentence: Hello World
Length: 11
```

### Code Example

```cpp
char sentence[100];
cin.getline(sentence, 100);
cout << "Sentence: " << sentence << endl;
cout << "Length: " << strlen(sentence) << endl;
```

### Constraints

- Sentence length ≤ 100

---

## Problem 3: Convert to Uppercase

**Difficulty:** Easy

### Description

Convert all lowercase letters in a string to uppercase.

### Input Format

- A string `word`

### Output Format

- Print the string in uppercase

### Sample Input

```
hello world
```

### Sample Output

```
HELLO WORLD
```

### Algorithm

```cpp
void convertToUppercase(char word[]) {
    for(int i = 0; i < strlen(word); i++) {
        if(word[i] >= 'a' && word[i] <= 'z') {
            word[i] = word[i] - 'a' + 'A';
        }
    }
}
```

### Constraints

- String length ≤ 100

---

## Problem 4: Convert to Lowercase

**Difficulty:** Easy

### Description

Convert all uppercase letters in a string to lowercase.

### Input Format

- A string `word`

### Output Format

- Print the string in lowercase

### Sample Input

```
HELLO WORLD
```

### Sample Output

```
hello world
```

### Algorithm

```cpp
void convertToLowercase(char word[]) {
    for(int i = 0; i < strlen(word); i++) {
        if(word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = word[i] - 'A' + 'a';
        }
    }
}
```

### Constraints

- String length ≤ 100

---

## Problem 5: Reverse a String

**Difficulty:** Easy

### Description

Reverse a given string.

### Input Format

- A string `word`

### Output Format

- Print the reversed string

### Sample Input

```
hello
```

### Sample Output

```
olleh
```

### Algorithm

```cpp
void reverse(char word[], int n) {
    int start = 0, end = n-1;
    while(start < end) {
        swap(word[start], word[end]);
        start++;
        end--;
    }
}
```

### Constraints

- String length ≤ 100

---

## Problem 6: Check Palindrome

**Difficulty:** Easy

### Description

Check if a given string is a palindrome.

### Input Format

- A string `word`

### Output Format

- Print "Palindrome" or "Not Palindrome"

### Sample Input 1

```
racecar
```

### Sample Output 1

```
Palindrome
```

### Sample Input 2

```
hello
```

### Sample Output 2

```
Not Palindrome
```

### Algorithm

```cpp
bool isPalindrome(char word[], int n) {
    int start = 0, end = n-1;
    while(start < end) {
        if(word[start] != word[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
```

### Constraints

- String length ≤ 100

---

## Problem 7: Check Anagram

**Difficulty:** Medium

### Description

Check if two strings are anagrams of each other.

### Input Format

- Two strings `str1` and `str2`

### Output Format

- Print "Anagrams" or "Not Anagrams"

### Sample Input

```
listen silent
```

### Sample Output

```
Anagrams
```

### Algorithm

1. Check if lengths are equal
2. Use frequency array for character count
3. Compare frequency arrays

### Code Example

```cpp
bool isAnagram(string str1, string str2) {
    if(str1.length() != str2.length()) {
        return false;
    }

    int count[26] = {0};
    for(char ch : str1) {
        count[ch - 'a']++;
    }

    for(char ch : str2) {
        count[ch - 'a']--;
        if(count[ch - 'a'] < 0) {
            return false;
        }
    }

    return true;
}
```

### Constraints

- String length ≤ 100

---

## Problem 8: String Copy

**Difficulty:** Easy

### Description

Copy one string to another using C-style strings.

### Input Format

- Source string

### Output Format

- Print original and copied string

### Sample Input

```
hello
```

### Sample Output

```
Original: hello
Copied: hello
```

### Code Example

```cpp
char source[] = "hello";
char destination[100];
strcpy(destination, source);
```

### Constraints

- String length ≤ 100

---

## Problem 9: String Concatenation

**Difficulty:** Easy

### Description

Concatenate two strings using C-style strings.

### Input Format

- Two strings `str1` and `str2`

### Output Format

- Print concatenated string

### Sample Input

```
hello world
```

### Sample Output

```
helloworld
```

### Code Example

```cpp
char str1[] = "hello";
char str2[] = "world";
strcat(str1, str2);
```

### Constraints

- Total length ≤ 100

---

## Problem 10: String Comparison

**Difficulty:** Easy

### Description

Compare two strings using strcmp function.

### Input Format

- Two strings `str1` and `str2`

### Output Format

- Print comparison result

### Sample Input

```
apple banana
```

### Sample Output

```
apple comes before banana
```

### Code Example

```cpp
int result = strcmp(str1, str2);
if(result < 0) {
    cout << str1 << " comes before " << str2 << endl;
} else if(result > 0) {
    cout << str2 << " comes before " << str1 << endl;
} else {
    cout << "Strings are equal" << endl;
}
```

### Constraints

- String length ≤ 100

---

## Problem 11: C++ String Length

**Difficulty:** Easy

### Description

Use C++ string class and find its length.

### Input Format

- A string `str`

### Output Format

- Print string and its length

### Sample Input

```
programming
```

### Sample Output

```
String: programming
Length: 11
```

### Code Example

```cpp
string str = "programming";
cout << "String: " << str << endl;
cout << "Length: " << str.length() << endl;
```

### Constraints

- String length ≤ 100

---

## Problem 12: C++ String Character Access

**Difficulty:** Easy

### Description

Access characters in C++ string using at() function.

### Input Format

- A string `str`
- Position `pos`

### Output Format

- Print character at given position

### Sample Input

```
hello 2
```

### Sample Output

```
Character at position 2: l
```

### Code Example

```cpp
string str = "hello";
int pos = 2;
cout << "Character at position " << pos << ": " << str.at(pos) << endl;
```

### Constraints

- Valid position (0 to length-1)

---

## Problem 13: String Substring

**Difficulty:** Easy

### Description

Extract substring from a C++ string.

### Input Format

- A string `str`
- Start index and length

### Output Format

- Print the substring

### Sample Input

```
programming 4 7
```

### Sample Output

```
Substring: ramming
```

### Code Example

```cpp
string str = "programming";
int start = 4, length = 7;
cout << "Substring: " << str.substr(start, length) << endl;
```

### Constraints

- Valid start and length

---

## Problem 14: Find Substring

**Difficulty:** Easy

### Description

Find position of a substring in a string.

### Input Format

- Main string `str`
- Substring to find `substr`

### Output Format

- Print position if found, "Not found" otherwise

### Sample Input

```
programming gram
```

### Sample Output

```
Found at position: 3
```

### Code Example

```cpp
string str = "programming";
string substr = "gram";
size_t pos = str.find(substr);
if(pos != string::npos) {
    cout << "Found at position: " << pos << endl;
} else {
    cout << "Not found" << endl;
}
```

### Constraints

- String length ≤ 100

---

## Problem 15: String Iteration

**Difficulty:** Easy

### Description

Iterate through string using range-based for loop.

### Input Format

- A string `str`

### Output Format

- Print each character separated by spaces

### Sample Input

```
hello
```

### Sample Output

```
h e l l o
```

### Code Example

```cpp
string str = "hello";
for(char ch : str) {
    cout << ch << " ";
}
cout << endl;
```

### Constraints

- String length ≤ 100

---

## Problem 16: Count Vowels and Consonants

**Difficulty:** Easy

### Description

Count number of vowels and consonants in a string.

### Input Format

- A string `str`

### Output Format

- Print count of vowels and consonants

### Sample Input

```
hello world
```

### Sample Output

```
Vowels: 3
Consonants: 7
```

### Algorithm

1. Initialize vowel_count = 0, consonant_count = 0
2. Iterate through each character
3. Check if vowel (a,e,i,o,u,A,E,I,O,U)
4. Increment appropriate counter

### Constraints

- String length ≤ 100

---

## Problem 17: Remove Duplicates from String

**Difficulty:** Medium

### Description

Remove duplicate characters from a string.

### Input Format

- A string `str`

### Output Format

- Print string with duplicates removed

### Sample Input

```
programming
```

### Sample Output

```
progamin
```

### Algorithm

1. Use frequency array or map
2. Build new string with unique characters

### Constraints

- String length ≤ 100

---

## Problem 18: Check if Strings are Equal

**Difficulty:** Easy

### Description

Compare two strings for equality.

### Input Format

- Two strings `str1` and `str2`

### Output Format

- Print "Equal" or "Not Equal"

### Sample Input

```
hello hello
```

### Sample Output

```
Equal
```

### Code Example

```cpp
string str1 = "hello", str2 = "hello";
if(str1 == str2) {
    cout << "Equal" << endl;
} else {
    cout << "Not Equal" << endl;
}
```

### Constraints

- String length ≤ 100

---

## Problem 19: String to Integer Conversion

**Difficulty:** Easy

### Description

Convert string to integer using stoi function.

### Input Format

- A string containing number

### Output Format

- Print the integer value

### Sample Input

```
12345
```

### Sample Output

```
12345
```

### Code Example

```cpp
string str = "12345";
int num = stoi(str);
cout << num << endl;
```

### Constraints

- Valid number string

---

## Problem 20: Integer to String Conversion

**Difficulty:** Easy

### Description

Convert integer to string using to_string function.

### Input Format

- An integer `num`

### Output Format

- Print the string representation

### Sample Input

```
12345
```

### Sample Output

```
12345
```

### Code Example

```cpp
int num = 12345;
string str = to_string(num);
cout << str << endl;
```

### Constraints

- -10^9 ≤ num ≤ 10^9

---

## Problem 21: Valid Palindrome (Ignoring Case)

**Difficulty:** Medium

### Description

Check if string is palindrome ignoring case differences.

### Input Format

- A string `str`

### Output Format

- Print "Palindrome" or "Not Palindrome"

### Sample Input

```
RaceCar
```

### Sample Output

```
Palindrome
```

### Algorithm

1. Convert entire string to lowercase
2. Check if palindrome

### Constraints

- String length ≤ 100

---

## Problem 22: Count Words in Sentence

**Difficulty:** Easy

### Description

Count number of words in a sentence.

### Input Format

- A sentence `str`

### Output Format

- Print number of words

### Sample Input

```
Hello world programming
```

### Sample Output

```
3
```

### Algorithm

1. Initialize word_count = 0
2. Iterate through string
3. Increment count when space found (not consecutive)

### Constraints

- Sentence length ≤ 100

---

## Problem 23: Reverse Words in Sentence

**Difficulty:** Medium

### Description

Reverse the order of words in a sentence.

### Input Format

- A sentence `str`

### Output Format

- Print sentence with words reversed

### Sample Input

```
Hello world programming
```

### Sample Output

```
programming world Hello
```

### Algorithm

1. Split sentence into words
2. Reverse the words array
3. Join words back

### Constraints

- Sentence length ≤ 100

---

## Problem 24: Check if String is Number

**Difficulty:** Easy

### Description

Check if a string represents a valid number.

### Input Format

- A string `str`

### Output Format

- Print "Valid Number" or "Not a Valid Number"

### Sample Input 1

```
12345
```

### Sample Output 1

```
Valid Number
```

### Sample Input 2

```
12a45
```

### Sample Output 2

```
Not a Valid Number
```

### Algorithm

1. Check each character
2. All characters should be digits

### Constraints

- String length ≤ 100

---

## Problem 25: Find All Substrings

**Difficulty:** Medium

### Description

Generate all possible substrings of a string.

### Input Format

- A string `str`

### Output Format

- Print all substrings

### Sample Input

```
abc
```

### Sample Output

```
a
ab
abc
b
bc
c
```

### Algorithm

```cpp
for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
        for(int k = i; k <= j; k++) {
            cout << str[k];
        }
        cout << endl;
    }
}
```

### Constraints

- String length ≤ 10 (to avoid too much output)

---

## Additional Practice Problems

### Problem 26: Check if Two Strings are Rotations

Check if one string is rotation of another.

### Problem 27: Longest Common Prefix

Find longest common prefix of array of strings.

### Problem 28: Valid Parentheses

Check if string has valid parentheses.

### Problem 29: Compress String

Compress string by replacing consecutive characters.

### Problem 30: Pattern Matching

Implement basic pattern matching with wildcards.

### Problem 31: String Permutations

Generate all permutations of a string.

### Problem 32: Remove Vowels from String

Remove all vowels from a string.

### Problem 33: Check Pangram

Check if string contains all alphabets.

### Problem 34: String Tokenization

Split string into tokens based on delimiter.

### Problem 35: URL Parser

Parse URL to extract components.

## String Concepts

### 1. C-Style Strings (Character Arrays)

- Null-terminated (`\0`)
- Fixed size
- Functions in `<cstring>`
- Manual memory management

### 2. C++ Strings (std::string)

- Dynamic size
- Rich member functions
- Operators overloaded
- Automatic memory management

### 3. String Operations

- **Input:** `cin`, `getline()`
- **Output:** `cout`
- **Manipulation:** `substr()`, `find()`, `replace()`
- **Conversion:** `stoi()`, `to_string()`

### 4. String Algorithms

- **Pattern matching**
- **String compression**
- **Palindrome checking**
- **Anagram detection**

## Key Takeaways

### Common Patterns

```cpp
// Pattern 1: String input
char str[100];
cin >> str; // Word input
cin.getline(str, 100); // Sentence input

// Pattern 2: String length
int length = strlen(str); // C-style
int length = str.length(); // C++ string

// Pattern 3: Character access
char ch = str[0]; // C-style
char ch = str.at(0); // C++ string

// Pattern 4: String comparison
if(strcmp(str1, str2) == 0) // C-style
if(str1 == str2) // C++ string

// Pattern 5: String concatenation
strcat(str1, str2); // C-style
str1 += str2; // C++ string
```

### Best Practices

- **Use C++ strings:** For most applications (safer, easier)
- **Use C-style strings:** When performance critical or interfacing with C
- **Handle null termination:** For C-style strings
- **Check bounds:** Before accessing characters
- **Use appropriate input method:** `cin` vs `getline()`

### Common Mistakes

- **Buffer overflow:** Writing beyond array bounds
- **Missing null termination:** In C-style strings
- **Mixing cin and getline:** Input stream issues
- **Case sensitivity:** String comparisons are case-sensitive

### Performance Tips

- **Pre-allocate strings:** When size known
- **Use reserve():** For expected string size
- **Avoid frequent concatenations:** In loops
- **Use stringstream:** For complex string building

### Interview Tips

- **String manipulation:** Be comfortable with both C and C++ strings
- **Memory management:** Understand C-style string limitations
- **Algorithm implementation:** Know common string algorithms
- **Edge cases:** Empty strings, single character, special characters

### Real-World Applications

1. **Text Processing**

   - Search and replace
   - Text formatting
   - Data validation

2. **Web Development**

   - URL parsing
   - Form validation
   - Template processing

3. **Data Analysis**

   - CSV parsing
   - Log processing
   - Text mining

4. **System Programming**

   - File path manipulation
   - Command line parsing
   - Configuration files

5. **Game Development**
   - Player names
   - Chat messages
   - Localization

### Advanced Topics

1. **Regular Expressions**

   - Pattern matching
   - Text validation
   - Search and replace

2. **Unicode Support**

   - International characters
   - Different encodings
   - Localization

3. **String Algorithms**

   - KMP algorithm
   - Rabin-Karp
   - Aho-Corasick

4. **Memory Optimization**
   - String interning
   - Copy-on-write
   - Small string optimization
