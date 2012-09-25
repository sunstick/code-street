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