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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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