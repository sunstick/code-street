/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        tail -> next = head;
        ListNode *kbegin = NULL;
        ListNode *kend = NULL;

        ListNode *node = head;

        int i = 0;
        while (node) {
            if (i % k == 0)
                kbegin = node;
            if (i % k == k - 1)
                kend = node;
            node = node -> next;
            if (i % k == k - 1) {
                kend -> next = NULL;
                ListNode *prev = NULL;
                ListNode *t = kbegin;
                while (t) {
                    ListNode *temp = t -> next;
                    t -> next = prev;
                    prev = t;
                    t = temp;
                }
                tail -> next = kend;
                tail = kbegin;
                tail -> next = node;
            }
            i++;
        }
        return dummy.next;
    }
};