/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lo = 0;
        int hi = n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] == target) return true;

            if (A[lo] == A[mid] && A[mid] == A[hi]) {
                for (int i = lo; i <= hi; i++)
                    if (A[i] == target)
                        return true;
                return false;
            } else if (A[lo] <= A[mid]) { // first part is sorted
                if (A[mid] > target && target >= A[lo])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            } else { // latter part is sorted
                if (A[mid] < target && target <= A[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }

        return false;
    }
};