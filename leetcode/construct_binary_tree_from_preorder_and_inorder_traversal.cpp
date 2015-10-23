/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, inorder, 0, inorder.size());
    }

    TreeNode *buildTree(vector<int> &preorder, int s1, vector<int> &inorder, int s2, int l) {
        if (l <= 0) return NULL;

        int target = preorder[s1];
        int i = 0;
        while (i < l) {
            if (inorder[i + s2] == target)
                break;
            i++;
        }

        i = i + s2;

        TreeNode *node = new TreeNode(target);
        node -> left = buildTree(preorder, s1 + 1, inorder, s2, i - s2);
        node -> right = buildTree(preorder, s1 + 1 + i - s2, inorder, i + 1, l - 1 - i + s2);

        return node;
    }
};