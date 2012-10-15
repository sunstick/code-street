/**
Given a binary tree

struct Node {
  Node* leftChild;
  Node* rightChild;
  Node* nextRight;
}

Populate the nextRight pointers in each node.
*/

#include <iostream>

using namespace std;

struct node_t {
    int value;
    node_t *left;
    node_t *right;
    node_t *next;
    node_t(node_t *l, node_t *r, node_t *n, int v): left(l), right(r), next(n), value(v) {}
};

void connect(node_t *node) {
    if (!node)
        return ;

    node_t *node1 = node;

    while (node1) {
        node_t *p = node1 -> next;

        while (p && !(p -> left || p -> right))
            p = p -> next;

        node_t *res;

        if (p)
            res = p -> left ? p -> left : p -> right;
        else
            res = NULL;

        if (node1 -> right)
            node1 -> right -> next = res;
        if (node1 -> left)
            node1 -> left -> next = node1 -> right ? node1 -> right : res;

        node1 = node1 -> next;
    }

    if (node -> left)
        connect(node -> left);
    else
        connect(node -> right);
}

int main() {
    node_t node1(NULL, NULL, NULL, 1);
    node_t node2(NULL, NULL, NULL, 2);
    node_t node3(NULL, NULL, NULL, 3);
    node_t node4(NULL, &node1, NULL, 4);
    node_t node5(&node4, NULL, NULL, 5);
    node_t node6(&node2, &node3, NULL, 6);
    node_t node7(&node5, NULL, NULL, 7);
    node_t node8(NULL, NULL, NULL, 8);
    node_t node9(NULL, &node6, NULL, 9);
    node_t node10(NULL, &node7, NULL, 10);
    node_t node11(&node8, &node9, NULL, 11);
    node_t node12(NULL, NULL, NULL, 12);
    node_t node13(&node10, NULL, NULL, 13);
    node_t node14(&node11, &node12, NULL, 14);
    node_t node15(&node13, &node14, NULL, 15);

    connect(&node15);

    cout << node4.next -> value << endl; // 2
    cout << node2.next -> value << endl; // 3
    cout << node5.next -> value << endl; // 6
    cout << node7.next -> value << endl; // 8
    cout << node8.next -> value << endl; // 9
    cout << node10.next -> value << endl; // 11
    cout << node11.next -> value << endl; // 12
    cout << node13.next -> value << endl; // 14

    cout << (node1.next == NULL) << endl;
    cout << (node3.next == NULL) << endl;
    cout << (node6.next == NULL) << endl;
    cout << (node9.next == NULL) << endl;
    cout << (node12.next == NULL) << endl;
    cout << (node14.next == NULL) << endl;
    cout << (node15.next == NULL) << endl;
    return 0;
}
