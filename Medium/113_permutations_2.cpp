/*
Link: https://leetcode.com/problems/permutations-ii/description/

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(n! * n * log(n!))
Space complexity = O(n * (n!))
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> v = nums;
        do {
            next_permutation(v.begin(), v.end());
            s.insert(v);
        } while(v != nums);
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};