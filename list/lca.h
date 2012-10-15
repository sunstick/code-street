/*
 LCA problem of linked list
 */

ListNode *lca(ListNode *p, ListNode *q) {
    int dp1 = length(p);
    int dp2 = length(q);

    if (dp1 < dp2) {
        swap(dp1, dp2);
        swap(p, q);
    }

    int dp = dp1 - dp2;
    while (dp--)
        p = p -> next;

    while (p && q && p != q) {
        p = p -> next;
        q = q -> next;
    }

    return p == q ? q : NULL;
}

void test() {
    ListNode *node10 = new ListNode(10, NULL);
    ListNode *node9 = new ListNode(9, node10);
    ListNode *node8 = new ListNode(8, node9);
    ListNode *node7 = new ListNode(7, node8);
    ListNode *node6 = new ListNode(6, node7);
    ListNode *node5 = new ListNode(5, node6);
    ListNode *node4 = new ListNode(4, node5);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *node1 = new ListNode(1, node2);

    ListNode *nodes[] =
    {node1, node2, node3, node4, node5, node6, node7, node8, node9, node10};

    int n = sizeof(nodes) / sizeof(ListNode *);

    for (int i = 0; i < n; i++) {
        ListNode *cha = new ListNode(0, nodes[i]);
        for (int j = 0; j < 10; j++)
            cout << lca(cha, nodes[j]) -> value << " " << lca(nodes[j], cha) -> value << endl;
        cout << "-----" << endl;
    }

    ListNode *cha = new ListNode(0, NULL);
    for (int j = 0; j < 10; j++)
        cout << (lca(cha, nodes[j]) == NULL) << " " << (lca(nodes[j], cha) == NULL) << endl;
    cout << "-----" << endl;

}