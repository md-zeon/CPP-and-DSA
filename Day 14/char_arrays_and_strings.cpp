#include<iostream>
#include <cstring>
#include <string>

using namespace std;

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
        } else {
            continue;
        }
    }
}

void reverse(char word[], int n) {
    int st = 0, end = n-1;
    while (st < end)
    {
        swap(word[st], word[end]);
        st++;
        end--;
    }
    
}

bool isPalindrome(char word[], int n) {
    int st = 0, end = n-1;
    while(st < end) {
        if(word[st++] != word[end--]) {
            return false;
        }
    }
    return true;
}

bool isAnagram(string str1, string str2) {
    if(str1.length() != str2.length()) {
        return false;
    }

    int count[26] = {0};
    for(int i = 0; i < str1.length(); i++) {
        int idx = str1[i] - 'a';
        count[idx]++;
    }

    for(int i = 0; i < str2.length(); i++) {
        int idx = str2[i] - 'a';
        count[idx]--;
        if(count[idx] < 0) {
            return false;
        }
    }

    return true;

}

int main() {
    // char work[10] = {'h', 'e', 'l', 'l', 'o', '\0'};
    // cout << strlen(work) << endl;
    // char word[30];
    // cin >> word;
    // cout << "Your word was : " << word << endl << "Your length: " << strlen(word) << endl;
    // char sentence[100];
    // cin.getline(sentence, 100);
    // cout << "Your Sentence was : " << sentence << endl << "Your length: " << strlen(sentence) << endl;

    //! Convert to Uppercase && lowercase
    char word[] = "racecar";
    // cout << "Original Word: " << word << endl;
    // convertToUppercase(word);
    // cout << "Uppercase Word: " << word << endl;
    // convertToLowercase(word);
    // cout << "Lowercase Word: " << word << endl;

    //! Reverse a char array
    // reverse(word, strlen(word));
    // cout << "Reversed Word: " << word << endl;

    //! valid palindrome
    // cout << "isPalindrome: " << isPalindrome(word, strlen(word)) << endl;

    //? <cstring> functions
    /**
     ** strcpy(dest, src) : to copy string from source to destination
     ** strcat(str1, str2) : to concatenate str1 with str2
     ** strcmp(str1, str2) : compares two strings based on values(-ve, 0, +ve)
     */

    //? String in c++
    /**
     ** C++ strings are objects of pre-defined string class in STL
     ** C++ string have useful member functions.
     ** C++ string are dynamic(their size can change in run time).
     ** C++ string support operators like +, ==, >, < etc.
     ** C++ string are stored contiguously in memory.
     */

    // string str = "hello";
    // cout << str << endl;
    // str = "yellow";
    // cout << str << endl;
    // getline(cin, str);
    // cout << str << endl;

    //? for each loop
    string str = "apna college";
    // for(char ch:str) {
    //     cout << ch << " ";
    // }
    // cout << endl;

    //? member functions in string 
    /**
     ** str,length();
     ** str.at(idx);
     ** str.substr(startIdx, size)
     ** str.find(word);
    */

    // cout << str.length() << endl;
    // cout << str.at(3) << endl;
    // cout << str.substr(5, 7) << endl;
    // cout << str.find("college") << endl;

    //! valid Anagrams
    cout << isAnagram("anagram", "nagaram");
    return 0;
}