#include<stdio.h>
#include "common.h"

void input(Prc p[],int *n){
    int i;
    printf("Enter number of processes: ");
    scanf("%d", n);
    for (i = 0; i < *n; i++) {
        p[i].id = i + 1;
        printf("P%d AT BT: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rem = p[i].bt;
        p[i].comp = 0;
    }
}
void output(Prc p[], int n) {
    int i;
    float total_wt = 0, total_tat = 0;

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt);

        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    printf("\nAverage TAT = %.2f", total_tat / n);
    printf("\nAverage WT  = %.2f\n", total_wt / n);
}

void swap(Prc *a, Prc *b) {
    Prc temp = *a;
    *a = *b;
    *b = temp;
}