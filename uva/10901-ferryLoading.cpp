#include <queue>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;
typedef struct {
    int id;
    int arrive;
    int depart;
} boat;

bool boat_cmp(boat b1, boat b2) {
    return b1.id < b2.id;
}

queue<boat> lq;
queue<boat> rq;
vector<boat> outvec;

int main() {
    int n, t, m, tests;
    cin >> tests;
    while (tests-- > 0) {
        outvec.clear();

        cin >> n >> t >> m;
        int ar;
        string lr;

        for (int i = 0; i < m; i++) {
            cin >> ar >> lr;
            boat bt;
            bt.id = i;
            bt.arrive = ar;

            if (lr == "left")
                lq.push(bt);
            else
                rq.push(bt);
        }

        int flag = 0, time = 0;

        while (!lq.empty() || !rq.empty()) {
            queue<boat> &tq = flag ? rq : lq;
            queue<boat> &oq = flag ? lq : rq;

            int has = 0;
            for (int i = 0; i < n && !tq.empty() && tq.front().arrive <= time; i++) {
                has = 1;
                tq.front().depart = time + t;
                outvec.push_back(tq.front());
                tq.pop();
            }
            if (has) {
                flag = 1 - flag;
                time += t;
            } else {
                int ttime = !tq.empty() ? tq.front().arrive : 99999999;
                int otime = !oq.empty() ? oq.front().arrive : 99999999;
                if (ttime <= otime) { // this side is earlier
                    time = max(time, ttime);
                } else { // other side is earlier
                    flag = 1 - flag;
                    time = max(time + t, otime + t);
                }
            }
        }

        sort(outvec.begin(), outvec.end(), boat_cmp);
        vector<boat>::iterator it = outvec.begin();

        while (it != outvec.end()) {
            cout << it -> depart << endl;
            it++;
        }

        if (tests)
            cout << endl;
    }
    return 0;
}
