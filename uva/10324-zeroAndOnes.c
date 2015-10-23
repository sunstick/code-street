#include<stdio.h>
#include<string.h>

int main() {
    char s[1000015];
    int t = 1, n, p1, p2, i, c, tem;
    while (scanf("%s", s) == 1) {
        if (strcmp(s, "\n") == 0)
            break;
        scanf("%d", &n);
        printf("Case %d:\n", t++);
        while (n--) {
            scanf("%d%d", &p1, &p2);
            if (p1 > p2) {
                tem = p1;
                p1 = p2;
                p2 = tem;
            }
            for (i = p1; i <= p2; i++) {

                if (s[i] == s[p1]) c = 1;
                else {
                    c = 0;
                    break;
                }
            }
            if (c == 1)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}