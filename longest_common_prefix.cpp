class Solution {
public:
    bool is_same(vector<string> &strs, int k) {
        char c;
        for (int i = 0; i < strs.size(); i++) {
            if (k >= strs[i].size())
                return false;
            if (i == 0)
                c = strs[i][k];
            else {
                if (strs[i][k] != c)
                    return false;
            }
        }

        return true;
    }
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.size() == 0) return "";
        int s = 0;

        while (true) {
            if (is_same(strs, s)) s++;
            else break;
        }
        return strs[0].substr(0, s);
    }
};