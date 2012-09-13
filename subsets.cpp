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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(s.begin(), s.end());

        vector<int> v;
        vector<vector<int> > res;

        solve(res, v, 0, s);

        return res;
    }
};