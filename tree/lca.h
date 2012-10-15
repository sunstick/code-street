/*
LCA problem of a binary tree
*/

TreeNode *lca(TreeNode *node, TreeNode *p, TreeNode *q) {
    if (!node)
        return NULL;
    if (node == p || node == q)
        return node;

    TreeNode *left = lca(node -> left, p, q);
    TreeNode *right = lca(node -> right, p, q);
    if (left && right)
        return node;
    return left ? left : right;
}

void test() {
    TreeNode *node1 = new TreeNode(1, NULL, NULL);
    TreeNode *node3 = new TreeNode(3, node1, NULL);
    TreeNode *node5 = new TreeNode(5, NULL, NULL);
    TreeNode *node4 = new TreeNode(4, node3, node5);
    TreeNode *node8 = new TreeNode(8, NULL, NULL);
    TreeNode *node12 = new TreeNode(12, NULL, NULL);
    TreeNode *node16 = new TreeNode(16, NULL, NULL);
    TreeNode *node6 = new TreeNode(6, node4, node8);
    TreeNode *node14 = new TreeNode(14, node12, node16);
    root = new TreeNode(10, node6, node14);

    TreeNode *nodes[] = {root, node1, node3, node5, node4, node8, node12, node16, node6, node14};

    for (int i = 0; i < 10; i++)
        for (int j = i + 1; j < 10; j++) {
            TreeNode *n = lca(root, nodes[i], nodes[j]);
            cout << nodes[i]->value << " and " << nodes[j]->value << " has the LCA ";
            cout << n->value << endl;
        }
}
