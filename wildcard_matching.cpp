class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!s || !p )
            return false;

        const char *nextStar = strchr(p, '*');

        if ( !nextStar)
            return strCmp(s, p);

        if (!strCmpN(s, p, nextStar - p) )
            return false;

        do {
            s += nextStar - p;
            p = nextStar + 1;
            nextStar = strchr(p, '*');

            if (!nextStar)
                return strCmp(max(s, s + strlen(s) - strlen(p)), p);

            s = strStrN(s, p, nextStar - p);
        } while (s);

        return false;
    }

private:
    // Find substring of str that match length-n pattern p;
    // Consider '?' but not '*'
    const char *strStrN(const char *str, const char *p, int n) {
        const char *strEnd = str + strlen(str) - n + 1;
        while (str < strEnd && !strCmpN(str, p, n))
            str++;

        return str < strEnd ? str : NULL;
    }

    // compare if first n chars of str match length-n pattern target;
    // Consider '?' but not '*'
    bool strCmpN(const char *s, const char *p, int n) {
        const char *pEnd = p + n;
        while ( p != pEnd && *s && ( *s == *p  || *p == '?' ) ) {
            s++;
            p++;
        }

        return p == pEnd;
    }

    bool strCmp(const char *s, const char *p) {
        int n = strlen(p);
        if (strlen(s) != n)
            return false;

        return(strCmpN(s, p, n));
    }
};
