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
    int n, x, speed, p;
    cin >> n;
    Forn(i, n) {
        int speed = 0;
        cin >> x;
        while (x--) {
            cin >> p;
            speed = max(speed, p);
        }

        cout << "Case " << (i + 1) << ": " << speed << endl;
    }

    return 0;
}