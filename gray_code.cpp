class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        res.push_back(0);

        if (n == 0) return res;
        res.push_back(1);

        int add = 1;
        for (int i = 1; i < n; i++) {
            add *= 2;
            for (int j = res.size() - 1; j >= 0; j--)
                res.push_back(res[j] + add);
        }

        return res;
    }
};