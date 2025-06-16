/*
Link: https://leetcode.com/problems/palindrome-partitioning/description/

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(2^n * n)
Space complexity = O(2^n * n)
*/
class Solution {
private:
    bool isPalindrome(string s){
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }

    void solve(int ind, string& s, vector<string>& v, vector<vector<string>>& ans){
        if(ind == s.size()){
            ans.push_back(v);
            return;
        }
        for(int i=ind; i<s.size(); i++){
            string part = s.substr(ind, i - ind + 1);
            if(isPalindrome(part)){
                v.push_back(part);
                solve(i+1, s, v, ans);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        solve(0, s, v, ans);
        return ans;
    }
};