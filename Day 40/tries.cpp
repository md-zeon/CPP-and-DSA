#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    int freq;

    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
        root->freq = -1; // for prefix problem
    }

    void insert(string key) { // O(L)
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node(); // insert
                temp->children[key[i]]->freq = 1; // for prefix problem
            } else {
                temp->children[key[i]]->freq += 1; // for prefix problem
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    bool search(string key) { // O(L)
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) {
                return false;
            } else {
                temp = temp->children[key[i]];
            }
        }
        return temp->endOfWord;
    }

    string getPrefix(string key) {
        Node* temp = root;
        string prefix = "";
        for (int i = 0; i < key.size(); i++) {
            prefix += key[i];
            if (temp->children[key[i]]->freq == 1) {
                break;
            }
            temp = temp->children[key[i]];
        }
        return prefix;
    }

    bool startsWith(string prefix) { // O(L)
        Node* temp = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (temp->children[prefix[i]]) {
                temp = temp->children[prefix[i]];
            } else {
                return false;
            }
        }
        return true;
    }

    void longestHelper(Node* root, string &ans, string temp) {
        for (pair<char, Node*> child : root->children) {
            if (child.second->endOfWord) {
                temp += child.first;
                if ((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())) {
                    ans = temp;
                }
                longestHelper(child.second, ans, temp);
                temp = temp.substr(0, temp.size()-1);
            }
        }
    }

    string longestStringWithEOW() {
        string ans = "";
        longestHelper(root, ans, "");
        return ans;
    }
};

bool wordBreakFunc(string key, Trie &trie) {
    if (key.size() == 0) {
        return true;
    }
    for (int i = 0; i < key.size(); i++) {
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);
        if (trie.search(first) && wordBreakFunc(second, trie)) {
            return true;
        }
    }
    return false;
}

void prefixProblem(vector<string> dict) {
    Trie trie;
    for (int i = 0; i < dict.size(); i++) {
        trie.insert(dict[i]);
    }

    for (int i = 0; i < dict.size(); i++) {
        cout << trie.getPrefix(dict[i]) << " ";
    }
}

string longestString(vector<string> dict) {
    Trie trie;
    string ans = "";
    for (int i = 0; i < dict.size(); i++) {
        trie.insert(dict[i]);
    }

    return trie.longestStringWithEOW();
}

int main() {
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    
    // Trie trie;
    // for (int i = 0; i < words.size(); i++) {
    //     trie.insert(words[i]);
    // }

    // cout << "Searching for 'cat': " << (trie.search("cat") ? "Found" : "Not Found") << endl;
    // cout << "Searching for 'the': " << (trie.search("the") ? "Found" : "Not Found") << endl;
    // cout << "Searching for 'their': " << (trie.search("their") ? "Found" : "Not Found") << endl;


    //! Word Break Problem
    /*
    vector<string> dictionary = {"i", "like", "sam", "sung", "samsung", "mobile", "ice"};
    string key = "ilikesamsung";
    Trie wordBreak;

    for (int i = 0; i < dictionary.size(); i++) {
        wordBreak.insert(dictionary[i]);
    }
    if (wordBreakFunc(key, wordBreak)) {
        cout << "Key is a word break of given string" << endl;
    } else {
        cout << "Key is not a word break of given string" << endl;
    }
    */

    //! Prefix Problem : Find shortest unique prefix for each word. (no word is prefix of another)
    words.clear();
    words = {"zebra", "dog", "duck", "dove"};
    // prefixProblem(words); // ans = "z", "dog", "du", "dov"

    //! Starts With Problem
    /*
    words.clear();
    words = {"apple", "app", "mango", "man", "woman"};
    vector<string> prefix = {"app", "man", "wom", "wem"};
    Trie sw;

    for (int i = 0; i < words.size(); i++) {
        sw.insert(words[i]);
    }

    for (int i = 0; i < prefix.size(); i++) {
        if (sw.startsWith(prefix[i])) {
            cout << prefix[i] << " starts with a word" << endl;
        } else {
            cout << prefix[i] << " does not start with a word" << endl;
        }
    }
    */

    //! Count Unique Substrings
    // do it

    //! Longest words with all Prefix: Longest word such that all of it's prefix's exist in array
    vector<string> dict = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << longestString(dict);



    return 0;
}