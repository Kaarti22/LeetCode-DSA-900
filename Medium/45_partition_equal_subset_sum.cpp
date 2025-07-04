/*
Link: https://leetcode.com/problems/partition-equal-subset-sum/description/

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n*sum)
Space complexity = O(n*sum)
*/
class Solution {
private:
    bool subsetSum(vector<int>& nums, int sum){
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
        for(int i=0; i<n+1; i++){
            dp[i][0] = true;
        }
        for(int j=1; j<sum+1; j++){
            dp[0][j] = false;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        return subsetSum(nums, sum / 2);
    }
};