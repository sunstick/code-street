/*
  Find all paths whose sum is a certain value.
 */

bool hasPathSum(TreeNode *node, int target) {
    target -= node->value;
    if (!node->left && !node->right) {
        if (target == 0)
            return true;
        return false;
    }

    if (node -> left)
        if (hasPathSum(node->left, target))
            return true;

    if (node -> right)
        if (hasPathSum(node->right, target))
            return true;

    return false;
    // conceptually equivalent to return (hasPathSum(node->left, target) || hasPathSum(node->right, target))
}

void test() {
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5, node4);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node12 = new TreeNode(12, NULL, node7);

    root = new TreeNode(10, node5, node12);
    cout << hasPathSum(root, 6) << endl;
}
