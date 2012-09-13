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