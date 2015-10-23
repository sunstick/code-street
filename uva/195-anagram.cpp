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

bool compare_char(char a, char b) {
    char x = tolower(a);
    char y = tolower(b);

    if (x == y)
        return a < b;

    return x < y;
}

int main() {
    int n;
    cin >> n;

    string str;

    while (n--) {
        cin >> str;
        sort(str.begin(), str.end(), compare_char);
        do {
            cout << str << endl;
        } while (next_permutation(str.begin(), str.end(), compare_char));
    }
    return 0;
}