class Solution {
public:
    void solve(int offset, string str, string prev, vector<string> &res) {
        if (str == "") return ;

        if (offset == 3) {
            if (str[0] == '0' && str.size() > 1)
                return ;
            int v = atoi(str.c_str());

            if (v >= 0 && v <= 255)
                res.push_back(prev + str);
            return ;
        }
        int x = str.size();
        int n = min(3, x);

        for (int i = 1; i <= n; i++) {
            string sub = str.substr(0, i);
            if (sub[0] == '0' && i > 1) break;
            int v = atoi(sub.c_str());
            if (v > 255)
                break;
            solve(offset + 1, str.substr(i), prev + sub + ".", res);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;

        solve(0, s, "", res);

        return res;
    }
};
