/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/

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