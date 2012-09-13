class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int t = m + n - 1;
        m--;
        n--;

        while (m >= 0 && n >= 0) {
            if (A[m] > B[n])
                A[t--] = A[m--];
            else
                A[t--] = B[n--];
        }

        if (n >= 0) {
            while (n >= 0)
                A[t--] = B[n--];
        }
    }
};