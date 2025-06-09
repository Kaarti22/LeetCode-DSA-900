/*
Link: https://leetcode.com/problems/product-of-array-except-self/description/

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n)
Space complexity = O(n)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n), suffix(n);
        int prod = 1;
        for(int i=0; i<n; i++){
            prod *= nums[i];
            prefix[i] = prod;
        }
        prod = 1;
        for(int i=n-1; i>=0; i--){
            prod *= nums[i];
            suffix[i] = prod;
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            if(i == 0){
                ans[i] = suffix[i+1];
            } else if(i == n-1){
                ans[i] = prefix[i-1];
            } else {
                ans[i] = prefix[i-1] * suffix[i+1];
            }
        }
        return ans;
    }
};

/*
Time complexity = O(n)
Space complexity = O(1)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int prod = 1;
        for(int i=0; i<n; i++){
            prod *= nums[i];
            ans[i] = prod; 
        }
        prod = 1;
        for(int i=n-1; i>=0; i--){
            if(i == 0){
                ans[i] = prod;
            } else {
                ans[i] = ans[i-1] * prod;
            }
            prod *= nums[i];
        }
        return ans;
    }
};