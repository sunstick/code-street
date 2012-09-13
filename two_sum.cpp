class Solution {
public:
    vector<int> twoSum(vector<int> &num, int target) {
        for (int i = 0; i < num.size() - 1; i++)
            for (int j = i + 1; j < num.size(); j++) {
                if (num[i] + num[j] == target) {
                    vector<int> res;
                    res.push_back(i + 1);
                    res.push_back(j + 1);
                    return res;
                }
            }
    }
};