/*
Link: https://leetcode.com/problems/combination-sum-ii/description/

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity = O(2^n)
Space complexity = O(k) where k is length of path
*/
class Solution {
private:
    void solve(int ind, int target, vector<int>& v, vector<int>& candidates, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        for(int i=ind; i<candidates.size(); i++){
            if(i > ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            v.push_back(candidates[i]);
            solve(i + 1, target - candidates[i], v, candidates, ans);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve(0, target, v, candidates, ans);
        return ans;
    }
};