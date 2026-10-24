// Q7: Non-preemptive SJF scheduling with arrival times
#include <stdio.h>

int main(void) {
    int n, at[50], bt[50], done[50] = {0}, ct[50], wt[50], tat[50];
    int i, time = 0, completed = 0, best;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    if (n < 1 || n > 50) { printf("Invalid number of processes.\n"); return 1; }

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        if (at[i] < 0 || bt[i] < 1) { printf("Invalid arrival or burst time.\n"); return 1; }
    }

    while (completed < n) {
        best = -1;
        for (i = 0; i < n; i++) {
            if (!done[i] && at[i] <= time) {
                if (best == -1 || bt[i] < bt[best] ||
                    (bt[i] == bt[best] && at[i] < at[best])) best = i;
            }
        }
        if (best == -1) { time++; continue; }

        time += bt[best];
        ct[best] = time;
        tat[best] = ct[best] - at[best];
        wt[best] = tat[best] - bt[best];
        done[best] = 1;
        completed++;
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        total_wt += wt[i]; total_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time: %.2f\n", total_wt / n);
    printf("Average turnaround time: %.2f\n", total_tat / n);
    return 0;
}
