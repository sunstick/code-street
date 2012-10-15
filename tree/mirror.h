/*
 Given a binary search tree(BST), convert it into its mirror
 */

void convert(TreeNode *node) {
    if (node == NULL)
        return ;
    TreeNode *temp = node -> left;
    node -> left = node -> right;
    node -> right = temp;
    convert(node -> left);
    convert(node -> right);
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
    inorder(root);
    cout << endl;
    convert(root);
    inorder(root);
    cout << endl;
}
