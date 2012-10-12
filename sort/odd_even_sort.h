/*
  There is an array of odd and even numbers. Now, sort them in such a way that the top portion of
the array contains odd numbers, bottom portion contains even numbers. The odd numbers are to be sorted
in descending order and the even numbers in ascending order. You are not allowed to use any extra array
and it has to use a conventional sorting mechanism and should not do any pre or post processing.
 */

bool odd_even_cmp(int a, int b) {
    if (a & 1) { // if a is odd
        if (b & 1) // if b is odd too
            return a > b;
        else
            return true;
    } else {
        if (b & 1) // if b is odd
            return false;
        else
            return a < b;
    }
}

void odd_even_sort(int array[], int n) {
    sort(array, array + n, odd_even_cmp);
}

void test() {
    int array[8] = {
        1, 2, 3, 4, 5, 6, 7, 8
    };

    odd_even_sort(array, 8);

    for (int i = 0; i < 8; i++)
        cout << array[i] << " ";

    cout << endl;
}
