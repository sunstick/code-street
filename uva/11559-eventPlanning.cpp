#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>

#define For(i, a, b) for( int i = (a); i < (b); i++ )
#define Forn(i, n) For(i, 0, n)
#define Foreach(it, x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)

using namespace std;

int main() {
    int n, b, h, w, p, spots;
    while (cin >> n >> b >> h >> w) {
        int cost = b + 1;

        while (h--) {
            cin >> p;
            for (int i = 0; i < w; i++) {
                cin >> spots;
                if (spots >= n)
                    cost = min(cost, n * p);
            }
        }
        if (cost == b + 1)
            cout << "stay home" << endl;
        else
            cout << cost << endl;
    }

    return 0;
}