#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string a, b;

    while (cin >> a) {
        if (a == "#")
            break;
        size_t pos;
        for (pos = 0; pos < a.size(); pos++) {
            b = a.substr(pos);

            sort(b.rbegin(), b.rend());
            if (b == a.substr(pos))
                break;
        }
        if (pos == 0)
            cout << "No Successor" << endl;
        else {
            size_t posE = a.size() - 1;
            while (a[posE] <= a[pos - 1])
                posE--;

            char ch = a[pos - 1];
            a[pos - 1] = a[posE];
            a[posE] = ch;
            sort(a.begin() + pos, a.end());
            cout << a << endl;
        }
    }

    return 0;
}
