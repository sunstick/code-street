/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

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