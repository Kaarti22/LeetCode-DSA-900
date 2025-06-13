/*
Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
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
Time complexity = O(k)
Space complexity = O(h)
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int c = 0;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            c++;
            if(c == k){
                return curr->val;
            }
            curr = curr->right;
        }
        return -1;
    }
};

// Definition of Binary tree with leftSize (additional)
struct TreeNode {
    int val;
    int leftSize;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Time complexity = O(h) = O(logn)
Insert/Delete = still O(logn) while maintaining leftSubtreeSize
*/
class AugmentedBST {
public:
    TreeNode* root = nullptr;

    int kthSmallest(TreeNode* node, int k){
        while(node){
            if(k == node->leftSize + 1) return node->val;
            else if(k <= node->leftSize) node = node->left;
            else {
                k -= node->leftSize + 1;
                node = node->right;
            }
        }
        return -1;
    }

    // insert and delete functions must update node->leftSize accordingly
};