/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

void solve(vector<int> &s, int off, int n, int start, int k, vector<vector<int> > &res) {
    if (off == k) {
        res.push_back(s);
        return ;
    }

    for (int i = start + 1; i <= n; i++) {
        s[off] = i;
        solve(s, off + 1, n, i, k, res);
    }
}

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> s(k);
        solve(s, 0, n, 0, k, res);
        return res;
    }
};