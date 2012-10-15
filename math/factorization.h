/*
factorize n!
*/

int prime[100], counta = 0;
int p[100];
int maxp = 0;

int is_prime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

void factorize(int n) {
    memset(p, 0, sizeof(p));
    maxp = 0;
    for (int i = 2; i <= n; i++) {
        int m = i;
        for (int j = 0; j < counta; j++) {
            while (m % prime[j] == 0) {
                m /= prime[j];
                p[j]++;
                if (j > maxp)
                    maxp = j;
            }
        }
    }
}

void test() {
    int n;

    for (int i = 2; i < 100 ; i++) {
        if (is_prime(i)) {
            prime[counta++] = i;
        }
    }

    while (cin >> n) {
        factorize(n);
        cout << n << "!=";
        for (int i = 0; i <= maxp; i++) {
            cout << p[i] << " ";
        }
    }
}
