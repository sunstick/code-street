long comb(int n, int i) {
    if (n == 0 || n == 1 || i == 0 || i == n)
        return 1;
    if (i == 1 || i == n - 1)
        return n;

    long a = 1;
    for (int x = 0; x < i; x++) {
        a *= (n - x);
    }

    for (int x = 1; x <= i; x++) {
        a /= x;
    }

    return a;
}

// level starting from 0, actually print out {level + 1} levels
void print_pascal_triangle(int level) {
    for (int l = 0; l <= level; l++) {
        for (int i = 0; i < level - l; i++)
            cout << "    ";
        for (int i = 0; i <= l; i++) {
            printf("%-8ld", comb(l, i));
        }
        cout << endl;
    }
}