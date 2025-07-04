/*
Link: https://leetcode.com/problems/4sum/description/

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n^3)
Space complexity = O(1)
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; i++){
            if(i > 0 && nums[i-1] == nums[i]) continue;
            for(int j=i+1; j<n-2; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                long long sum = 1ll * target - 1ll * nums[i] - 1ll * nums[j];
                int k = j + 1, l = n - 1;
                while(k < l){
                    if((1ll * nums[k] + 1ll * nums[l]) == sum){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k-1]) k++;
                        while(k < l && nums[l] == nums[l+1]) l--;
                    } else if((1ll * nums[k] + 1ll * nums[l]) < sum){
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};