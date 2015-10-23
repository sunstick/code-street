#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

int n;
char input[40];
int data[32];

int main() {
    data[1] = 1;
    for (int i = 2; i < 32; i++)
        data[i] = 2 * (data[i - 1] + 1) - 1;

    while (cin >> input && strcmp(input, "0")) {
        n = strlen(input);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (data[n - i] * (input[i] - '0'));
        }

        cout << sum << endl;
    }
    return 0;
}
