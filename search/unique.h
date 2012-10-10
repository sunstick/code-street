// Given an array of length n containing integers 1 to n, determine if it contains any duplicates

bool has_dups(int A[], int n) {
    int i = 1;
    while (i <= n) {
        if (A[i - 1] != i) {
            if (A[i - 1] == A[A[i - 1] - 1]) // has duplicates
                return true;
            swap(A[i - 1], A[A[i - 1] - 1]);
        } else
            i++;
    }

    return false;
}

// what if the problem is to let you return the number of duplicates

int num_dups(int A[], int n) {
    int res = 0;
    int i = 1;

    while (i <= n) {
        if (A[i - 1] != i && A[i - 1] != A[A[i - 1] - 1])
            swap(A[i - 1], A[A[i - 1] - 1]);
        else i++;
    }

    for (i = 1; i <= n; i++)
        if (A[i - 1] != i)
            res++;

    return res;
}

void test() {
    int A[] = {1, 2, 1, 1, 2, 4, 5, 3, 9, 5};

    cout << has_dups(A, sizeof(A) / sizeof(int)) << endl;

    cout << num_dups(A, sizeof(A) / sizeof(int)) << endl;
}