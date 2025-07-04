/*
Link: https://leetcode.com/problems/permutation-in-string/description/

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n)
Space complexity = O(26)
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m1;
        for(auto it: s1){
            m1[it]++;
        }
        int n = s1.size(), m = s2.size();
        int i = 0, j = 0;
        unordered_map<char, int> m2;
        while(i < m){
            while(j < i + n && j < m){
                m2[s2[j]]++;
                j++;
            }
            if(m1 == m2) return true;
            m2[s2[i]]--;
            if(m2[s2[i]] == 0) m2.erase(s2[i]);
            i++;
        }
        return false;
    }
};