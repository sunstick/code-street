#include <iostream>
#include <algorithm>

using namespace std;

int m, n, a, b;
int father[30010];
int rank[30010];
int numelem[30010];

void make_set(int x) {
    father[x] = x;
    rank[x] = 0;
    numelem[x] = 1;
}

int find_set(int x) {
    if (x != father[x])
        father[x] = find_set(father[x]);
    return father[x];
}

int union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y)
        return numelem[x];
    if (rank[x] > rank[y]) {
        father[y] = x;
        numelem[x] += numelem[y];
        return numelem[x];
    } else {
        if (rank[x] == rank[y])
            rank[y]++;
        father[x] = y;
        numelem[y] += numelem[x];
        return numelem[y];
    }
}

int main() {
    int test;
    cin >> test;

    while (test-- > 0) {
        cin >> n;
        cin >> m;
        for (int i = 1; i <= n; i++)
            make_set(i);
        int maxnum = -1;
        while (m-- > 0) {
            cin >> a;
            cin >> b;
            maxnum = max(maxnum, union_set(a, b));
        }

        cout << maxnum << endl;
    }
    return 0;
}
