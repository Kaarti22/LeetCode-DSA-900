/*
Link: https://leetcode.com/problems/3sum-closest/description/

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n^2)
Space complexity = O(1)
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i=0; i<n-2; i++){
            int j = i + 1, k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < abs(ans - target)){
                    ans = sum;
                }
                if(sum < target) j++;
                else if(sum > target) k--;
                else return target;
            }
        }
        return ans;
    }
};