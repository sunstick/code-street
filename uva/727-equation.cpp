#include <iostream>
#include <stack>
#include <cctype>
#include <cstdio>

using namespace std;

int prio[128];
int prii[128];

stack<char> sc;

int main() {
    prio['('] = 2;
    prio['+'] = 0;
    prio['-'] = 0;
    prio['*'] = 1;
    prio['/'] = 1;

    prii['('] = -1;
    prii['+'] = 0;
    prii['-'] = 0;
    prii['*'] = 1;
    prii['/'] = 1;

    int n;
    cin >> n; getchar();
    string line;
    getline(cin, line);

    while (n-- > 0) {
        while (getline(cin, line)) {
            if (line == "")
                break;

            if (isdigit(line[0]))
                cout << line[0];
            else {
                char ch = line[0];
                if (ch == ')') {
                    while (sc.top() != '(') {
                        cout << sc.top();
                        sc.pop();
                    }
                    sc.pop();
                } else {
                    while (!sc.empty() && prio[ch] <= prii[sc.top()]) {
                        cout << sc.top();
                        sc.pop();
                    }
                    sc.push(ch);
                }
            }
        }

        while (!sc.empty()) {
            cout << sc.top();
            sc.pop();
        }
        cout << endl;

        if (n)
            cout << endl;
    }
    return 0;
}
