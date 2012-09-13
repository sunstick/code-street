class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1 / x;

        bool flag = false;
        if (n < 0) {
            n = -n;
            flag = true;
        }

        if (n % 2) {
            double t = pow(x, n / 2);
            return flag ? 1 / (t * t * x) : t * t * x;
        } else {
            double t = pow(x, n / 2);
            return flag ? 1 / (t * t) : t * t;
        }
    }
};