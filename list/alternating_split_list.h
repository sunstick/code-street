/*
  The function takes one list and split it into two smaller ones.
  Sublists should be made from alternating elements in the original list.
 */

void alternating_split(ListNode *head, ListNode **aRef, ListNode **bRef) {
    ListNode dummyA, dummyB;
    ListNode *tailA = &dummyA;
    ListNode *tailB = &dummyB;

    ListNode *node = head;

    dummyA.next = NULL;
    dummyB.next = NULL;

    while (node) {
        tailA -> next = node;
        node = node -> next;
        tailA = tailA -> next;
        tailA -> next = NULL;

        if (node) {
            tailB -> next = node;
            node = node -> next;
            tailB = tailB -> next;
            tailB -> next = NULL;
        }
    }

    *aRef = dummyA.next;
    *bRef = dummyB.next;
}

ListNode *shuffle_merge(ListNode *a, ListNode *b) {
    ListNode dummy(0, NULL);
    ListNode *tail = &dummy;

    while (a && b) {
        tail -> next = a;
        a = a -> next;
        tail = tail -> next;
        tail -> next = b;
        b = b -> next;
        tail = tail -> next;
        tail -> next = NULL;
    }

    if (a) tail -> next = a;
    if (b) tail -> next = b;

    return dummy.next;
}

void test() {
    ListNode *a = NULL;
    ListNode *b = NULL;
    ListNode *ax = NULL;
    ListNode *bx = NULL;

    push(&b, 2);
    push(&b, 2);
    push(&b, 2);
    push(&b, 2);
    push(&b, 2);

    push(&a, 1);
    push(&a, 1);
    push(&a, 1);
    push(&a, 1);
    push(&a, 1);
    push(&a, 1);
    push(&a, 1);

    print_list(a);
    print_list(b);
    a = shuffle_merge(a, b);
    print_list(a);

    alternating_split(a, &ax, &bx);
    print_list(ax);
    print_list(bx);
}