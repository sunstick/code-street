class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int newn = 0;
        int i = 0;
        int j = 0;

        while (j < n) {
            A[i++] = A[j];
            newn++;
            j++;

            if (j < n && A[j] == A[j - 1]) {
                A[i++] = A[j];
                newn++;
                j++;
            }

            while (j < n && A[j] == A[i - 1]) {
                j++;
            }
        }

        return newn;
    }
};