class Solution {
public:
    bool canJump(int A[], int n) {
        int i = 0;
        int range = 0;

        while (i <= min(n - 1, range)) {
            range = max(range, i + A[i]);
            if (range >= n - 1)
                return true;
            i++;
        }

        return false;
    }
};