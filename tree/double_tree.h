/*
For each node in the binary search tree, create a new duplicate node,
and insert the duplicate as the left child of the original node.
The resulting tree should still be a binary search tree
*/

void double_tree(TreeNode *node) {
    if (!node)
        return;

    TreeNode *newNode = new TreeNode(node->value, node->left, NULL);
    node->left = newNode;

    double_tree(newNode->left);
    double_tree(node->right);
}