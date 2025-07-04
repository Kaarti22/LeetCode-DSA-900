/*
Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
Time complexity = O(n)
Space complexity = O(n)
*/
class Solution {
private:
    void fillParents(TreeNode* node, TreeNode* par, unordered_map<TreeNode*, TreeNode*>& parent){
        parent[node] = par;
        if(node->left){
            fillParents(node->left, node, parent);
        }
        if(node->right){
            fillParents(node->right, node, parent);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        fillParents(root, nullptr, parent);
        queue<pair<pair<TreeNode*, TreeNode*>, int>> q;
        q.push({{target, nullptr}, 0});
        vector<int> ans;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first.first;
            TreeNode* par = it.first.second;
            int dist = it.second;
            if(dist == k){
                ans.push_back(node->val);
                continue;
            }
            if(node->left && node->left != par){
                q.push({{node->left, node}, dist + 1});
            }
            if(node->right && node->right != par){
                q.push({{node->right, node}, dist + 1});
            }
            if(parent[node] != nullptr && parent[node] != par){
                q.push({{parent[node], node}, dist + 1});
            }
        }
        return ans;
    }
};