/*
Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

 

Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []
 

Constraints:

The number of nodes in head is in the range [0, 2 * 104].
-105 <= Node.val <= 105
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
Space complexity = O(logn)
*/
class Solution {
private:
    ListNode* curr;

    TreeNode* solve(int left, int right){
        if(left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* leftChild = solve(left, mid - 1);
        TreeNode* node = new TreeNode(curr->val);
        node->left = leftChild;
        curr = curr->next;
        node->right = solve(mid + 1, right);
        return node;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        curr = head;
        return solve(0, n - 1);
    }
};