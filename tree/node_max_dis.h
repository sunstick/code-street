/*
Find the maximum distance between two nodes in a binary tree.
*/

int maxDistance(TreeNode *node) {
    if (!node)
        return 0;
    int a = maxDepth(node -> left);
    int b = maxDepth(node -> right);

    int dis = a + b;

    a = maxDistance(node -> left);
    b = maxDistance(node -> right);

    dis = max(dis, a);
    dis = max(dis, b);

    return dis;
}

void test() {
    TreeNode *node1 = new TreeNode(1, NULL, NULL);
    TreeNode *node3 = new TreeNode(3, node1, NULL);
    TreeNode *node5 = new TreeNode(5, NULL, NULL);
    TreeNode *node4 = new TreeNode(4, node3, node5);
    TreeNode *node12 = new TreeNode(12, NULL, NULL);
    TreeNode *node16 = new TreeNode(16, NULL, NULL);
    TreeNode *node8 = new TreeNode(8, NULL, NULL);
    TreeNode *node6 = new TreeNode(6, node4, node8);
    TreeNode *node14 = new TreeNode(14, node12, node16);
    root = new TreeNode(10, node6, node14);

    cout << maxDistance(node1) << endl;
    cout << maxDistance(node3) << endl;
    cout << maxDistance(node5) << endl;
    cout << maxDistance(node4) << endl;
    cout << maxDistance(node12) << endl;
    cout << maxDistance(node16) << endl;
    cout << maxDistance(node14) << endl;
    cout << maxDistance(node6) << endl;
    cout << maxDistance(root) << endl;

}
