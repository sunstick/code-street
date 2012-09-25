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
    bool mirrored(TreeNode *left, TreeNode *right) {
        if (left && !right) return false;
        if (!left && right) return false;
        if (!left && !right) return true;

        if (left -> val != right -> val) return false;
        return mirrored(left -> left, right -> right) && mirrored(left -> right, right -> left);
    }
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return mirrored(root -> left, root -> right);
    }
};