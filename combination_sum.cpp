class Solution {
public:
    void search_path(vector<vector<int> > &path, vector<int> &v, int **dp, int i, int j, vector<int> &a) {
        if (j == 0) {
            if (find(path.begin(), path.end(), v) == path.end())
                path.push_back(v);
            return ;
        }

        if (i <= 0) return ;

        if (dp[i][j] == 1 || dp[i][j] == 3 || dp[i][j] == 5 || dp[i][j] == 7) {
            v.push_back(a[i - 1]);
            search_path(path, v, dp, i - 1, j - a[i - 1], a);
            v.pop_back();
        }

        if (dp[i][j] == 2 || dp[i][j] == 3 || dp[i][j] == 6 || dp[i][j] == 7) {
            v.push_back(a[i - 1]);
            search_path(path, v, dp, i, j - a[i - 1], a);
            v.pop_back();
        }

        if (dp[i][j] == 4 || dp[i][j] == 5 || dp[i][j] == 6 || dp[i][j] == 7) {
            search_path(path, v, dp, i - 1, j, a);
        }
    }
    vector<vector<int> > combinationSum(vector<int> &a, int target) {
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());

        int n = a.size();
        int **dp = new int*[n + 1];

        for (int i = 0; i <= n; i++) {
            dp[i] = new int[target + 1];
            memset(dp[i], 0, sizeof(dp[i]));
        }

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = 0;

                if (a[i - 1] <= j) {
                    if (dp[i - 1][j - a[i - 1]])
                        dp[i][j] += 1;

                    if (dp[i][j - a[i - 1]])
                        dp[i][j] += 2;

                    if (dp[i - 1][j])
                        dp[i][j] += 4;

                } else {
                    if (dp[i - 1][j])
                        dp[i][j] += 4;
                }

            }
        }

        vector<vector<int> > path;
        vector<int> v;

        for (int i = 1; i <= n; ++i) {
            if (dp[i][target])
                search_path(path, v, dp, i, target, a);
        }

        return path;
    }
};