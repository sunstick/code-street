/*
Given a binary tree, determine if it is height-balanced.
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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int height;
        return isBalanced(root, height);
    }

    bool isBalanced(TreeNode *node, int &height) {
        if (node == NULL) {
            height = 0;
            return true;
        }
        int left, right;
        if (!isBalanced(node -> left, left)) return false;
        if (!isBalanced(node -> right, right)) return false;

        height = max(left, right) + 1;
        return abs(left - right) <= 1;
    }
};