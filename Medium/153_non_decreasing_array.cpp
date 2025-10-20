/*
Link: https://leetcode.com/problems/non-decreasing-array/description/

Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

 

Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:

Input: nums = [4,2,1]
Output: false
Explanation: You cannot get a non-decreasing array by modifying at most one element.
 

Constraints:

n == nums.length
1 <= n <= 104
-105 <= nums[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n)
Space complexity = O(1)
*/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                if((i == 0) || (i-1 >= 0 && nums[i-1] <= nums[i+1])){
                    ind = i;
                    break;
                } else {
                    nums[i+1] = nums[i];
                    ind = i;
                    break;
                }
            }
        }
        if(ind == -1) return true;
        for(int i=ind+1; i<n-1; i++){
            if(nums[i] > nums[i+1]) return false;
        }
        return true;
    }
};