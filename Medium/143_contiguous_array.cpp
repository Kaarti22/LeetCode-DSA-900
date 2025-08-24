/*
Link: https://leetcode.com/problems/contiguous-array/

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Example 3:

Input: nums = [0,1,1,1,1,1,0,0,0]
Output: 6
Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n)
Space complexity = O(n)
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n);
        if(nums[0] == 0) sum[0] = -1;
        else sum[0] = 1;
        for(int i=1; i<n; i++){
            if(nums[i] == 0) sum[i] = sum[i-1] - 1;
            else sum[i] = sum[i-1] + 1; 
        }
        int ans = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for(int i=0; i<n; i++){
            if(m.find(sum[i]) != m.end()){
                int ind = m[sum[i]];
                ans = max(ans, i - ind);
            } else {
                m[sum[i]] = i;
            }
        }
        return ans;
    }
};