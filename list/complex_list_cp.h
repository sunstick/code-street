/*
 Copy of complex lists
*/

struct ComplexNode {
    int value;
    ComplexNode *next;
    ComplexNode *sibling;
    ComplexNode(int v, ComplexNode *n, ComplexNode *s): value(v), next(n), sibling(s) {}
};

ComplexNode *clone(ComplexNode *head) {
    map<ComplexNode *, ComplexNode *> hash;
    ComplexNode *curr = head;
    ComplexNode dummy(0, NULL, NULL);
    ComplexNode *tail = &dummy;

    while (curr) {
        tail -> next = new ComplexNode(curr -> value, NULL, NULL);
        tail = tail -> next;
        hash[curr] = tail;
        curr = curr -> next;
    }

    curr = head;
    tail = dummy.next;
    while (curr) {
        if (curr -> sibling)
            tail -> sibling = hash[curr -> sibling];
        curr = curr -> next;
        tail = tail -> next;
    }

    return dummy.next;
}

void test() {
    ComplexNode *n5 = new ComplexNode(5, NULL, NULL);
    ComplexNode *n4a = new ComplexNode(4, n5, NULL);
    ComplexNode *n4 = new ComplexNode(4, n4a, NULL);
    ComplexNode *n3 = new ComplexNode(3, n4, NULL);
    ComplexNode *n2 = new ComplexNode(2, n3, NULL);
    ComplexNode *n1 = new ComplexNode(1, n2, NULL);

    n1 -> sibling = n2;
    n2 -> sibling = n4;
    n3 -> sibling = n4a;
    n4 -> sibling = n5;
    n4a-> sibling = NULL;
    n5 -> sibling = n3;

    ComplexNode *head = clone(n1);
    ComplexNode *curr = head;
    while (curr) {
        cout << curr->value << " ";
        if (curr -> sibling)
            cout << curr -> sibling -> value;
        cout << endl;
        curr = curr -> next;
    }
}
