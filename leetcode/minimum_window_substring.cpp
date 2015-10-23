/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int need[256];
        int meet[256];
        memset(need, 0, sizeof(need));
        memset(meet, 0, sizeof(meet));

        for (int i = 0; i < t.size(); i++)
            need[t[i]]++;

        int min_size = INT_MAX;
        string min_str = "";

        int start = 0;
        int end = 0;
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (need[s[i]] == 0) continue;
            meet[s[i]]++;
            if (meet[s[i]] <= need[s[i]]) count++;

            if (count == t.size()) {
                end = i;

                while (need[s[start]] == 0 || meet[s[start]] > need[s[start]]) {
                    meet[s[start]]--;
                    start++;
                }

                if (end - start + 1 < min_size) {
                    min_size = end - start + 1;
                    min_str = s.substr(start, end - start + 1);
                }
            }
        }

        return min_str;
    }
};