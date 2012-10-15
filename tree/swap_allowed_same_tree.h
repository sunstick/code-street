/*
If we allow a node to swap its left or right node, write a function to tell if two trees are the same.
For example,
  1
2   3
is same with
  1
3   2

return the number of necessary swapping operations
*/

#define MAX_SWAP -1

int swapIdentical(TreeNode *a, TreeNode *b) {
    if (a && !b)
        return MAX_SWAP;
    if (b && !a)
        return MAX_SWAP;
    if (!a && !b)
        return 0;

    if (a -> value != b -> value)
        return MAX_SWAP;

    int leftNoSwap = swapIdentical(a -> left, b -> left);
    int rightNoSwap = swapIdentical(a -> right, b -> right);

    if (leftNoSwap != MAX_SWAP && rightNoSwap != MAX_SWAP)
        return leftNoSwap + rightNoSwap;

    int leftWithSwap = swapIdentical(a -> left, b -> right);
    int rightWithSwap = swapIdentical(a -> right, b -> left);

    if (leftWithSwap != MAX_SWAP && rightWithSwap != MAX_SWAP)
        return leftWithSwap + rightWithSwap + 1;

    return MAX_SWAP;
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

    TreeNode *t_node1 = new TreeNode(1, NULL, NULL);
    TreeNode *t_node3 = new TreeNode(3, NULL, t_node1);
    TreeNode *t_node5 = new TreeNode(5, NULL, NULL);
    TreeNode *t_node4 = new TreeNode(4, t_node5, t_node3);
    TreeNode *t_node8 = new TreeNode(8, NULL, NULL);
    TreeNode *t_node12 = new TreeNode(12, NULL, NULL);
    TreeNode *t_node16 = new TreeNode(16, NULL, NULL);
    TreeNode *t_node6 = new TreeNode(6, t_node8, t_node4);
    TreeNode *t_node14 = new TreeNode(14, t_node16, t_node12);
    TreeNode *t_root = new TreeNode(10, t_node6, t_node14);

    cout << swapIdentical(root, t_root) << endl;

    inorder(root);
    cout << endl;

    inorder(t_root);
    cout << endl;
    postorder(root);
    cout << endl;
    postorder(t_root);
    cout << endl;
}
