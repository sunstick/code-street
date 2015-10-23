#include <iostream>
#include <map>
#include <string>

using namespace std;

int m, n;
string f1, f2;

map<string, string> father;
map<string, int> rank;
map<string, int> numelem;

void make_set(string x) {
    if (father.count(x))
        return;

    father[x] = x;
    rank[x] = 0;
    numelem[x] = 1;
}

string find_set(string x) {
    if (x != father[x])
        father[x] = find_set(father[x]);
    return father[x];
}

int union_set(string x, string y) {
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
    cin >> n;
    while (n-- > 0) {
        cin >> m;
        while (m-- > 0) {
            cin >> f1;
            cin >> f2;
            make_set(f1);
            make_set(f2);
            cout << union_set(f1, f2) << endl;
        }
        father.clear();
        rank.clear();
        numelem.clear();
    }
    return 0;
}
