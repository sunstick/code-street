#include <iostream>
#include <cctype>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        int n = line.size();
        bool flag;
        int ans = 0;

        if (isalpha(line[0])) {
            flag = true;
            ans++;
        } else
            flag = false;

        for (int i = 1; i < n; i++) {
            if (isalpha(line[i])) {
                if (!flag) {
                    ans++;
                    flag = true;
                }
            } else
                flag = false;
        }
        cout << ans << endl;
    }
    return 0;
}
