/*
Link: https://leetcode.com/problems/unique-binary-search-trees/description/

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 19
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n^2)
Space complexity = O(n)
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++){
                int left = j - 1;
                int right = i - j;
                dp[i] += dp[left] * dp[right];
            }
        }
        return dp[n];
    }
};