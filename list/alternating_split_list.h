/*
  The function takes one list and split it into two smaller ones.
  Sublists should be made from alternating elements in the original list.
 */

void alternatingSplit(ListNode *head, ListNode **aRef, ListNode **bRef) {
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