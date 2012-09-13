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