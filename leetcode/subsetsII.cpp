/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

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
        sort(s.begin(), s.end());

        vector<int> v;
        vector<vector<int> > res;

        solve(res, v, 0, s);

        return res;
    }
};

// What if we require all subsets are true set, i.e., no duplicates
/*
For example,
If S = [1,1,2,2], a solution is:
[
    [1,2],
    [1],
    [2],
    []
]
*/

class Solution {
public:
    int increase(vector<int> &num, int i) {
        int newi = i + 1;
        while (newi < num.size() && num[newi] == num[i])
            newi++;
        return newi;
    }

    void solve(vector<int> &s, vector<int> &t, vector<vector<int> > &res, int off) {
        if (off == s.size()) {
            res.push_back(t);
            return ;
        }

        t.push_back(s[off]);
        solve(s, t, res, increase(s, off));
        t.pop_back();
        solve(s, t, res, increase(s, off));
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> t;
        vector<vector<int> > res;

        solve(S, t, res, 0);

        return res;
    }
};