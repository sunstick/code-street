/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
    int sqrt(int x) {
        long long low = 0;
        long long hi = x;

        while (low < hi) {
            long long mid = low + (hi - low + 1) / 2;
            if (mid * mid > (long long)x)
                hi = mid - 1;
            else
                low = mid;
        }
        return (int)low;
    }
};