/*
Link: https://leetcode.com/problems/coin-change/description/

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n^2)
Space complexity = O(n^2)
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1));
        for(int i=0; i<n+1; i++){
            dp[i][0] = 0;
        }
        for(int j=1; j<amount+1; j++){
            dp[0][j] = INT_MAX - 1;
            if(j % coins[0] == 0){
                dp[1][j] = j / coins[0];
            } else {
                dp[1][j] = INT_MAX - 1;
            }
        }
        for(int i=2; i<n+1; i++){
            for(int j=1; j<amount+1; j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
    }
};