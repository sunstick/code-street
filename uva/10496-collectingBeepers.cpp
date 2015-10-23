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

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long

#define For(i, a, b) for( int i = (a); i < (b); i++ )
#define Forn(i, n) For(i, 0, n)
#define Rep(n) while(n-- > 0)
#define Foreach(it, x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Read(r) freopen(r, "r", stdin)
#define Write(w) freopen(w, "w", stdout)

using namespace std;

int n, m, orx, ory, xsize, ysize;
vector<pair<int, int> > points;

int dis() {
    pair<int, int> lastp = points[points.size() - 1];
    int sum = abs(orx - lastp.first) + abs(ory - lastp.second);
    int cmx = orx, cmy = ory;
    Foreach(it, points) {
        sum += abs(it->first - cmx) + abs(it->second - cmy);
        cmx = it->first;
        cmy = it->second;
    }
    return sum;
}

int main() {
    cin >> n;
    Rep(n) {
        cin >> xsize >> ysize >> orx >> ory;
        cin >> m;
        Rep(m) {
            int x, y;
            cin >> x >> y;
            points.push_back(make_pair(x, y));
        }

        sort(points.begin(), points.end());
        int shortest = INF_MAX;

        do {
            shortest = min(shortest, dis());
        } while (next_permutation(points.begin(), points.end()));
        cout << "The shortest path has length " << shortest << endl;
        points.clear();
    }
    return 0;
}
