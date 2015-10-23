#include <iostream>
#include <set>

using namespace std;

int m, n, a, b;
int father[50010];
int rank[50010];
set<int> re;

void make_set(int x) {
    father[x] = x;
    rank[x] = 0;
}

int find_set(int x) {
    if (x != father[x])
        father[x] = find_set(father[x]);
    return father[x];
}

void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y)
        return ;
    if (rank[x] > rank[y]) {
        father[y] = x;
    } else {
        if (rank[x] == rank[y])
            rank[y]++;
        father[x] = y;
    }
}

int main() {
    int casen = 1;
    while (cin >> n && cin >> m && m) {
        for (int i = 1; i <= n; i++)
            make_set(i);

        while (m-- > 0) {
            cin >> a;
            cin >> b;
            union_set(a, b);
        }

        for (int i = 1; i <= n; i++)
            re.insert(find_set(i));

        cout << "Case " << casen << ": " << re.size() << endl;
        casen++;
        re.clear();
    }
    return 0;
}
