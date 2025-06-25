/*
Link: https://leetcode.com/problems/unique-binary-search-trees-ii/description/

Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

 

Example 1:


Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 8Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

 

Example 1:


Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 8
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
Time complexity = O(n * 4^n / sqrt(n))
Space complexity = O(n * 4^n / sqrt(n))
*/
class Solution {
private:
    vector<TreeNode*> build(int start, int end){
        vector<TreeNode*> ans;
        if(start > end){
            ans.push_back(nullptr);
            return ans;
        }
        for(int i=start; i<=end; i++){
            vector<TreeNode*> leftTrees = build(start, i-1);
            vector<TreeNode*> rightTrees = build(i+1, end);
            for(auto left: leftTrees){
                for(auto right: rightTrees){
                    TreeNode* node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
};