/*
  Reverse a linked list by block size.
  For example, if the block size is 3 and the list is [1,2,3,4,5,6,7,8],
  the returned list would be [3,2,1,6,5,4,8,7]
 */
/*
  Note this problem is different from the LeetCode problem "reverse nodes in k groups".
  In that problem, if the number of nodes is not a multiple of k, the left-out nodes in the end should remain what it is.
 */

#include "list_util.h"

ListNode *block_reverse(ListNode *head, int block_size) {
    ListNode dummy(0, NULL);
    ListNode *begin = &dummy;
    ListNode *end = &dummy;
    ListNode *node = head;

    int i = 1;

    while (node) {
        if (begin == end)
            end = node;
        ListNode *temp = node -> next;
        node -> next = begin -> next;
        begin -> next = node;
        node = temp;
        if (i % block_size == 0) {
            begin = end;
        }
        i++;
    }

    return dummy.next;
}

void test() {
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    print_list(head);

    head = block_reverse(head, 2);

    print_list(head);
}
