/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
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

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        vector<int> sol;

        sort(num.begin(), num.end());
        int n = num.size();

        for (int i = 0; i < n; i = increase(num, i))
            for (int j = i + 1; j < n; j = increase(num, j)) {
                int p = j + 1;
                int q = n - 1;

                while (p < q) {
                    int sum = num[i] + num[j] + num[p] + num[q];
                    if (sum == target) {
                        sol.clear();
                        sol.push_back(num[i]);
                        sol.push_back(num[j]);
                        sol.push_back(num[p]);
                        sol.push_back(num[q]);
                        res.push_back(sol);
                        p = increase(num, p);
                        q = decrease(num, q);
                    } else if (sum < target)
                        p = increase(num, p);
                    else
                        q = decrease(num, q);
                }
            }
        return res;
    }
};