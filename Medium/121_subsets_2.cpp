/*
Link: https://leetcode.com/problems/subsets-ii/description/

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(2^n)
Space complexity = O(n * 2^n)
*/
class Solution {
private:
    void solve(vector<int>& nums, int ind, vector<int>& v, vector<vector<int>>& ans){
        ans.push_back(v);
        for(int i=ind; i<nums.size(); i++){
            if(i > ind && nums[i] == nums[i-1]) continue;
            v.push_back(nums[i]);
            solve(nums, i + 1, v, ans);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve(nums, 0, v, ans);
        return ans;
    }
};