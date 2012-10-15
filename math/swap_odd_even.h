/*
Write a program to swap odd and even bits in an integer with as few instructions as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc).
*/

int swap_odd_even_bits(int n) {
    return ((0xAAAAAAAA & n) >> 1) | ((0x55555555 & n) << 1);
}

void test() {
    int n = 12893;
    bitset<sizeof(int) * 8> bsn(n);
    cout << bsn << endl;
    bitset<sizeof(int) * 8> bss(swap_odd_even_bits(n));
    cout << "after swapping:" << bss << endl;
}
