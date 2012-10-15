/*
  Write a function to determine the number of bits required to convert integer A to integer B.
 */

int bit_swap_required(int a, int b) {
    int c = a ^ b;
    int count = 0;
    while (c) {
        c = c & (c - 1);
        count++;
    }
    return count;
}

void test() {
    int a = 0;
    int b = 1;
    bitset<sizeof(int) * 8> bsa(a);
    bitset<sizeof(int) * 8> bsb(b);
    cout << bsa << endl;
    cout << bsb << endl;
    cout << "bit swap required: " << bit_swap_required(a, b) << endl;
}

