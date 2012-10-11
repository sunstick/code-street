/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

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
        if (strs.size() == 0) return "";
        int s = 0;

        while (true) {
            if (is_same(strs, s)) s++;
            else break;
        }
        return strs[0].substr(0, s);
    }
};