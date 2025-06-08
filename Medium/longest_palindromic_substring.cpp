/*
Link: https://leetcode.com/problems/longest-palindromic-substring/description/

Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n^2)
Space complexity = O(n)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i=0; i<n; i++){
            int j = i - 1, k = i + 1;
            while(j >= 0 && k < n && s[j] == s[k]){
                j--;
                k++;
            }
            if(k - j - 1 > ans.size()){
                ans = s.substr(j + 1, k - j - 1);
            }
            j = i - 1, k = i;
            while(j >= 0 && k < n && s[j] == s[k]){
                j--;
                k++;
            }
            if(k - j - 1 > ans.size()){
                ans = s.substr(j + 1, k - j - 1);
            }
        }
        return ans;
    }
};