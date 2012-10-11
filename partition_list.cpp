/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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