#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string files[130];

int main() {
    int n = 0;
    while (cin >> n) {
        int maxLen = -1;
        for (int i = 0; i < n; i++) {
            cin >> files[i];
            int s = files[i].size();
            maxLen = max(maxLen, s);
        }
        sort(files, files + n);
        int columns = 62 / (maxLen + 2);

        for (int i = 0; i < 60; i++)
            cout << "-";
        cout << endl;

        int rows = (n % columns == 0) ? n / columns : (n / columns + 1);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                int x = j * rows + i;
                if (x < n) {
                    cout << files[x];
                    int si = files[x].size();
                    int m = maxLen;
                    if (j < columns - 1)
                        m += 2;
                    for (int k = 0; k < m - si; k++)
                        cout << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
