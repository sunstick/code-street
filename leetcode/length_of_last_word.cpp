/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int n = strlen(s);

        int j = n - 1;
        while (j >= 0 && s[j] == ' ')
            j--;

        if (j == -1)
            return 0;

        int i = j - 1;
        while (i >= 0 && isalpha(s[i]))
            i--;

        return j - i;
    }
};
