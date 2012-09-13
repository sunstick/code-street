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
