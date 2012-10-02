/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
*/

int increase(vector<int> &num, int i) {
    int newi = i + 1;
    while (newi < num.size() && num[newi] == num[i])
        newi++;
    return newi;
}

int decrease(vector<int> &num, int i) {
    int newi = i - 1;
    while (newi >= 0 && num[newi] == num[i])
        newi--;
    return newi;
}

void solve(vector<vector<int> > &res, vector<int> &num, int target, int skip_index) {
    int i = skip_index + 1;
    int j = num.size() - 1;

    vector<int> temp;

    while (i < j) {
        temp.clear();
        if (num[i] + num[j] == target) {
            temp.push_back(num[skip_index]);
            temp.push_back(num[i]);
            temp.push_back(num[j]);
            i = increase(num, i);
            j = decrease(num, j);
            res.push_back(temp);
        } else if (num[i] + num[j] < target) {
            i = increase(num, i);
        } else {
            j = decrease(num, j);
        }

    }
}

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i = increase(num, i))
            solve(res, num, 0 - num[i], i);

        return res;
    }
};