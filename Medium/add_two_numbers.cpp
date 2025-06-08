/*
Link: https://leetcode.com/problems/add-two-numbers/description/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
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
Time complexity = O(n+m)
Space complexity = O(n+m)
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = nullptr;
        ListNode* temp = nullptr;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        while(temp1 && temp2){
            int val = temp1->val + temp2->val + carry;
            int rem = val % 10;
            carry = val / 10;
            ListNode* node = new ListNode(rem);
            if(temp == nullptr){
                ans = node;
            } else {
                temp->next = node;
            }
            temp = node;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1){
            int val = temp1->val + carry;
            int rem = val % 10;
            carry = val / 10;
            ListNode* node = new ListNode(rem);
            if(temp == nullptr){
                ans = node;
            } else {
                temp->next = node;
            }
            temp = node;
            temp1 = temp1->next;
        }
        while(temp2){
            int val = temp2->val + carry;
            int rem = val % 10;
            carry = val / 10;
            ListNode* node = new ListNode(rem);
            if(temp == nullptr){
                ans = node;
            } else {
                temp->next = node;
            }
            temp = node;
            temp2 = temp2->next;
        }
        if(carry == 1){
            ListNode* node = new ListNode(carry);
            temp->next = node;
        }
        return ans;
    }
};