#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int data[15];

void select(int n, int k, string &now, vector<int> &curr) {
    if (n == 6) {
        cout << now << endl;
        return ;
    }
    int i = curr[curr.size() - 1] + 1;
    for (; i < k; i++) {
        stringstream ss;
        ss << data[i];
        string an;

        if (n == 0)
            an = ss.str();
        else
            an = now + " " + ss.str();

        curr.push_back(i);
        select(n + 1, k, an, curr);
        curr.pop_back();
    }
}

int main() {
    int k;
    int c = 0;
    while (cin >> k && k) {
        if (c)
            cout << endl;
        for (int i = 0; i < k; i++)
            cin >> data[i];
        string now = "";
        vector<int> curr;
        curr.push_back(-1);
        select(0, k, now, curr);
        c++;
    }
}
