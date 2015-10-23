#include <map>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    char buffer[40];
    int cases;
    cin >> cases;
    getchar();
    getchar();
    while (cases--) {
        map<string, int> m;
        vector<string> trees;
        int total = 0;
        while (gets(buffer) && buffer[0]) {
            string in(buffer);
            if (!m[in]) {
                m[in] = 1;
                trees.push_back(in);
            } else
                m[in]++;
            total++;
        }
        sort(trees.begin(), trees.end());
        for (int i = 0 ; i < (trees.size()); i++) {
            cout << trees[i] << ' ';
            printf("%.4lf\n", m[trees[i]] * 100.00 / total);
        }
        if (cases)
            putchar('\n');
    }
}
