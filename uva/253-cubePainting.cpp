#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string Cube;
void ChSwap(char &a, char  &b) {
    char c = a;
    a = b;
    b = c;
}
int IsEqual(string str) {
    string s = str;
    if (s == Cube)   return 1;
    ChSwap(s[1], s[4]);
    ChSwap(s[2], s[3]);
    if (s == Cube)   return 1;
    ChSwap(s[2], s[3]);
    ChSwap(s[1], s[2]);
    ChSwap(s[3], s[4]);
    if (s == Cube)   return 1;
    ChSwap(s[1], s[4]);
    ChSwap(s[2], s[3]);
    if (s == Cube)   return 1;
    return 0;
}
int main() {
    int flag;
    string input, s;
    while (cin >> input) {
        flag = 0;
        Cube.assign(input, 6, 6);
        input.erase(6);
        if (input[0] == Cube[0] && input[5] == Cube[5]) {
            if (IsEqual(input))    flag = 1;
        }
        if (!flag && input[5] == Cube[0] && input[0] == Cube[5]) {
            s = input;
            ChSwap(s[0], s[5]);
            ChSwap(s[1], s[4]);
            if (IsEqual(s))    flag = 1;
        }
        if (!flag && input[1] == Cube[0] && input[4] == Cube[5]) {
            s = input;
            ChSwap(s[0], s[5]);
            ChSwap(s[0], s[1]);
            ChSwap(s[4], s[5]);
            if (IsEqual(s))    flag = 1;
        }
        if (!flag && input[4] == Cube[0] && input[1] == Cube[5]) {
            s = input;
            ChSwap(s[1], s[4]);
            ChSwap(s[0], s[1]);
            ChSwap(s[4], s[5]);
            if (IsEqual(s))    flag = 1;
        }
        if (!flag && input[2] == Cube[0] && input[3] == Cube[5]) {
            s = input;
            ChSwap(s[0], s[5]);
            ChSwap(s[0], s[2]);
            ChSwap(s[3], s[5]);
            if (IsEqual(s))    flag = 1;
        }
        if (!flag && input[3] == Cube[0] && input[2] == Cube[5]) {
            s = input;
            ChSwap(s[2], s[3]);
            ChSwap(s[0], s[2]);
            ChSwap(s[3], s[5]);
            if (IsEqual(s))    flag = 1;
        }
        if (flag)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;
    }
    return 0;
}
