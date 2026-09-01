#ifndef COMMON_H
#define COMMON_H

typedef struct{
    int id,at,bt,ct,tat,wt;
    int rem,comp;
}Prc;

void input(Prc p[], int *n);
void output(Prc p[], int n);
void swap(Prc *a, Prc *b);

#endif