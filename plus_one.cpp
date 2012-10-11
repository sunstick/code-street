/*
Given a number represented as an array of digits, plus one to the number.
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        reverse(digits.begin(), digits.end());
        int carry = 0;

        for (int i = 0; i < digits.size(); i++) {
            if (i == 0) {
                res.push_back((digits[i] + 1) % 10);
                carry = (digits[i] + 1) / 10;
            } else {
                res.push_back((digits[i] + carry) % 10);
                carry = (digits[i] + carry) / 10;
            }
        }

        if (carry)
            res.push_back(carry);


        reverse(res.begin(), res.end());
        return res;
    }
};