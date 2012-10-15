/*
Find the elements in an array whose sum is the target sum.
The well known subset sum problem.
Brutal force method is used here.
*/

// one element can be used only once
// negative elements are allowed in array
void target_sum(int array[], int n, int target, vector<int> &p) {
    if (target == 0 && n == 0) {
        for (int i = 0; i < p.size(); ++i)
            cout << p[i] << " ";
        cout << endl;
        return ;
    }

    if (n == 0) return ;

    p.push_back(array[n - 1]);
    target_sum(array, n - 1, target - array[n - 1], p);
    p.pop_back();
    target_sum(array, n - 1, target, p);
}

// one element can be used multiple times
// negative element is not allowed here
void target_sum_dup(int array[], int n, int target, vector<int> &p) {
    if (target == 0) {
        for (int i = 0; i < p.size(); ++i)
            cout << p[i] << " ";
        cout << endl;
        return ;
    }

    if (n == 0 || target < 0) return ;

    p.push_back(array[n - 1]);
    target_sum_dup(array, n, target - array[n - 1], p);
    p.pop_back();
    target_sum_dup(array, n - 1, target, p);
}

void test() {
    int array[] = {1, 2, 3, 4, 5, 9};
    vector<int> v;
    target_sum(array, sizeof(array) / sizeof(int), 10, v);
    cout << "--------" << endl;
    target_sum_dup(array, sizeof(array) / sizeof(int), 10, v);
}