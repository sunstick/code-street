void solve(int off, int left, int right, string &sol, int n, vector<string> &res) {
    if (off == 2 * n) {
        res.push_back(sol);
        return ;
    }

    if (left < n) {
        sol.push_back('(');
        solve(off + 1, left + 1, right, sol, n, res);
        sol = sol.substr(0, sol.size() - 1);
    }

    if (right < left) {
        sol.push_back(')');
        solve(off + 1, left, right + 1, sol, n, res);
        sol = sol.substr(0, sol.size() - 1);
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string sol = "";
        vector<string> res;
        solve(0, 0, 0, sol, n, res);
        return res;
    }
};