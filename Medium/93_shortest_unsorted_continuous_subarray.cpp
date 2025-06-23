/*
Link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
 

Follow up: Can you solve it in O(n) time complexity?
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n)
Space complexity = O(1)
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int st = -1, end = -1;
        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                st = i;
                break;
            }
        }
        if(st == -1) return 0;
        for(int i=n-1; i>0; i--){
            if(nums[i] < nums[i-1]){
                end = i;
                break;
            }
        }
        int maxi = INT_MIN, mini = INT_MAX;
        for(int i=st; i<=end; i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        st--;
        while(st >= 0 && nums[st] > mini){
            st--;
        }
        end++;
        while(end < n && nums[end] < maxi){
            end++;
        }
        return end - st - 1;
    }
};