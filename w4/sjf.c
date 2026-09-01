#include <stdio.h>
#include "common.h"

int main() {
    Prc p[20];
    int n, i, shortest;
    int time = 0, completed = 0;

    input(p, &n);

    while (completed < n) {
        shortest = -1;

        /* Find shortest arrived process */
        for (i = 0; i < n; i++) {
            if (!p[i].comp && p[i].at <= time) {
                if (shortest == -1 ||
                    p[i].bt < p[shortest].bt)
                    shortest = i;
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        time += p[shortest].bt;
        p[shortest].ct = time;
        p[shortest].comp = 1;
        completed++;
    }

    printf("\nSJF Scheduling\n");
    output(p, n);

    return 0;
}