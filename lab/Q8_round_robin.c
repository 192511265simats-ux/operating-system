// Q8: Round Robin CPU scheduling
#include <stdio.h>

int main(void) {
    int n, at[50], bt[50], rem[50], ct[50], tat[50], wt[50];
    int quantum, time = 0, completed = 0, i, progressed;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    if (n < 1 || n > 50) { printf("Invalid number of processes.\n"); return 1; }

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        if (at[i] < 0 || bt[i] < 1) { printf("Invalid arrival or burst time.\n"); return 1; }
        rem[i] = bt[i];
    }
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    if (quantum < 1) { printf("Time quantum must be positive.\n"); return 1; }

    while (completed < n) {
        progressed = 0;
        for (i = 0; i < n; i++) {
            if (rem[i] > 0 && at[i] <= time) {
                int run = rem[i] < quantum ? rem[i] : quantum;
                rem[i] -= run;
                time += run;
                progressed = 1;
                if (rem[i] == 0) {
                    ct[i] = time;
                    completed++;
                }
            }
        }
        if (!progressed) time++;
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i]; total_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time: %.2f\n", total_wt / n);
    printf("Average turnaround time: %.2f\n", total_tat / n);
    return 0;
}
