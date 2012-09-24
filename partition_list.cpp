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
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy1(0);
        ListNode dummy2(0);
        ListNode *tail1 = &dummy1;
        ListNode *tail2 = &dummy2;

        while (head) {
            ListNode **tail;
            if (head -> val < x)
                tail = &tail1;
            else
                tail = &tail2;


            (*tail) -> next = head;
            head = head -> next;
            *tail = (*tail) -> next;
            (*tail) -> next = NULL;
        }

        tail1 -> next = dummy2.next;

        return dummy1.next;
    }
};