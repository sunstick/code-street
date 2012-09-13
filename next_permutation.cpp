class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = num.size() - 1;

        while (i > 0 && num[i] <= num[i - 1]) i--;

        if (i == 0) {
            reverse(num.begin(), num.end());
            return ;
        }
        int pivot = num[i - 1];

        for (int j = num.size() - 1; j >= i; j--) {
            if (num[j] > pivot) {
                swap(num[i - 1], num[j]);
                break;
            }
        }

        reverse(num.begin() + i, num.end());
    }
};