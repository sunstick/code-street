/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

// Firstly tried using recursive backtracking, passed Judge Small but got TLE in Judge Large
/*
class Solution {
public:
    bool interleave(string &a, string &b, string &c, int off1, int off2, int off3) {
        if (a.size() + b.size() != c.size()) return false;

        if (off3 == c.size() && off1 == a.size() && off2 == b.size())
            return true;

        if (off1 < a.size() && a[off1] == c[off3])
            if (interleave(a, b, c, off1 + 1, off2, off3 + 1))
                return true;

        if (off2 < b.size() && b[off2] == c[off3])
            if (interleave(a, b, c, off1, off2 + 1, off3 + 1))
                return true;

        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        return interleave(s1, s2, s3, 0, 0, 0);
    }
};
*/


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        int m = s1.size();
        int n = s2.size();

        bool dp[m + 1][n + 1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
                if (i > 0 && s3[i + j - 1] == s1[i - 1])
                    dp[i][j] |= dp[i - 1][j];
                if (j > 0 && s3[i + j - 1] == s2[j - 1])
                    dp[i][j] |= dp[i][j - 1];
            }
        }

        return dp[m][n];
    }
};
