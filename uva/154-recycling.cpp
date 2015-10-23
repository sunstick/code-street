#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<pair<char, char> > city;
typedef vector<city> vvp;
vvp nation;

bool city_cmp(pair<char, char> p1, pair<char, char> p2) {
    return p1.first < p2.first;
}

int cdistance(city &c1, city &c2) {
    int n = c1.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (c1[i].second != c2[i].second)
            sum++;
    return sum;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line[0] == 'e') {
            int number = 0;
            int minchange = 100000;
            for (int i = 0; i < nation.size(); i++) {
                int sum = 0;
                for (int j = 0; j < nation.size(); j++)
                    sum += cdistance(nation[i], nation[j]);

                if (sum <= minchange) {
                    minchange = sum;
                    number = i + 1;
                }
            }
            nation.clear();
            cout << number << endl;
        } else if (line == "#")
            break;
        else {
            city temp;

            for (int i = 0; i < 5; i++)
                temp.push_back(make_pair(line[i * 4], line[i * 4 + 2]));

            sort(temp.begin(), temp.end(), city_cmp);
            nation.push_back(temp);
        }
    }
    return 0;
}
