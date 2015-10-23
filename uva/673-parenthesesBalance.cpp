#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdio>

using namespace std;

int n;
string line;

int main() {
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        int flag = 0;
        stack<char> cs;

        for (int j = 0; j < line.size(); j++) {
            char ch = line[j];
            if (ch == '(' || ch == '[')
                cs.push(ch);
            else {
                if (cs.empty()) {
                    flag = 1;
                    break;
                }
                char comp = (ch == ')') ? '(' : '[';
                if (cs.top() == comp)
                    cs.pop();
                else {
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag && cs.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
