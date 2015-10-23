#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> mp;

    for (int i = 0; i < n; i++) {
        string country;
        cin >> country;
        mp[country]++;
        getline(cin, country);
    }

    map<string, int>::iterator it = mp.begin();
    for (; it != mp.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}
