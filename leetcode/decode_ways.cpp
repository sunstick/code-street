/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (s == "") return 0;
        if (s[0] == '0') return 0;

        int a = 1;
        int b = 1;

        for (int i = 1; i < n; i++) {
            int x = 0;
            char c = s[i];
            if (c == '0') {
                if (s[i - 1] == '0' || s[i - 1] >= '3')
                    return 0;
                else
                    x = a;
            } else if (c >= '1' && c <= '6') {
                if (s[i - 1] == '1' || s[i - 1] == '2')
                    x = a + b;
                else
                    x = b;

            } else {
                if (s[i - 1] == '1')
                    x = a + b;
                else
                    x = b;
            }
            a = b;
            b = x;
        }

        return b;
    }
};