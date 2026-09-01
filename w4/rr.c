#include <stdio.h>
#include "common.h"

int main() {
    Prc p[20];
    int queue[100], visited[20] = {0};
    int n, quantum, front = 0, rear = 0;
    int time, i, j, completed = 0;

    input(p, &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    time = p[0].at;

    /* Add first arrived processes */
    for (i = 0; i < n; i++) {
        if (p[i].at <= time) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while (completed < n) {

        /* If queue is empty */
        if (front == rear) {
            time++;

            for (i = 0; i < n; i++) {
                if (!visited[i] && p[i].at <= time) {
                    queue[rear++] = i;
                    visited[i] = 1;
                    break;
                }
            }
        }

        i = queue[front++];

        if (p[i].rem > quantum) {
            time += quantum;
            p[i].rem -= quantum;
        }
        else {
            time += p[i].rem;
            p[i].rem = 0;
            p[i].ct = time;
            completed++;
        }

        /* Add newly arrived processes */
        for (j = 0; j < n; j++) {
            if (!visited[j] && p[j].at <= time) {
                queue[rear++] = j;
                visited[j] = 1;
            }
        }

        /* Put current process back */
        if (p[i].rem > 0)
            queue[rear++] = i;
    }

    printf("\nRound Robin Scheduling\n");
    output(p, n);

    return 0;
}