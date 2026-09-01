#include <stdio.h>
#include "common.h"

int main() {
    Prc p[20];
    int n, i, j;

    input(p, &n);

    /* Sort by Arrival Time */
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (p[j].at > p[j + 1].at)
                swap(&p[j], &p[j + 1]);

    p[0].ct = p[0].at + p[0].bt;

    for (i = 1; i < n; i++) {
        if (p[i].at > p[i - 1].ct)
            p[i].ct = p[i].at + p[i].bt;
        else
            p[i].ct = p[i - 1].ct + p[i].bt;
    }

    printf("\nFCFS Scheduling\n");
    output(p, n);

    return 0;
}