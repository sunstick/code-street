/*
  Write an algorithm which computes the number of trailing zeros in n factorial.
 */

int count_zero_1 (int n) {
    int count = 0;
    if (n < 0) return 0;

    for (int i = 5; i <= n; i += 5) {
        int j = i;
        while (j % 5 == 0) {
            count++;
            j /= 5;
        }
    }

    return count;
}

int count_zero_2 (int n) {
    int count = 0;
    if (n < 0) return 0;

    for (int i = 5; n / i > 0; i *= 5) {
        count += n / i;
    }
    return count;
}

void test() {
    cout << count_zero_1(90) << endl;
    cout << count_zero_2(90) << endl;
}


