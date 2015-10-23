#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<string, int> psi;
vector<psi> vp;

bool myCmp(psi p1, psi p2) {
    return (p1.second < p2.second);
}

int sortness(string str) {
    int count = 0;
    for (int i = 0; i < str.size(); i++)
        for (int j = i + 1; j < str.size(); j++)
            if (str[i] > str[j])
                count ++;
    return count;
}

int main() {
    int n, m;
    string line;

    cin >> n;
    while (n-- > 0) {
        cin >> m;
        cin >> m;

        while (m-- > 0) {
            cin >> line;
            vp.push_back(make_pair(line, sortness(line)));
        }
        stable_sort(vp.begin(), vp.end(), myCmp);
        vector<psi>::iterator it = vp.begin();
        while (it != vp.end()) {
            cout << (*it).first << endl;
            it++;
        }
        vp.clear();
        if (n)
            cout << endl;
    }
    return 0;
}
