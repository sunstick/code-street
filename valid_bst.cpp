/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *node, int minv, int maxv) {
        if (!node)
            return true;
        int val = node -> val;
        if (val >= minv && val <= maxv)
            return isValidBST(node->left, minv, val - 1) && isValidBST(node->right, val + 1, maxv);
        else
            return false;
    }
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
};