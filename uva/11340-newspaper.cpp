#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;
typedef long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

int values[256];
uint times[256];

int main() {
    int m, n, v;
    uchar ch;
    string line;
    freopen("data.in", "rw", stdin);
    cin >> n;
    while (n-- > 0) {
        memset(values, 0, sizeof(values));
        memset(times, 0, sizeof(times));
        int m;
        cin >> m;
        while (m-- > 0) {
            cin >> ch;
            cin >> v;
            values[(int)ch] = v;
        }
        cin >> m;
        getchar();
        while (m-- > 0) {
            getline(cin, line);
            for (int i = 0; i < line.size(); i++) {
                ch = (uchar)line[i];
                times[(int)ch]++;
            }
        }
        ll sum = 0;
        for (int i = 0; i < 256; i++)
            sum += values[i] * times[i];
        ll a = sum / 100;
        ll b = sum % 100;
        printf("%ld.%02ld$\n", a, b);
    }
    return 0;
}
