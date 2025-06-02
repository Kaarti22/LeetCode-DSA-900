/*
Link: https://leetcode.com/problems/minimum-window-substring/description/

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n) + O(m)
Space complexity = O(52)
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> m;
        for(auto it: t){
            m[it]++;
        }
        int c = m.size();
        unordered_map<char, int> mp;
        int st = 0, end = INT_MAX - 1;
        int i = 0, j = 0;
        while(i < n){
            while(j < n){
                mp[s[j]]++;
                if(m.find(s[j]) != m.end() && mp[s[j]] == m[s[j]]){
                    c--;
                }
                if(c == 0){
                    while(i < n){
                        mp[s[i]]--;
                        if(mp[s[i]] == 0) mp.erase(s[i]);
                        if(m.find(s[i]) != m.end() && (mp.find(s[i]) == mp.end() || mp[s[i]] < m[s[i]])){
                            c++;
                            if(j - i + 1 < end - st + 1){
                                st = i;
                                end = j;
                            }
                            i++;
                            break;
                        }
                        i++;
                    }
                }
                j++;
            }
            i++;
        }
        if(end == INT_MAX - 1) return "";
        return s.substr(st, end - st + 1);
    }
};