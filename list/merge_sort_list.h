/*
 Implementation of merge sort of linked list.
 Key procedures are front_back_split and sorted merge
 */

ListNode *front_back_split(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head -> next;

    while (fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    ListNode *node = slow -> next;
    slow -> next = NULL;
    return node;
}

ListNode *sorted_merge(ListNode *head1, ListNode *head2) {
    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (head1 && head2) {
        if (head1 -> value < head2 -> value) {
            tail -> next = head1;
            head1 = head1 -> next;
        } else {
            tail -> next = head2;
            head2 = head2 -> next;
        }

        tail = tail -> next;
        tail -> next = NULL;
    }

    if (head1)
        tail -> next = head1;
    if (head2)
        tail -> next = head2;

    return dummy.next;
}

ListNode *merge_sort(ListNode *head) {
    if (!head || !(head -> next))
        return head;
    ListNode *front = head;
    ListNode *back = front_back_split(head);
    front = merge_sort(front);
    back = merge_sort(back);
    return sorted_merge(front, back);
}

void test() {
    // there are memory leaks in testing
    head = NULL;
    push(&head, 10);
    head = merge_sort(head);
    print_list(head);

    head = NULL;
    push(&head, 1);
    push(&head, 1);
    push(&head, 8);
    push(&head, -2);
    push(&head, 3);
    push(&head, 2);
    push(&head, -7);
    push(&head, 0);
}