/*
Link: https://leetcode.com/problems/single-number-ii/description/

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(32 * n)
Space complexity = O(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int j=0; j<32; j++){
            int c = 0;
            for(auto it: nums){
                if((1 << j) & it){
                    c++;
                }
            }
            if(c % 3 != 0) ans |= (1 << j);
        }
        return ans;
    }
};