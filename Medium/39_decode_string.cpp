/*
Link: https://leetcode.com/problems/decode-string/description/

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
 

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n)
Space complexity = O(n)
*/
class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack <string> stringStack;
        string curr = "";
        int k = 0;
        for(auto ch: s){
            if(isdigit(ch)){
                k = k * 10 + (ch - '0');
            } else if(ch == '['){
                countStack.push(k);
                stringStack.push(curr);
                curr = "";
                k = 0;
            } else if(ch == ']'){
                string decoded = stringStack.top();
                stringStack.pop();
                int count = countStack.top();
                countStack.pop();
                while(count--){
                    decoded += curr;
                }
                curr = decoded;
            } else {
                curr.push_back(ch);
            }
        }
        return curr;
    }
};