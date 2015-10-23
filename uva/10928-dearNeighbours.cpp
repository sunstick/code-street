#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

bool vp_cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

vector<pair<int, int> > vp;
string line;

int countSpace(string &str) {
    int count = 0;
    for (int i = 0; i < str.size(); i++)
        if (str[i] == ' ')
            count++;
    return count;
}

int main() {
    int n = 0;
    int p = 0;
    cin >> n;
    while (n -- > 0) {
        cin >> p; getchar();
        for (int i = 1; i <= p; i++) {
            getline(cin, line);
            vp.push_back(make_pair(i, countSpace(line) + 1));
        }

        sort(vp.begin(), vp.end(), vp_cmp);

        int x = vp.begin() -> second;

        vector<pair<int, int> >::iterator it = vp.begin();
        int v = 0;
        while (it != vp.end()) {
            if (it -> second == x) {
                if (!v) {
                    cout << it -> first;
                    v++;
                } else
                    cout << ' ' << it -> first;
                it++;
            } else
                break;
        }
        cout << endl;
        vp.clear();
    }
    return 0;
}
