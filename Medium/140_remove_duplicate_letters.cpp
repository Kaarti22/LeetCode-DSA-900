/*
Link: https://leetcode.com/problems/remove-duplicate-letters/

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
 

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n)
Space complexity = O(26)
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        unordered_map<char, int> last;
        for(int i=0; i<n; i++){
            last[s[i]] = i;
        }
        unordered_set<char> seen;
        stack<char> st;
        for(int i=0; i<n; i++){
            if(seen.find(s[i]) != seen.end()) continue;
            while(!st.empty() && st.top() >= s[i] && last[st.top()] > i){
                seen.erase(st.top());
                st.pop();
            }
            st.push(s[i]);
            seen.insert(s[i]);
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};