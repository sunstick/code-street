/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

class Solution {
public:
    bool isPalindrome(int c) {
        if (c < 0) return false;
        unsigned int x = c;

        unsigned int rev = 0;

        while (x) {
            rev = 10 * rev + x % 10;

            x /= 10;
        }

        return rev == (unsigned int)c;
    }
};