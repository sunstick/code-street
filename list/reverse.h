/*
  Reverse a list
 */

#include "list_util.h"

ListNode *reverse(ListNode *head) {
    ListNode *prev = NULL;
    ListNode *node = head;

    while (node) {
        ListNode *temp = node -> next;
        node -> next = prev;
        prev = node;
        node = temp;
    }

    return prev;
}

ListNode *reverse_cur(ListNode *head) {
    if (!(head -> next)) return head;

    ListNode *next = reverse_cur(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return next;
}

void reverse_cur2(ListNode **head_ref) {

}


void test() {
    ListNode *a = NULL;
    push(&a, 0);
    push(&a, 1);
    push(&a, 2);
    push(&a, 3);
    print_list(a);
    ListNode *b = reverse(a);
    print_list(b);

    a = reverse_cur(b);
    print_list(a);
}