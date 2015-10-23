#include <iostream>
#include <set>
#include <cstring>
#include <cstdio>
#define N 20

using namespace std;

set<int> primes;
int ring[N], vis[N], n;

void search(int cur) {
    if (cur == n) {
        if (primes.count(ring[0] + ring[n - 1])) {
            cout << ring[0];
            for (int i = 1; i < n; i++)
                cout << " " << ring[i];
            cout << endl;
        }
        return ;
    }

    for (int i = 0; i < n; i++)
        if (!vis[i] && primes.count(i + 1 + ring[cur - 1])) {
            vis[i] = 1;
            ring[cur] = i + 1;
            search(cur + 1);
            vis[i] = 0;
        }
}

int main() {
    primes.insert(3);
    primes.insert(5);
    primes.insert(7);
    primes.insert(11);
    primes.insert(13);
    primes.insert(17);
    primes.insert(19);
    primes.insert(23);
    primes.insert(29);
    primes.insert(31);

    int number = 0;

    while (cin >> n) {
        if (number)
            cout << endl;
        number++;
        printf("Case %d:\n", number);
        memset(vis, 0, sizeof(vis));
        ring[0] = 1;
        vis[0] = 1;
        search(1);
    }
    return 0;
}
