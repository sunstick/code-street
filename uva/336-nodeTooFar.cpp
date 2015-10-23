#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <utility>

using namespace std;

typedef map<int, vector<int>* > network;
network nc;
int numOfN = 0;
int cases = 0;

void addtoNetwork(int n1, int n2) {
    if (nc.count(n1)) {
        nc[n1]->push_back(n2);
    } else {
        numOfN++;
        vector<int> *temp = new vector<int>();
        temp->push_back(n2);
        nc[n1] = temp;
    }
}

int main() {
    int n;
    while (cin >> n && n) {
        nc.clear();
        numOfN = 0;
        while (n--) {
            int n1; int n2;
            cin >> n1;
            cin >> n2;
            addtoNetwork(n1, n2);
            addtoNetwork(n2, n1);
        }

        while (1) {
            queue<pair<int, int> > flow;
            int node;
            int time;
            cin >> node;
            cin >> time;
            int ftime = time;
            int fnode = node;
            if (!node && !time)
                break;
            cases++;

            flow.push(make_pair(node, time));
            int reach = 0;
            set<int> flag;

            while (!flow.empty()) {
                pair<int, int> tp = flow.front();
                flow.pop();
                node = tp.first;
                time = tp.second;
                if (flag.count(node) == 0) {
                    flag.insert(node);
                    reach++;
                    vector<int> *neighbors = nc[node];
                    if (time)
                        for (int i = 0; i < neighbors->size(); i++) {
                            int thistime = (*neighbors)[i];
                            flow.push(make_pair(thistime, time - 1));
                        }
                }
            }

            cout << "Case " << cases << ": " << numOfN - reach << " nodes not reachable from node ";
            cout << fnode << " with TTL = " << ftime << "." << endl;
        }
    }
    return 0;
}
