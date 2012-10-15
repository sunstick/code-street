/*
Find the smallest number in a rotated and sorted array
*/
 
int searchMin_rotated(int *array, int l, int r) {
    while (l != r && array[l] >= array[r]) {
        int m = (r - l) / 2 + l;
        if (array[m] <= array[r])
            r = m;
        else
            l = m + 1;
    }

    return array[l];
}