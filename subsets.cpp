/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    void solve(int x, vector<vector<int> > &res, vector<int> &s) {
        vector<int> v;
        for (int i = 0; i < s.size(); i++)
            if (x & (1 << i))
                v.push_back(s[i]);
        sort(v.begin(), v.end());
        res.push_back(v);
    }

    vector<vector<int> > subsets(vector<int> &s) {
        int n = s.size();
        vector<vector<int> > res;

        for (int i = 0; i < (1 << n); i++) {
            solve(i, res, s);
        }

        return res;
    }
};

class Solution {
public:

    void solve(vector<vector<int> > &res, vector<int> &v, int off, vector<int> &s) {
        if (off == s.size()) {
            res.push_back(v);
            return ;
        }

        solve(res, v, off + 1, s);
        v.push_back(s[off]);
        solve(res, v, off + 1, s);
        v.pop_back();
    }

    vector<vector<int> > subsets(vector<int> &s) {
        sort(s.begin(), s.end());

        vector<int> v;
        vector<vector<int> > res;

        solve(res, v, 0, s);

        return res;
    }
};