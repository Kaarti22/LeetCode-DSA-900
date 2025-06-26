/*
Link: https://leetcode.com/problems/largest-number/description/

Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(nlogn)
Space complexity = O(n)
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto it: nums){
            v.push_back(to_string(it));
        }
        sort(v.begin(), v.end(), [&](string& a, string& b){
            return (a + b) > (b + a);
        });
        if(v[0] == "0") return "0";
        string ans = "";
        for(auto it: v){
            ans += it;
        }
        return ans;
    }
};