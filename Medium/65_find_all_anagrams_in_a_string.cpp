/*
Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n)
Space complexity = O(26)
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        unordered_map<char, int> m1;
        for(auto it: p){
            m1[it]++;
        }
        vector<int> ans;
        unordered_map<char, int> m2;
        int i = 0, j = 0;
        while(j < n){
            while(j - i + 1 <= m){
                m2[s[j]]++;
                j++;
            }
            if(m1 == m2) ans.push_back(i);
            m2[s[i]]--;
            if(m2[s[i]] == 0) m2.erase(s[i]);
            i++;
        }
        return ans;
    }
};