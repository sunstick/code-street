/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy1(0);
        ListNode dummy2(0);
        ListNode *tail1 = &dummy1;
        ListNode *tail2 = &dummy2;

        ListNode *node = head;

        // alternating split
        int i = 0;
        while (node) {
            ListNode **tail;
            if (i % 2 == 0)
                tail = &tail1;
            else
                tail = &tail2;

            (*tail) -> next = node;
            node = node -> next;
            *tail = (*tail) -> next;
            (*tail) -> next = NULL;
            i++;
        }

        // alternating merge
        ListNode dummy(0);
        ListNode *tail = &dummy;
        ListNode *node1 = dummy1.next;
        ListNode *node2 = dummy2.next;

        while (node2 && node1) {
            tail -> next = node2;
            node2 = node2 -> next;
            tail = tail -> next;
            tail -> next = NULL;

            tail -> next = node1;
            node1 = node1 -> next;
            tail = tail -> next;
            tail -> next = NULL;
        }

        if (node1)
            tail -> next = node1;
        if (node2)
            tail -> next = node2;

        return dummy.next;
    }
};