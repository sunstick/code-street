struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v = 0, TreeNode *l = NULL, TreeNode *r = NULL): value(v), left(l), right(r) {}
};

TreeNode *root;

void preorder(TreeNode *node) {
    if (node) {
        cout << node -> value << " ";
        preorder(node -> left);
        preorder(node -> right);
    }
}

void inorder(TreeNode *node) {
    if (node) {
        inorder(node -> left);
        cout << node -> value << " ";
        inorder(node -> right);
    }
}

void postorder(TreeNode *node) {
    if (node) {
        postorder(node -> left);
        postorder(node -> right);
        cout << node -> value << " ";
    }
}

TreeNode *left_most(TreeNode *node) {
    if (node -> left)
        return left_most(node -> left);
    return node;
}

TreeNode *right_most(TreeNode *node) {
    if (node -> right)
        return right_most(node -> right);
    return node;
}