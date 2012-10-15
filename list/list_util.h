// list operations
#ifndef LIST_UTIL_H
#define LIST_UTIL_H

struct ListNode {
    int value;
    ListNode *next;
    ListNode(int v = 0, ListNode *n = NULL): value(v), next(n) {}
};

ListNode *head;

void print_list(ListNode *node) {
    while (node) {
        cout << node -> value << " ";
        node = node -> next;
    }

    cout << endl;
}

int length(ListNode *node) {
    int res = 0;
    while (node) {
        res++;
        node = node -> next;
    }
    return res;
}

int count(ListNode *node, int target) {
    int res = 0;
    while (node) {
        if (node -> value == target)
            res++;
        node = node -> next;
    }
    return res;
}

ListNode *getNth(ListNode *node, int n) { // 0 based
    int i = 0;
    while (node) {
        if (i == n)
            return node;
        node = node -> next;
    }

    return NULL;
}

ListNode *getLastNth(ListNode *node, int n) { // n == 1 indicates last element, and so on
    ListNode *fast = node;
    int i = 0;
    while (fast && i++ < n) {
        fast = fast -> next;
    }

    while (fast) {
        fast = fast -> next;
        node = node -> next;
    }

    return node;
}

void delete_list(ListNode **nodeRef) {
    if (*nodeRef == NULL) return ;

    delete_list(&((*nodeRef) -> next));

    delete *nodeRef;
    *nodeRef = NULL;
}

ListNode *insert(ListNode *node, int pos, ListNode *new_node) { // node is head of list
    ListNode dummy(0, node);
    ListNode *tail = &dummy;

    int i = 0;
    while (node && i < pos) {
        tail = tail -> next;
        node = node -> next;
    }

    tail -> next = new_node;
    new_node -> next = node;

    return dummy.next;
}

void push(ListNode **headRef, int val) {
    ListNode *newNode = new ListNode(val, *headRef);
    *headRef = newNode;
}

#endif