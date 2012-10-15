#ifndef LIST_UTIL_H
#define LIST_UTIL_H

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


int size(TreeNode *node) {
    if (!node)
        return 0;

    return size(node -> left) + size(node -> right) + 1;
}

int minDepth(TreeNode *node) {
    if (!node->left && !node->right)
        return 1;

    int d1 = -1;
    int d2 = -1;

    if (node -> left)
        d1 = minDepth(node -> left) + 1;
    if (node -> right)
        d2 = minDepth(node -> right) + 1;

    if (d1 == -1)
        return d2;
    if (d2 == -1)
        return d1;
    return min(d1, d2);
}

int maxDepth(TreeNode *node) {
    if (!node)
        return 0;
    return max(maxDepth(node -> left), maxDepth(node -> right)) + 1;
}

int minValue(TreeNode *node) {
    int l = node->value, r = node->value;

    if (node -> left)
        l = min(minValue(node -> left), l);
    if (node -> right)
        r = min(minValue(node -> right), r);

    return min(l, r);
}

static void printPathsCur(TreeNode *node, int path[], int cur) {
    if (!node)
        return ;

    path[cur] = node -> value;
    if (!node->left && !node->right) {
        for (int i = 0; i <= cur; i++)
            cout << path[i] << " ";
        cout << endl;
        return ;
    }

    if (node -> left)
        printPathsCur(node -> left, path, cur + 1);
    if (node -> right)
        printPathsCur(node -> right, path, cur + 1);
}

void printPaths(TreeNode *node) {
    int path[1000];
    printPathsCur(node, path, 0);
}

bool identical(TreeNode *a, TreeNode *b) {
    if (!a && !b)
        return true;
    if (a && !b)
        return false;
    if (!a && b)
        return false;

    if (a->value != b->value)
        return false;
    return identical(a->left, b->left) && identical(a->right, b->right);
}
#endif