/*
Given a binary tree, return the inorder traversal of its nodes' values.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorder(TreeNode *node, vector<int> &res) {
    if (node) {
        inorder(node -> left, res);
        res.push_back(node->val);
        inorder(node -> right, res);
    }
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};