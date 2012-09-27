/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/

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