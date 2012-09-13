class Solution {
public:
    void sortColors(int array[], int n) {
        int a = 0;
        int b = n - 1;
        int i = a;
        // What is the loop invariant here?

        // array[ 0, ..., a - 1] are all 0's
        // array[ a, ..., i - 1] are all 1's
        // array[ i, ..., b] unknown
        // array[ b + 1, ...] are all 2's

        while (i <= b) {
            if (array[i] == 0)
                swap(array[i++], array[a++]);
            else if (array[i] == 2)
                swap(array[i], array[b--]);
            else
                i++;
        }
    }
};