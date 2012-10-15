/*
  Write a c program to count the number of words in a string.
*/

int count_words(const char *str) {
    bool inWord = false;
    int res = 0;

    while (*str) {
        if (inWord && !isalpha(*str)) {
            inWord = false;
        } else if (!inWord && isalpha(*str)) {
            res++;
            inWord = true;
        }
        str++;
    }

    return res;
}

void test() {
    const char *str =  "Hello, my name is John.";
    cout << count_words(str) << endl;
}
