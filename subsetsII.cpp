class Solution {
public:

    void solve(vector<vector<int> > &res, vector<int> &v, int off, vector<int> &s) {
        if (off == s.size()) {
            if (find(res.begin(), res.end(), v) == res.end()) {
                res.push_back(v);
            }
            return ;
        }

        solve(res, v, off + 1, s);
        v.push_back(s[off]);
        solve(res, v, off + 1, s);
        v.pop_back();
    }

    vector<vector<int> > subsetsWithDup(vector<int> &s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(s.begin(), s.end());

        vector<int> v;
        vector<vector<int> > res;

        solve(res, v, 0, s);

        return res;
    }
};