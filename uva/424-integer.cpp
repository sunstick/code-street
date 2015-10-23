#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

const int maxn = 1000; // max digits supported

struct bign {
    int len, s[maxn]; // len is actual length

    bign() {
        memset(s, 0, sizeof(s));
        len = 1;
    }

    bign(const int num) {
        *this = num;
    }

    bign(const char *num) {
        *this = num;
    }

    bign operator = (const char *num) {
        len = strlen(num);

        for (int i = 0; i < len; i++) {
            s[i] = num[len - i - 1] - '0';
        }

        return *this;
    }

    bign operator = (const int num) {
        char s[maxn];

        sprintf(s, "%d", num);
        *this = s;

        return *this;
    }

    bign operator + (const bign &b) const {
        bign c;
        c.len = 0;

        for (int i = 0, g = 0; g || i < max(len, b.len); i++) {
            int x = g;
            if (i < len)
                x += s[i];
            if (i < b.len)
                x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }

        return c;
    }

    bign operator += (const bign &b) {
        *this = *this + b;
        return *this;
    }

    bign operator *(const bign &b) const {
        bign res;
        bign zero("0");

        if (*this == zero || b == zero)
            return zero;

        for (int i = 0; i < len; i++) {
            int carry = 0;
            bign c;
            c.len = i;

            for (int j = 0; j < b.len; j++) {
                int st = s[i] * b.s[j] + carry;
                c.s[c.len++] = st % 10;
                carry = st / 10;
            }
            if (carry) {
                c.s[c.len++] = carry;
            }

            res += c;
        }

        return res;
    }

    bool operator < (const bign &b) const {
        if (len != b.len)
            return len < b.len;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] != b.s[i]) {
                return s[i] < b.s[i];
            }
        }

        return false;
    }

    bool operator > (const bign &b) const {
        return b < *this;
    }

    bool operator <= (const bign &b) const {
        return !(b < *this);
    }

    bool operator >= (const bign &b) const {
        return !(*this < b);
    }

    bool operator == (const bign &b) const {
        return !(*this < b) && !(*this > b);
    }

    bool operator != (const bign &b) const {
        return (*this < b) || (*this > b);
    }

    string str() const {
        string res = "";
        for (int i = 0; i < len; i++) {
            res = (char)(s[i] + '0') + res;
        }
        if (res == "")
            res = "0";
        return res;
    }

};

istream &operator >> (istream &in, bign &x) {
    string s;
    in >> s;
    x = s.c_str();
    return in;
}

ostream &operator << (ostream &out, bign &x) {
    out << x.str();
    return out;
}

char num[110];

int main() {
    bign res;
    while (cin >> num) {
        if (strcmp(num, "0")) {
            bign temp = num;
            res += temp;
        } else
            break;
    }
    cout << res << endl;
    return 0;
}
