/*
Link: https://leetcode.com/problems/sort-list/description/

Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
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

/*
Time complexity = O(nlogn)
Space complexity = O(logn)
*/
class Solution {
private:
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while(left && right){
            if(left->val < right->val){
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        if(left) tail->next = left;
        if(right) tail->next = right;
        return dummy->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* left = head;
        ListNode* right = middle(head);
        ListNode* temp = right->next;
        right->next = nullptr;
        right = temp;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};