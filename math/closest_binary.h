/*
  Given an integer, print the next smallest and next largest number that have the same number of 1 bits in their binary representation.
 */

void print_bin(int x) {
    bitset<sizeof(int) * 8> binary (x);
    cout << binary << endl;
}

int count_ones(int n) {
    int count = 0;
    while (n) {
        count++;
        n &= n - 1;
    }
    return count;
}

void brutal_force(int n) {
    int count = count_ones(n);
    int m = n;

    n++;
    while (count_ones(n) != count)
        n++;
    print_bin(n);

    m--;
    while (count_ones(m) != count)
        m--;
    print_bin(m);
}

int get_next_smallest(int n) {
    int index = 0, num_ones = 0;
    while (!get_bit(n, index))
        index++;

    while (get_bit(n, index)) {
        index++;
        num_ones++;
    }
    n = set_bit(n, index, 1);
    n = set_bit(n, index - 1, 0);
    index -= 2;
    num_ones--;

    for (int i = 0; i <= index; i ++) {
        if (i < num_ones) n = set_bit(n, i, 1);
        else n = set_bit(n, i, 0);
    }

    return n;
}

int get_prev_biggest(int n) {
    int index = 0, num_zeros = 0;
    while (get_bit(n, index)) {
        index++;
    }
    while (!get_bit(n, index)) {
        index++;
        num_zeros++;
    }

    n = set_bit(n, index, 0);
    n = set_bit(n, index - 1, 1);
    index -= 2;
    num_zeros--;

    for (int i = 0; i <= index; i++) {
        if (i < num_zeros) n = set_bit(n, i, 0);
        else n = set_bit(n, i, 1);
    }
    return n;
}

void test() {
    int n = 219841;
    print_bin(n);
    int next = get_next_smallest(n);
    print_bin(next);
    brutal_force(n);
    int prev = get_prev_biggest(n);
    print_bin(prev);
}
