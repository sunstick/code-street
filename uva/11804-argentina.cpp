#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[22];
    int attack;
    int defense;
} player;

player argen[10];

int player_cmp(const void *v1, const void *v2) {
    player *p1 = (player *) v1;
    player *p2 = (player *) v2;
    if (p1->attack == p2->attack) {
        if (p1->defense == p2->defense)
            return strcmp(p1->name, p2->name);
        return p1->defense - p2->defense;
    }
    return p2->attack - p1->attack;
}

int playerre_cmp(const void *v1, const void *v2) {
    player *p1 = (player *) v1;
    player *p2 = (player *) v2;
    return strcmp(p1->name, p2->name);
}

int main() {
    int n = 0, att, def;
    char na[22];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int m = 10;
        while (m-- > 0) {
            scanf("%s %d %d", na, &att, &def);
            strcpy(argen[m].name, na);
            argen[m].attack = att;
            argen[m].defense = def;
        }
        qsort(argen, 10, sizeof(player), player_cmp);
        qsort(argen, 5, sizeof(player), playerre_cmp);
        qsort(argen + 5, 5, sizeof(player), playerre_cmp);
        printf("Case %d:\n(", i);
        for (int j = 0; j < 5; j++) {
            if (j != 4)
                printf("%s, ", argen[j].name);
            else
                printf("%s)\n(", argen[j].name);
        }
        for (int j = 5; j < 10; j++) {
            if (j != 9)
                printf("%s, ", argen[j].name);
            else
                printf("%s)\n", argen[j].name);
        }
    }

    return 0;
}
