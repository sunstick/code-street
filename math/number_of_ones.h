/*
Number of ones in an integer's binary representation.
*/

int number_ones(unsigned int n) {
    int ones = 0;
    while (n) {
        n = n & (n - 1);
        ones ++;
    }

    return ones;
}

void test() {
    cout << number_ones(7) << endl;
}

