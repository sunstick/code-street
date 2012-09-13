class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        map<string, vector<string> > dict;

        if (strs.size() == 0) {
            return result;
        }

        for (size_t i = 0; i < strs.size(); i++) {
            string sorted(strs[i]);
            sort(sorted.begin(), sorted.end());
            dict[sorted].push_back(strs[i]);
        }

        map<string, vector<string> >::iterator it;
        for (it = dict.begin(); it != dict.end(); it++) {
            if (it->second.size() > 1) {
                for (size_t i = 0; i < it->second.size(); i++) {
                    result.push_back(it->second[i]);
                }
            }
        }

        return result;
    }
};