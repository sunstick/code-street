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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode dummy(0);
        ListNode *tail = &dummy;
        tail -> next = NULL;

        while (l1 && l2) {
            if (l1 -> val < l2 -> val) {
                tail -> next = l1;
                l1 = l1 -> next;
                tail = tail -> next;
                tail -> next = NULL;
            } else {
                tail -> next = l2;
                l2 = l2 -> next;
                tail = tail -> next;
                tail -> next = NULL;
            }
        }

        if (l1)
            tail -> next = l1;
        if (l2)
            tail -> next = l2;

        return dummy.next;
    }
};