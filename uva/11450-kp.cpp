#include <iostream>
#include <cstring>

using namespace std;

int m;
int c;
int price[25][25];
int shopping[25][210];

void solve() {
    for (int i = 0; i <= c; ++i)
        for (int j = 0; j <= m; ++j)
            if (i == 0)
                shopping[i][j] = 0;
            else
                for (int k = 1; k <= price[i][0]; ++k)
                    if (j >= price[i][k] && shopping[i - 1][j - price[i][k]] != -1)
                        shopping[i][j] = max(shopping[i][j], shopping[i - 1][j - price[i][k]] + price[i][k]);
}

int main(int argc, char const *argv[]) {
    int t = 0;
    cin >> t;
    while (t--) {
        cin >> m >> c;
        for (int i = 1; i <= c; ++i) {
            cin >> price[i][0];
            for (int j = 1; j <= price[i][0]; ++j)
                cin >> price[i][j];
        }

        memset(shopping, -1, sizeof(shopping));

        solve();

        if (shopping[c][m] < 0)
            cout << "no solution" << endl;
        else
            cout << shopping[c][m] << endl;
    }
    return 0;
}