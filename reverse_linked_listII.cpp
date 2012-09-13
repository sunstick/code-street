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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *node = head;
        ListNode *prev = &dummy;

        ListNode *l1;
        ListNode *mth;
        int cur = 1;

        while (node) {
            if (cur > m && cur < n) {
                // move node and prev
                ListNode *temp = node -> next;
                node -> next = prev;
                prev = node;
                node = temp;
                // move node and prev
            } else if (cur == m) {
                mth = node;
                l1 = prev;
                prev = node;
                node = node -> next;
            } else if (cur == n) {
                l1 -> next = node;
                mth -> next = node -> next;
                // move node and prev
                ListNode *temp = node -> next;
                node -> next = prev;
                prev = node;
                node = temp;
                // move node and prev
            } else {
                prev = node;
                node = node -> next;
            }


            cur++;
        }

        return dummy.next;
    }
};