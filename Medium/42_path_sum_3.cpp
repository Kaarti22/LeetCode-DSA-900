/*
Link: https://leetcode.com/problems/path-sum-iii/description/

Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

Example 1:


Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
-1000 <= targetSum <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Time complexity = O(n^2)
Space complexity = O(n^2)
*/
class Solution {
private:
    vector<long long> solve(TreeNode* node, long long targetSum, int& ans){
        if(!node) return {};
        vector<long long> left = solve(node->left, targetSum, ans);
        vector<long long> right = solve(node->right, targetSum, ans);
        vector<long long> v = {node->val * 1ll};
        if(node->val * 1ll == targetSum) ans++;
        for(auto it: left){
            v.push_back(it + node->val * 1ll);
            if(it + node->val * 1ll == targetSum) ans++;
        }
        for(auto it: right){
            v.push_back(it + node->val * 1ll);
            if(it + node->val * 1ll == targetSum) ans++;
        }
        return v;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        solve(root, targetSum * 1ll, ans);
        return ans;
    }
};