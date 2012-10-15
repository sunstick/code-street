/*
 Reverse a stack recursively
 */

#define N 8

void recursive_push(stack<int> &st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();
    recursive_push(st, x);
    st.push(temp);
}

void reverse_stack(stack<int> &st) {
    if (st.empty())
        return ;
    int topE = st.top();
    st.pop();
    reverse_stack(st);
    recursive_push(st, topE);
}

void test() {
    stack<int> a;
    for (int i = 0; i < N; i++)
        a.push(i);

    reverse_stack(a);
    while (!a.empty()) {
        cout << a.top() << " ";
        a.pop();
    }
    cout << endl;
}
