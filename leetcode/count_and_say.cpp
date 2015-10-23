/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string countAndSay(const string &p) {
        string res = "";
        int i = 0;
        int newi = 1;
        while (i < p.size()) {
            while (newi < p.size() && p[i] == p[newi])
                newi++;
            int count = newi - i;
            res += (count + '0');
            res += (p[i]);
            i = newi;
        }
        return res;
    }
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string p = "1";
        for (int i = 2; i <= n; i++)
            p = countAndSay(p);
        return p;
    }
};