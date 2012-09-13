class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int newn = 0;
        int i = 0;
        int j = 0;

        while (j < n) {
            A[i++] = A[j];
            newn++;

            while (j < n && A[j] == A[i - 1]) {
                j++;
            }
        }

        return newn;
    }
};