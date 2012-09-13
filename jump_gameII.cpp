class Solution {
public:
    int jump(int A[], int n) {
        int jump = 0;
        int smin = 0;
        int smax = 0;

        for (int i = 0; i < n; i++) {
            if (smax >= n - 1)
                return jump;
            int new_smax = i + A[i];

            if (i < smin) {
                smax = max(smax, new_smax);
            } else {
                if (new_smax > smax) {
                    smin = smax + 1;
                    smax = new_smax;
                    jump++;
                }
            }
        }

        return 0;
    }
};