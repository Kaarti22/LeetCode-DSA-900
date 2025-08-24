/*
Link: https://leetcode.com/problems/recover-binary-search-tree/description/

You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 

Constraints:

The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1
 

Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?
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
Time complexity = O(nlogn)
Space complexity = O(n)
*/
class Solution {
private:
    void inOrder(TreeNode* root, vector<int>& v){
        if(!root) return;
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }

    void recover(TreeNode* root, pair<int, int>& p){
        if(!root) return;
        if(root->val == p.first){
            root->val = p.second;
        } else if(root->val == p.second){
            root->val = p.first;
        }
        recover(root->left, p);
        recover(root->right, p);
    }

public:
    void recoverTree(TreeNode* root) {
        vector<int> v;
        inOrder(root, v);
        vector<int> copy = v;
        sort(copy.begin(), copy.end());
        pair<int, int> p;
        int n = v.size();
        for(int i=0; i<n; i++){
            if(v[i] != copy[i]){
                p.first = v[i];
                p.second = copy[i];
                break;
            }
        }
        recover(root, p);
    }
};

/*
Time complexity = O(n)
Space complexity = O(1)
*/
class Solution {
private:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;

    void inOrder(TreeNode* node){
        if(!node) return;
        inOrder(node->left);
        if(node->val < prev->val){
            if(first == nullptr){
                first = prev;
                middle = node;
            } else {
                last = node;
            }
        }
        prev = node;
        inOrder(node->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        inOrder(root);
        if(first && last) swap(first->val, last->val);
        else swap(first->val, middle->val);
    }
};