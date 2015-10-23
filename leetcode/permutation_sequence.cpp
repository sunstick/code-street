/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:
    int factorial(int n) {
        int res = 1;
        for (int i = 2; i <= n; i++)
            res *= i;
        return res;
    }
    string getPermutation(int n, int k) {
        string res = "";

        for (int i = 1; i <= n; i++)
            res += i + '0';

        k--;
        for (int i = 0; i < n; i++) {
            int fac = factorial(n - i - 1);
            int x = k / fac;
            swap(res[i], res[i + x]);
            k = k % fac;
            sort(res.begin() + i + 1, res.end());
        }
        return res;
    }
};