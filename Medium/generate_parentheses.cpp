/*
Link: https://leetcode.com/problems/generate-parentheses/description/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(2^2n)
Space complexity = O(2n)
*/
class Solution {
private:
    void solve(string& s, vector<string>& ans, int open, int close, int n){
        if(open == n && close == n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            s += "(";
            solve(s, ans, open + 1, close, n);
            s.pop_back();
        }
        if(open > close){
            s += ")";
            solve(s, ans, open, close + 1, n);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> ans;
        int open = 0, close = 0;
        solve(s, ans, open, close, n);
        return ans;
    }
};