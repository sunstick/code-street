/*
Return number of duplicates in a given binary search tree.

For example,
     2
   /   \
  1     3
   \   / \
    2 2   3
           \
            4
*/

#include "tree_util.h"

TreeNode *bst_dups(TreeNode *node, TreeNode *prev, int &res) {
    if (!node) return prev;

    TreeNode *left = bst_dups(node -> left, prev, res);

    if (left && left -> value == node -> value)
        res++;

    TreeNode *right = bst_dups(node -> right, node, res);

    return right;
}

void test() {
    TreeNode *node2 = new TreeNode(2, NULL, NULL);
    TreeNode *node1 = new TreeNode(1, NULL, node2);

    TreeNode *node4 = new TreeNode(4, NULL, NULL);
    TreeNode *node3 = new TreeNode(3, NULL, node4);
    TreeNode *node2r = new TreeNode(2, NULL, NULL);
    TreeNode *node3r = new TreeNode(3, node2r, node3);

    TreeNode *node2m = new TreeNode(2, node1, node3r);

    int res = 0;
    bst_dups(node2m, NULL, res);
    cout << res << endl;
}