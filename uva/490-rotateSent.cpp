#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

string data[105];
int n = 0;

int main() {
    int maxn = 0;

    while (getline(cin, data[n])) {
        int temp = data[n].size();
        maxn = max(maxn, temp);
        n++;
    }

    for (int j = 0; j < maxn; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (j < data[i].size())
                cout << data[i][j];
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
