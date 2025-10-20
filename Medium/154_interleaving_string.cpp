/*
Link: https://leetcode.com/problems/interleaving-string/

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
 

Follow up: Could you solve it using only O(s2.length) additional memory space?
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n * m)
Space complexity = O(n * m)
*/
class Solution {
private:
    unordered_map<string, bool> dp;

    bool solve(string& s1, string& s2, string& s3, int ind1, int ind2, int ind){
        int n = s1.size(), m = s2.size(), k = s3.size();
        if(ind == k){
            return ind1 == n && ind2 == m;
        }
        string key = to_string(ind1) + "#" + to_string(ind2) + "#" + to_string(ind);
        if(dp.find(key) != dp.end()) return dp[key];
        bool a = false, b = false;
        if(ind1 < n && s1[ind1] == s3[ind]){
            a = solve(s1, s2, s3, ind1 + 1, ind2, ind + 1);
        }
        if(ind2 < m && s2[ind2] == s3[ind]){
            b = solve(s1, s2, s3, ind1, ind2 + 1, ind + 1);
        }
        return dp[key] = a || b;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        return solve(s1, s2, s3, 0, 0, 0);
    }
};

/*
Time complexity = O(n * m)
Space complexity = O(m)
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();
        if(n + m != k) return false;
        vector<bool> dp(m+1, false);
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i == 0 && j == 0) dp[j] = true;
                else if(i == 0){
                    dp[j] = dp[j-1] && s2[j-1] == s3[i+j-1];
                } else if(j == 0){
                    dp[j] = dp[j] && s1[i-1] == s3[i+j-1];
                } else {
                    dp[j] = (dp[j] && s1[i-1] == s3[i+j-1]) || (dp[j-1] && s2[j-1] == s3[i+j-1]);
                }
            }
        }
        return dp[m];
    }
};