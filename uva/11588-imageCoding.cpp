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
    int cases, r, c, m, n;
    cin >> cases;
    for (int i = 1; i <= cases; i++) {
        cin >> r >> c >> m >> n;
        int maxsize = 0;
        int hash[256];
        memset(hash, 0, sizeof(hash));

        int size = r * c;
        while (size--) {
            char temp;
            cin >> temp;
            hash[temp]++;
            maxsize = max(maxsize, hash[temp]);
        }

        int res = 0;
        for (int j = 0; j < 256; j++) {
            if (hash[j] == maxsize)
                res += m * hash[j];
            else if (hash[j])
                res += n * hash[j];
        }

        cout << "Case " << i << ": " << res << endl;
    }
    return 0;
}