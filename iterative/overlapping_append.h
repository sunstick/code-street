/*
The last n digits of string A overlaps with the first n digits of string B append B to append A, the overlapping part appears only once in the result string
*/

string appendad(string &a, string &b) {
    int i = 0;
    while (i < a.size()) {
        string x = a.substr(i);
        int n = x.size();
        string y = b.substr(0, x.size());
        if (x == y)
            break;
        i++;
    }
    return a.substr(0, i) + b;
}

void test() {
    string a = "www2.uic.edu/~csu6/";
    string b = "~csu6/xyz.pdf";
    cout << appendad(a, b) << endl;
}
