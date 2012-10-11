/*
Given a digit string, return all possible letter combinations that the number could represent.
*/

class Solution {
public:

    void solve(int off, string &digits, string candidate, vector<string> &res, string mapping[]) {
        if (off == digits.size()) {
            res.push_back(candidate);
            return;
        }

        int c = digits[off] - '0';
        string x = mapping[c];
        for (int i = 0; i < x.size(); i++)
            solve(off + 1, digits, candidate + x[i], res, mapping);
    }

    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;

        string mapping[10];
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";


        solve(0, digits, "", res, mapping);

        return res;
    }
};