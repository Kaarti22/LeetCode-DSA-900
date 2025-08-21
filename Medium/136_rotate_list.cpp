/*
Link: https://leetcode.com/problems/rotate-list/

Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
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
Time complexity = O(n)
Space complexity = O(1)
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int total = 0;
        ListNode* temp = head;
        ListNode* last = head;
        while(temp){
            last = temp;
            total++;
            temp = temp->next;
        }
        k %= total;
        if(k == 0) return head;
        int c = 0;
        temp = head;
        while(c < total - k - 1){
            temp = temp->next;
            c++;
        }
        ListNode* tempHead = temp->next;
        last->next = head;
        temp->next = nullptr;
        head = tempHead;
        return head;
    }
};