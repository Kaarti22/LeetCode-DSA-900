/*
Link: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/

Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Example 2:

Input: nums = [1,2,3,4], k = 3
Output: false
 

Constraints:

1 <= k <= nums.length <= 16
1 <= nums[i] <= 104
The frequency of each element is in the range [1, 4].
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(k * 2^n) but pruning and sorting help drastically
Space complexity = O(n)
*/
class Solution {
private:
    bool solve(int ind, int currSum, int k, vector<int>& nums, vector<bool>& vis, int target){
        if(k == 0) return true;
        if(currSum == target){
            return solve(0, 0, k-1, nums, vis, target);
        }
        for(int i=ind; i<nums.size(); i++){
            if(vis[i] || currSum + nums[i] > target) continue;
            vis[i] = true;
            if(solve(i + 1, currSum + nums[i], k, nums, vis, target)) return true;
            vis[i] = false;
            if(currSum == 0) break;
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;
        int target = sum / k;
        sort(nums.rbegin(), nums.rend());
        vector<bool> vis(nums.size(), false);
        return solve(0, 0, k, nums, vis, target);
    }
};

/*
Time complexity = O(n * 2^n)
Space complexity = O(2^n + n)
*/
class Solution {
private:
    bool dfs(vector<int>& nums, int k, int currSum, int start, int target, int usedMask, unordered_map<int, bool>& dp){
        if(k == 0) return true;
        if(currSum == target){
            return dfs(nums, k-1, 0, 0, target, usedMask, dp);
        }
        if(dp.count(usedMask)) return dp[usedMask];
        for(int i=start; i<nums.size(); i++){
            if((usedMask >> i) & 1) continue;
            if(currSum + nums[i] > target) continue;
            int newMask = usedMask | (1 << i);
            if(dfs(nums, k, currSum + nums[i], i + 1, target, newMask, dp)){
                return dp[usedMask] = true;
            }
        }
        return dp[usedMask] = false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;
        int target = sum / k;
        sort(nums.rbegin(), nums.rend());
        if(nums[0] > target) return false;
        unordered_map<int, bool> dp;
        return dfs(nums, k, 0, 0, target, 0, dp);
    }
};