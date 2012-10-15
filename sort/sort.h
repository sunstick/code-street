/*
sorting functions.
*/

void insertionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        assert(isSorted(a, i + 1));
        int temp = a[i + 1];
        int j = i;

        while (j >= 0 && temp < a[j]) { // If the second condition is temp <= a[j], then the algorithm is not stable.
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }

    assert(isSorted(a, n));
}

void bubbleSort(int a[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        assert(isSorted(a + i, n - i));
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }

    assert(isSorted(a, n));
}

bool checkPartition(int a[], int i, int last) {
    int pivot = a[0];
    for (int x = 1; x <= last; x++)
        if (a[x] >= pivot)
            return false;
    for (int x = last + 1; x < i; x++)
        if (a[x] < pivot)
            return false;
    return true;
}

int partition(int a[], int n) {
    swap(a[0], a[rand() % n]);

    int pivot = a[0];
    int last = 0;
    for (int i = 1; i < n; i++) {
        assert(checkPartition(a, i, last));
        if (a[i] < pivot)
            swap(a[i], a[++last]);
    }
    swap(a[0], a[last]);
    return last;
}

void quickSort(int a[], int n) {
    if (n <= 1)
        return ;
    int k = partition(a, n);
    quickSort(a, k);
    quickSort(a + k + 1, n - k - 1);
    assert(isSorted(a, n));
}

void merge(int a[], int low, int mid, int high) {
    int *b = new int[high - low + 1];
    memset(b, 0, sizeof(b));

    int i = low, j = mid + 1, x = 0;
    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            b[x++] = a[i++];
        else
            b[x++] = a[j++];
    }

    if (i <= mid) {
        while (i <= mid)
            b[x++] = a[i++];
    }
    assert(i == mid + 1);

    if (j <= high)
        while (j <= high)
            b[x++] = a[j++];
    assert(j == high + 1);
    assert(x == high - low + 1);
    for (int i = 0; i < x; i++)
        a[low++] = b[i];

    delete b;
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void test() {
    int *b = new int(10);
    cout << *b << " " << sizeof(b) << endl;
    int *c = new int[10];
    cout << *c << " " << sizeof(c) << endl;

    int a[11] = {2, -1, 0, 12, -7, 6, 6, 19, 18, -100, 12};
    mergeSort(a, 0, 10);
    printArray(a, 11);
}
