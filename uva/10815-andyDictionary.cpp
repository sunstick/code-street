#include <iostream>
#include <sstream>
#include <cstdio>
#include <set>
#include <string>
#include <cctype>

using namespace std;

set<string> dict;

int main() {
    string str;

    while (getline(cin, str)) {
        int n = str.size();
        int i = 0;
        while (i < n) {
            while (i < n && !isalpha(str[i]))
                i++;
            int count = 0;
            int j = i;
            while (i < n && isalpha(str[i])) {
                str[i] = tolower(str[i]);
                i++;
                count++;
            }
            if (count) {
                string temp(str, j, count);
                if (dict.count(temp) == 0)
                    dict.insert(temp);
            }
        }
    }

    for (set<string>::iterator it = dict.begin(); it != dict.end(); it++)
        cout << *it << endl;

    return 0;
}
