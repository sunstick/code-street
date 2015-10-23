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
#define Foreach(it, x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Read(r) freopen(r, "r", stdin)
#define Write(w) freopen(w, "w", stdout)

using namespace std;

vector<int> durations;

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss;
        ss << line;
        int capacity, temp, n;

        ss >> capacity;
        ss >> n;
        while (ss >> temp)
            durations.push_back(temp);

        int maxsum = 0;
        int res = 0;
        For(i, 1, 1 << n ) {
            int sum = 0;
            For(j, 0, n)
            if (1 << j & i)
                sum += durations[j];
            if (sum <= capacity && sum >= maxsum) {
                res = i;
                maxsum = sum;
            }
        }

        For(i, 0, n)
        if (1 << i & res)
            cout << durations[i] << " ";

        cout << "sum:" << maxsum << endl;
        durations.clear();
    }
    return 0;
}
