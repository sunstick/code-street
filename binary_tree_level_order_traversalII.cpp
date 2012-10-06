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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
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
                level ++;
                res.push_back(t);
                t.clear();
            }

            t.push_back(current -> val);

            if (current -> left) q.push(make_pair(current -> left, d + 1));
            if (current -> right) q.push(make_pair(current -> right, d + 1));
        }

        if (t.size() > 0) res.push_back(t);
        reverse(res.begin(), res.end());
        return res;
    }
};