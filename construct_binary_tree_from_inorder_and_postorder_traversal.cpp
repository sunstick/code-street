/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode *buildTree(vector<int> &inorder, int s1, int t1, vector<int> &postorder, int s2, int t2) {
        if (s1 > t1 || s2 > t2) return NULL;

        int target = postorder[t2];

        int i = 0;

        for (i = s1; i <= t1; i++)
            if (inorder[i] == target)
                break;
        TreeNode *node = new TreeNode(target);
        node -> left = buildTree(inorder, s1, i - 1, postorder, s2, s2 + (i - 1 - s1));
        node -> right = buildTree(inorder, i + 1, t1, postorder, t2 - 1 - (t1 - i - 1), t2 - 1);
        return node;
    }
};