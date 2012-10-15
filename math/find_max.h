/*
  Write a method which finds the maximum of two numbers. You should not use if-else or any other comparison operator.
 */

int findMax(int a, int b) {
    int c = a - b;
    c = c >> 31 & 0x1;
    return a - c * (a - b);
}

void test() {
}
