/*
Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
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
Time complexity = O(n)
Space complexity = O(n)
*/
class Solution {
private:
    unordered_map<int, int> inorderIndex;
    int preIndex = 0;

    TreeNode* solve(vector<int>& preorder, int inStart, int inEnd){
        if(inStart > inEnd){
            return nullptr;
        }
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int inIndex = inorderIndex[rootVal];
        root->left = solve(preorder, inStart, inIndex - 1);
        root->right = solve(preorder, inIndex + 1, inEnd);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            inorderIndex[inorder[i]] = i;
        }
        return solve(preorder, 0, inorder.size()-1);
    }
};