string res = "";

class Solution {
public:
    void longString(string &s, int i, int j) {
        int n = s.size();

        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
        }

        if (res.size() < j - i - 1)
            res = s.substr(i + 1, j - i - 1);
    }

    string longestPalindrome(string s) {
        res = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {
            longString(s, i, i);
            if (i > 0)
                longString(s, i - 1, i);
        }

        return res;
    }
};