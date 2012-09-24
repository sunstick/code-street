/*
  append list b onto the list a
*/

#include "list_util.h"

void append_b_to_a(ListNode *a, ListNode *b) {
    assert(a);

    while (a -> next) {
        a = a -> next;
    }

    a-> next = b;
    b = NULL;
}