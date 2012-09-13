class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        string res = "";
        vector<string> vstr(nRows);

        if (nRows == 1) return s;

        int zigzag = 2 * nRows - 2;
        int zin, zth, row;

        for (int i = 0; i < n; i++) {
            zin = i / zigzag;
            zth = i % zigzag;
            if (zth < nRows)
                row = zth;
            else {
                row = (nRows - 2) - (zth - nRows);
            }

            vstr[row] += s[i];
        }

        for (int i = 0; i < nRows; i++)
            res += vstr[i];

        return res;
    }
};