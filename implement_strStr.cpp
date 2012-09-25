class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int len1 = strlen(haystack);
        int len2 = strlen(needle);
        bool flag;

        for (int i = 0; i < len1 - len2 + 1; i++) {
            flag = true;
            for (int j = 0; j < len2; j++) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return haystack + i;
            }
        }
        return NULL;
    }
};