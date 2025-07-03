/*
Link: https://leetcode.com/problems/path-sum-ii/description/

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
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
Time complexity = O(n * h)
Space complexity = O(n)
*/
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<vector<int>> ans;
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = nullptr;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int sum = q.front().second;
            q.pop();
            if(!node->left && !node->right && sum == targetSum){
                vector<int> v;
                TreeNode* curr = node;
                while(curr){
                    v.push_back(curr->val);
                    curr = parent[curr];
                }
                reverse(v.begin(), v.end());
                ans.push_back(v);
            }
            if(node->left){
                parent[node->left] = node;
                q.push({node->left, sum + node->left->val});
            }
            if(node->right){
                parent[node->right] = node;
                q.push({node->right, sum + node->right->val});
            }
        }
        return ans;
    }
};