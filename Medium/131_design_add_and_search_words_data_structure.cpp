/*
Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 2 dots in word for search queries.
At most 104 calls will be made to addWord and search.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(m * 52)
Space complexity = O(n)
*/
class WordDictionary {
private:
    unordered_set<string> s;

public:
    WordDictionary() {
        s.clear();
    }
    
    void addWord(string word) {
        s.insert(word);
    }
    
    bool search(string word) {
        int n = word.size();
        vector<int> ind;
        for(int i=0; i<n; i++){
            if(word[i] == '.') ind.push_back(i);
        }
        if(ind.size() == 0){
            return s.find(word) != s.end();
        } else if(ind.size() == 1){
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[ind[0]] = ch;
                if(s.find(word) != s.end()) return true;
            }
        } else {
            for(char ch1 = 'a'; ch1 <= 'z'; ch1++){
                word[ind[0]] = ch1;
                for(char ch2 = 'a'; ch2 <= 'z'; ch2++){
                    word[ind[1]] = ch2;
                    if(s.find(word) != s.end()) return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */