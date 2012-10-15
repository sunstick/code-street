/*
  Given two 32-bit numbers, n and m, and two bit positions, i and j.
  Write a method to set all bits between i and j in n equal to m.
*/

void print_bin(int x) {
    bitset<sizeof(int) * 8> binary (x);
    cout << binary << endl;
}

int setnm(int n, int m, int i, int j) {
    int x = (~0 << i);
    int z = (~0 << (i + j - 1));
    int s = ~(x ^ z);
    n &= s;
    n |= (m << i);
    return n;
}

void test() {
    int n = 0xff;
    print_bin(n);
    int m = 0xA;
    print_bin(m);
    int i = 2;
    int j = 5;
    n = setnm(n, m, i, j);
    print_bin(n);
}
