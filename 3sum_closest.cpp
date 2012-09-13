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