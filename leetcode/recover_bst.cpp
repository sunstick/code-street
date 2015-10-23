/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    void inorder(TreeNode *node, vector<TreeNode *> &v) {
        if (!node) return ;
        inorder(node -> left, v);
        v.push_back(node);
        inorder(node -> right, v);
    }
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode *> v;
        inorder(root, v);

        int prev = INT_MIN;
        int x = -1;
        int y = 0;

        for (int i = 0; i < v.size(); i++) {
            if (v[i] -> val >= prev)
                prev = v[i] -> val;
            else {
                x = i - 1;
                y = i;
                break;
            }
        }

        for (int i = y + 1; i < v.size(); i++) {
            if (v[i] -> val <= v[y] -> val) {
                y = i;
                break;
            }
        }

        swap(v[x] -> val, v[y] -> val);

    }
};