class Solution {
public:
    void search_path(vector<vector<int> > &path, int **dp, vector<int> &v, int i, int j, vector<int> &num) {
        if (j == 0) {
            if (find(path.begin(), path.end(), v) == path.end())
                path.push_back(v);
            return ;
        }

        if (i <= 0) return ;

        if (dp[i][j] == 3 || dp[i][j] == 2) {
            search_path(path, dp, v, i - 1, j, num);
        }

        if (dp[i][j] == 3 || dp[i][j] == 1) {
            v.push_back(num[i - 1]);
            search_path(path, dp, v, i - 1, j - num[i - 1], num);
            v.pop_back();
        }
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        reverse(num.begin(), num.end());
        int n = num.size();
        int **dp = new int*[n + 1];

        for (int i = 0; i <= n; i++) {
            dp[i] = new int [target + 1];
            memset(dp[i], 0, sizeof(dp[i]));
        }

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = 0;
                if (j >= num[i - 1]) {
                    if (dp[i - 1][j - num[i - 1]])
                        dp[i][j] += 1;
                    if (dp[i - 1][j])
                        dp[i][j] += 2;
                } else {
                    if (dp[i - 1][j])
                        dp[i][j] += 2;
                }
            }
        }

        vector<vector<int> > path;
        vector<int> v;

        for (int i = 1; i <= n; ++i)
            if (dp[i][target])
                search_path(path, dp, v, i, target, num);


        return path;
    }
};