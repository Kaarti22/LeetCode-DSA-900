/*
Link: https://leetcode.com/problems/subarray-sum-equals-k/description/

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n)
Space complexity = O(n)
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        m[0] = 1;
        int ans = 0, sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            int rem = sum - k;
            if(m.find(rem) != m.end()){
                ans += m[rem];
            }
            m[sum]++;
        }
        return ans;
    }
};