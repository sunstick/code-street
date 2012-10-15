// bit operations
int get_bit(int n, int index) {
    return (n & (1 << index)) > 0 ? 1 : 0;
}

int set_bit(int n, int index, int value) {
    if (value)
        return n | (1 << index);
    else
        int mask = ~(1 << index);
    return n & mask;
}
