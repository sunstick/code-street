/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int> &h) {
        int res = -1;
        int n = h.size();

        int i = 0, j = n - 1;

        while (i < j) {
            res = max(res, (j - i) * min(h[i], h[j]));

            if (h[i] <= h[j]) { // move i;
                int newi = i + 1;
                while (newi < j && h[newi] <= h[i])
                    newi++;
                i = newi;
            } else { // move j
                int newj = j - 1;
                while (i < newj && h[newj] <= h[j])
                    newj--;
                j = newj;
            }
        }

        return res;
    }
};