/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &l) {
        map<string, int> need;
        map<string, int> meet;
        vector<int> res;

        for (int i = 0; i < l.size(); i++)
            need[l[i]]++;

        int m = l.size();
        int n = l[0].size();
        int x = s.size();

        int index = 0;
        while (index <= x - m * n) {
            if (need.count(s.substr(index, n)) == 0) {
                index++;
                continue;
            }

            meet.clear();
            bool flag = false;
            int count = 0;
            for (int i = 0; i < m; i++) {
                string str = s.substr(index + i * n, n);
                if (need.count(str) == 0) {
                    index++;
                    flag = true;
                    break;
                }
                meet[str]++;
                if (meet[str] <= need[str]) count++;
            }

            if (flag) continue;

            if (count == m) res.push_back(index);
            index += n;
        }

        return res;
    }
};