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
#define Fors(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fore(it, x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)

using namespace std;

int n, m, len;
string words[110], rule, res;

void solve(int cur) {
    if (cur == len) {
        cout << res << endl;
        return ;
    }
    char ch = rule[cur];
    if (ch == '#')
        For(i, 0, n) {
        int pos = res.size();
        res += words[i];
        solve(cur + 1);
        res = res.substr(0, pos);
    } else
        For(i, 0, 10) {
        res.push_back(i + '0');
        solve(cur + 1);
        res = res.substr(0, res.size() - 1);
    }
}

int main() {
    while (cin >> n) {
        For(i, 0, n)
        cin >> words[i];
        cin >> m;
        For(i, 0, m) {
            cout << "--" << endl;
            res = "";
            cin >> rule;
            len = rule.size();
            solve(0);
        }
    }

    return 0;
}
