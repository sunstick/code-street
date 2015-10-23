#include <iostream>
#include <set>
#include <cstdio>
#include <cctype>

using namespace std;

int father[500];
int rank[500];
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
    int n;
    string line;

    cin >> n; getchar();
    getchar();
    while (n-- > 0) {
        getline(cin, line);
        char x = line[0];
        for (int i = 'A'; i <= x; i++)
            make_set(i);

        while (getline(cin, line) && line != "") {
            union_set(line[0], line[1]);
        }

        for (int i = 'A'; i <= x; i++)
            re.insert(find_set(i));
        cout << re.size() << endl;
        if (n)
            cout << endl;
        re.clear();
    }
    return 0;
}
