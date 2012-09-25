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