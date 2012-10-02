/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

public class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length() + 1;
        int n = word2.length() + 1;

        int[][] dp = new int[m][n];
        dp[0][0] = 0;

        for (int i = 1; i < m; i++)
            dp[i][0] = i;

        for (int i = 1; i < n; i++)
            dp[0][i] = i;

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                int add = 0;
                if (word1.charAt(i) != word2.charAt(j)) {
                    add = 1;
                }
                dp[i + 1][j + 1] = Math.min(Math.min(dp[i][j] + add, dp[i + 1][j] + 1), dp[i][j + 1] + 1);
            }
        }

        return dp[m - 1][n - 1];
    }
}