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