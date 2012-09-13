#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res = "";

        int carry = 0;

        int n = max(a.size(), b.size());

        int i = 0;

        while (i < n || carry) {
            int ai = i < a.size() ? a[i] - '0' : 0;
            int bi = i < b.size() ? b[i] - '0' : 0;
            int bit = ai + bi + carry;
            carry = bit / 2;
            bit = bit % 2;
            res += (bit + '0');
            i++;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};