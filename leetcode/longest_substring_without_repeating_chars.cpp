/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_window = 0;
        bool hash[256];
        memset(hash, 0, sizeof(hash));

        int i = 0, j = 0;
        while (j < s.size()) {
            if (hash[s[j]]) {
                while (i < j && s[i] != s[j]) {
                    hash[s[i]] = false;
                    i++;
                }
                i++;
            }
            hash[s[j]] = true;
            max_window = max(max_window, j - i + 1);
            j++;
        }

        return max_window;
    }
};