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



class Solution {
public:
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

    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> s(k);
        solve(s, 0, n, 0, k, res);
        return res;
    }
};

// another way to solve this

class Solution {
public:
    void solve(vector<vector<int> > &res, vector<int> &temp, int off, int n, int k) {
        if (temp.size() == k) {
            res.push_back(temp);
            return ;
        }

        if (off <= n) {
            solve(res, temp, off + 1, n, k);
            temp.push_back(off);
            solve(res, temp, off + 1, n, k);
            temp.pop_back();
        }
    }

    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> temp;

        solve(res, temp, 1, n, k);

        return res;
    }
};