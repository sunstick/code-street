/*
 Check if a sequence of integers is a postorder traversal of some binary search tree (BST)
 */

bool hasBST(int *array, int a, int b) {
    if (a >= b)
        return true;

    if (array[a] > array[b])
        return false;

    int mid = a;
    while (mid < b && array[mid] <= array[b])
        mid++;

    return hasBST(array, a, mid - 1) && hasBST(array, mid, b - 1);
}

void test() {
    int array[] = {
        5, 7, 6, 9, 8, 10, 8
    };
    for (int i = 0; i < sizeof(array) / sizeof(int); i++)
        cout << hasBST(array, 0, i) << endl;
}
