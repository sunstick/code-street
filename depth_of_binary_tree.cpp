/*
Given a binary tree, find its depth (maximum height).
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
class Solution {
public:
    int maxHeight(TreeNode *root) {
        if (!root) return 0;
        return max(maxHeight(root -> left), maxHeight(root -> right)) + 1;
    }
};