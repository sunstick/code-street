#include <iostream>
#include <cstring>
#include <string>
#include <utility>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<pair<int, string> > vp;

bool myfunction (pair<int, string> p1, pair<int, string> p2) {
    return (p1.first < p2.first);
}

int main() {
    freopen("data.in", "rw", stdin);
    string line1, line2;
    int n;
    cin >> n;
    getchar();

    for (int i = 0; i < n; i++) {
        stringstream s1, s2;
        vp.clear();
        getline(cin, line1);
        getline(cin, line1);
        getline(cin, line2);
        s1 << line1;
        s2 << line2;
        int x;
        string y;

        while (s1 >> x) {
            s2 >> y;
            pair<int, string> p = make_pair(x, y);
            vp.push_back(p);
        }

        sort(vp.begin(), vp.end(), myfunction);

        for (vector<pair<int, string> >::iterator it = vp.begin(); it != vp.end(); it++)
            cout << (*it).second << endl;
        if (i < n - 1)
            cout << endl;
    }
    return 0;
}
