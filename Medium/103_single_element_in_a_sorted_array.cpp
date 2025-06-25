/*
Link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(logn)
Space complexity = O(1)
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(mid - 1 >= 0 && nums[mid-1] != nums[mid] && mid + 1 < n && nums[mid+1] != nums[mid]){
                return nums[mid];
            }
            if(mid - 1 >= 0 && nums[mid-1] == nums[mid]){
                int len = mid - low + 1;
                if(len & 1) high = mid;
                else low = mid + 1;
            } else {
                int len = mid - low;
                if(len & 1) high = mid - 1;
                else low = mid;
            }
        }
        return nums[low];
    }
};