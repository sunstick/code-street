/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    string convert(string s, int nRows) {
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