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

/*
The in-place partition operation for linked lists is much simpler than it for arrays.

Can you think of other operations that are simpler/faster on linked lists than they on arrays?
rotate operation, merge sort (because sorted_merge on linked lists doesn't require additional buffer)

*/