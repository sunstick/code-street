#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vint;
vint vp;

long merge(vint &vs, int l, int i, int j, int h) {
    vint temp;
    int x = l, y = j;
    long sum = 0;

    while (x <= i && y <= h) {
        if (vs[x] <= vs[y]) {
            temp.push_back(vs[x]);
            x++;
        } else {
            temp.push_back(vs[y]);
            sum += (i - x + 1);
            y++;
        }
    }

    while (x <= i) {
        temp.push_back(vs[x]);
        x++;
    }

    while (y <= h) {
        temp.push_back(vs[y]);
        y++;
    }

    for (int k = 0; k < temp.size(); k++)
        vs[k + l] = temp[k];

    return sum;
}

long calSwap(vint &vs, int l, int h) {
    if (l >= h)
        return 0;
    long sum = 0;
    int m = l + (h - l) / 2;
    sum += calSwap(vs, l, m);
    sum += calSwap(vs, m + 1, h);
    sum += merge(vs, l, m, m + 1, h);
    return sum;
}

int main() {
    int n;
    while (1) {
        cin >> n;
        if (!n)
            break;
        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;
            vp.push_back(m);
        }
        int a = calSwap(vp, 0, n - 1);
        if (a % 2)
            cout << "Marcelo" << endl;
        else
            cout << "Carlos" << endl;
        vp.clear();
    }
    return 0;
}
