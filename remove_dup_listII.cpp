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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head) return head;

        ListNode dummy(0);
        ListNode *tail = &dummy;
        tail -> next = NULL;

        ListNode *node = head;

        while (node) {
            ListNode *prev = node;
            node = node -> next;

            if (!node) {
                tail -> next = prev;
                tail = tail -> next;
                tail -> next = NULL;
                break;
            }

            if (node -> val == prev -> val) {
                while (node && node -> val == prev -> val)
                    node = node -> next;
            } else {
                tail -> next = prev;
                tail = tail -> next;
                tail -> next = NULL;
            }
        }


        return dummy.next;
    }
};
