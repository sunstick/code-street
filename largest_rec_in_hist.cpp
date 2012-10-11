/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

class Solution {
public:
    void solve(vector<int> &height, vector<int> &left, int n) {
        for (int i = 0; i < n; i++) {
            left[i] = i;
            int x = left[i] - 1;
            while (x >= 0 && height[i] <= height[x]) {
                left[i] = left[x];
                x = left[x] - 1;
            }
            if (x < 0) left[i] = 0;
        }
    }

    int largestRectangleArea(vector<int> &height) {
        int n = height.size();
        int res = 0;
        if (!n) return 0;

        vector<int> left(n);
        vector<int> right(n);

        solve(height, left, n);
        reverse(height.begin(), height.end());
        solve(height, right, n);
        reverse(height.begin(), height.end());
        reverse(right.begin(), right.end());

        for (int i = 0; i < n; i++)
            res = max(res, height[i] * ((n - 1 - right[i]) - left[i] + 1));

        return res;
    }
};