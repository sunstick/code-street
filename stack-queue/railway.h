/*
一个队列按1 ~ n的顺序入栈，给定另外一个顺序，问可不可能按此顺序出栈
*/

const int MAXN = 1000 + 10;

bool possible(int *target, int n) {
    stack<int> s;
    int A = 1, B = 1;
    int ok = 1;
    while (B <= n) {
        if (A == target[B]) {
            A++; B++;
        } else if (!s.empty() && s.top() == target[B]) {
            s.pop(); B++;
        } else if (A <= n)
            s.push(A++);
        else {
            ok = 0; break;
        }
    }
    return ok;
}

void test() {
    int n, target[MAXN];
    while (cin >> n && n) {
        memset(target, 0, sizeof(target));
        cin >> target[1];
        if (!target[1]) {
            cout << endl;
            break;
        }
        for (int i = 2; i <= n; i++) {
            cin >> target[i];
        }
        bool f = possible(target, n);
        cout << (f ? "Yes" : "No") << endl;
    }
}
