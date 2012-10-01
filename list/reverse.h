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
    ListNode *node = *head_ref;
    if (!node) return ;

    ListNode *rest = node -> next;
    if (!rest) return ;

    reverse_cur2(&rest);
    node -> next -> next = node;
    node -> next = NULL;
    *head_ref = rest;
}

void test() {
    ListNode *a = NULL;
    ListNode *b = NULL;

    push(&a, 0);
    push(&a, 1);
    push(&a, 2);
    push(&a, 3);
    push(&a, 4);

    print_list(a);
    b = reverse(a);
    print_list(b);
    a = reverse_cur(b);
    print_list(a);
    reverse_cur2(&a);
    print_list(a);
}