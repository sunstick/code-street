/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int close = abs(num[0] + num[1] + num[2] - target);
        int sum = num[0] + num[1] + num[2];
        int n = num.size();

        sort(num.begin(), num.end());

        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int temp = num[i] + num[j] + num[k];
                if (abs(temp - target) < close) {
                    close = abs(temp - target);
                    sum = temp;
                }

                if (temp < target)
                    j++;
                else if (temp > target)
                    k--;
                else
                    return sum;
            }
        }

        return sum;
    }
};