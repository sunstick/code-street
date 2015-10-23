/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        int k = 0;
        ListNode *far = head;
        ListNode *near = head;
        ListNode *prev = &dummy;

        while (k < n) {
            far = far -> next;
            k++;
        }

        while (far) {
            far = far -> next;
            near = near -> next;
            prev = prev -> next;
        }

        prev -> next = near -> next;
        delete[] near;

        return dummy.next;
    }
};