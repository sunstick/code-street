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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *tail = &dummy;
        ListNode *node = head;

        while (node) {
            tail -> next = node;

            while (node && node -> val == tail -> next -> val)
                node = node -> next;

            tail = tail -> next;
            tail -> next = NULL;
        }

        return dummy.next;
    }
};