/*
Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(logn)
Space complexity = O(1)
*/
class Solution {
private:
    int firstIndex(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] < target){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low < n && nums[low] == target ? low : -1;
    }

    int lastIndex(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] <= target){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high >= 0 && nums[high] == target ? high : -1;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        int first = firstIndex(nums, target);
        int last = lastIndex(nums, target);
        return {first, last};
    }
};