#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

#define REP(i, b, n) for(int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

struct Ret {
    int l, ln, maxi, r, rn;
}; // l is the left boundary, ln is the number of left boundary
// r is the right boundary, rn is the number of right boundary

const int N = (1 << 18);
const int M = 2 * N;
int in[N];
Ret rmq[M];

void outret(Ret ret) {
    cout << ret.l << " " << ret.ln << " " << ret.maxi << " " << ret.r << " " << ret.rn << endl;
}

Ret init(int now, int l, int r) { // note that l and r are both indexes. Index information is contained implicitly in rmq.
    if (l == r) {
        return rmq[now] = (Ret) {
            in[l], 1, 1, in[r], 1
        };
    }
    Ret L = init(now * 2 + 1, l, (l + r) / 2);
    Ret R = init(now * 2 + 2, (l + r) / 2 + 1, r);
    int tmp = L.r == R.l ? L.rn + R.ln : 0;
    int maxi = 0;
    maxi = max(tmp, max(L.maxi, R.maxi));
    int retl = L.ln, retr = R.rn;
    if (L.l == R.l) retl += R.ln;
    if (L.r == R.r) retr += L.rn;

    return rmq[now] = (Ret) {
        L.l, retl, maxi, R.r, retr
    };
}

Ret query(int now, int l, int r, int ql, int qr) { // note that l, r, ql, qr are all indexes.
    if (l == ql && r == qr)
        return rmq[now]; // Rets in query process is constructed from Rets created in init process.
    int ml = (l + r) / 2, mr = (l + r) / 2 + 1;
    Ret ret;

    if (qr <= ml) {
        Ret child = query(now * 2 + 1, l, ml, ql, qr);
        ret = child;
    } else if (mr <= ql) {
        Ret child = query(now * 2 + 2, mr, r, ql, qr);
        ret = child;
    } else {
        Ret L = query(now * 2 + 1, l, ml, ql, ml);
        Ret R = query(now * 2 + 2, mr, r, mr, qr);
        int tmp = L.r == R.l ? L.rn + R.ln : 0;
        int maxi = max(tmp, max(L.maxi, R.maxi));
        int retl = L.ln, retr = R.rn;
        if (L.l == R.l)
            retl += R.ln;
        if (L.r == R.r)
            retr += L.rn;
        return (Ret) {
            L.l, retl, maxi, R.r, retr
        };
    }
    return ret;
}

int main() {
    int n, q;
    while (scanf("%d%d", &n, &q) != -1 && n) {
        rep(i, n)
        scanf("%d", &in[i]);
        int maxi = in[n - 1];
        int newn = 1;
        while (newn < n) {
            newn *= 2;
        }

        REP(i, n, newn) {
            in[i] = maxi + i + 1;
        }

        n = newn;
        init(0, 0, n - 1);

        rep(i, q) {
            int l, r;
            scanf("%d%d", &l, &r);
            Ret ans = query(0, 0, n - 1, l - 1, r - 1);
            printf("%d\n", ans.maxi);
        }
    }
    return 0;
}
