/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

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