/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i = 1;
        while (i <= n) {
            if (A[i - 1] != i && A[i - 1] > 0 && A[i - 1] <= n && A[i - 1] != A[A[i - 1] - 1])
                swap(A[i - 1], A[A[i - 1] - 1]);
            else
                i++;
        }

        for (int i = 1; i <= n; i++) {
            if (A[i - 1] != i)
                return i;
        }

        return n + 1;
    }
};