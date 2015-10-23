// subset sum problem

#include <iostream>
#include <sstream>

using namespace std;

int dp[30][300];
int a[30];

void solve(int *a, int n, int b) {
    memset(dp, 0, sizeof(dp));
    dp[0][a[0]] = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= b; ++j) {
            if (j > a[i])
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - a[i]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
}

int main(int argc, char const *argv[]) {
    int m = 0;
    cin >> m;
    cin.ignore(100, '\n');
    while (m--) {
        stringstream ss;
        int sum = 0;
        string str;

        getline(cin, str);
        ss << str;

        int n = 0;
        while (ss >> a[n]) sum += a[n++];

        if (sum % 2) cout << "NO" << endl;
        else {
            sum /= 2;
            solve(a, n, sum);
            if (dp[n - 1][sum])  cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}