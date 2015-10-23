#include <iostream>

using namespace std;

int main() {
    int a, b;
    int casen = 0;

    while ((cin >> a >> b) && (a || b)) {
        casen++;
        unsigned long long sum1 = a * (a - 1) / 2;
        unsigned long long sum2 = b * (b - 1) / 2;
        unsigned long long x = sum1 * sum2;
        cout << "Case " << casen << ": " << x << endl;
    }
    return 0;
}
