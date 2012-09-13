class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        while (*s && isspace(*s)) s++;
        if (!*s) return false;

        const char *e = s + strlen(s) - 1;
        while (*e && isspace(*e)) e--;

        if (*s == '+' || *s == '-') s++;

        bool num = false; // is it a number? final result
        bool dot = false; // is there any . appear so far?
        bool exp = false; // is there any e appear so far?

        while (s != e + 1) {
            if (*s == '.') {
                if (dot || exp) return false;
                dot = true;
            } else if (*s == 'e') {
                if (!num) return false;
                if (exp) return false;
                exp = true;
                num = false;
            } else if (isdigit(*s)) {
                num = true;
            } else if (*s == '+' || *s == '-') {
                if (*(s - 1) != 'e') return false;
            } else
                return false;
            s++;
        }

        return num;
    }
};