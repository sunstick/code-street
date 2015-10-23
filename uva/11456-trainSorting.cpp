#include <iostream>
#include <cstring>

using namespace std;

int n;
int train[2010];
int dp[2][2010];

void solve(int *dp, bool flag) {
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (train[j] < train[i] == flag) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> train[n - i - 1];
        }

        memset(dp, 0, sizeof(dp));
        solve(dp[0], 0);
        solve(dp[1], 1);

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            ans = max(ans, dp[0][i] + dp[1][i] - 1);
        }
        cout << ans << endl;
    }
    return 0;
}