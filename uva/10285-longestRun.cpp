#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int n, r, c, maxElement;
int data[110][110];
string area;

void floodFill(int i, int j, int val) {
    maxElement = max(maxElement, val);

    if (data[i][j] < data[i + 1][j])
        floodFill(i + 1, j, val + 1);

    if (data[i][j] < data[i - 1][j])
        floodFill(i - 1, j, val + 1);

    if (data[i][j] < data[i][j + 1])
        floodFill(i, j + 1, val + 1);

    if (data[i][j] < data[i][j - 1])
        floodFill(i, j - 1, val + 1);
}

int main() {
    cin >> n;
    while (n-- > 0) {
        memset(data, -1, sizeof(data));
        maxElement = 0;
        cin >> area >> r >> c;

        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                cin >> data[i][j];

        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                floodFill(i, j, 1);

        cout << area << ": " << maxElement << endl;
    }

    return 0;
}
