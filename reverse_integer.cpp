class Solution {
public:
    int reverse(int x) {
        int res = 0;
        bool flag = false;
        if (x < 0) {
            flag = true;
            x = -x;
        }

        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }

        return flag ? -res : res;
    }
};