class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int end = n - 1;
        int start = 0;

        while (start <= end) {
            if (A[start] == elem) {
                int temp = A[start];
                A[start] = A[end];
                A[end] = temp;
                end--;
                n--;
            } else
                start++;
        }

        return n;
    }
};