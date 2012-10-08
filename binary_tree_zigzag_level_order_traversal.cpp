/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        queue<pair<TreeNode *, int> > q;
        int level = 0;
        vector<vector<int> > res;
        vector<int> t;

        if (root)
            q.push(make_pair(root, 0));

        while (!q.empty()) {
            TreeNode *current = q.front().first;
            int d = q.front().second;
            q.pop();

            if (d > level) {
                if (level % 2 == 1) reverse(t.begin(), t.end());
                res.push_back(t);
                t.clear();
                level ++;
            }

            t.push_back(current -> val);

            if (current -> left) q.push(make_pair(current -> left, d + 1));
            if (current -> right) q.push(make_pair(current -> right, d + 1));
        }

        if (t.size() > 0) {
            if (level % 2 == 1) reverse(t.begin(), t.end());
            res.push_back(t);
        }
        return res;
    }
};