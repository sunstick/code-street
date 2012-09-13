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