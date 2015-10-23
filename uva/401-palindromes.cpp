#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const string instr   = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
const string mapping = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

int pos(char ch) {
    for (int i = 0; i < instr.size(); i++)
        if (ch == instr[i])
            return i;
    return -1;
}

int main() {
    string str;
    while (cin >> str) {
        bool regular = true;
        bool mirror = true;
        int i = 0;
        int j = str.size() - 1;

        while (i <= j) {
            if (str[i] != str[j])
                regular = false;
            int index = pos(str[j]);

            if (str[i] != mapping[index])
                mirror = false;
            i++;
            j--;
        }

        if (regular && mirror)
            cout << str << " -- is a mirrored palindrome." << endl;
        else if (regular)
            cout << str << " -- is a regular palindrome." << endl;
        else if (mirror)
            cout << str << " -- is a mirrored string." << endl;
        else
            cout << str << " -- is not a palindrome." << endl;
        cout << endl;
    }
    return 0;
}
