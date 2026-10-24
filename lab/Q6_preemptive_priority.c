// Q6: Preemptive priority scheduling; smaller priority number means higher priority
#include <stdio.h>

int main(void) {
    int n, at[50], bt[50], rem[50], pr[50], ct[50], tat[50], wt[50];
    int i, time = 0, completed = 0, best;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    if (n < 1 || n > 50) { printf("Invalid number of processes.\n"); return 1; }

    for (i = 0; i < n; i++) {
        printf("Enter arrival time, burst time and priority for P%d: ", i + 1);
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]);
        if (at[i] < 0 || bt[i] < 1) { printf("Invalid arrival or burst time.\n"); return 1; }
        rem[i] = bt[i];
        ct[i] = 0;
    }

    while (completed < n) {
        best = -1;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rem[i] > 0) {
                if (best == -1 || pr[i] < pr[best] ||
                    (pr[i] == pr[best] && at[i] < at[best])) best = i;
            }
        }
        if (best == -1) { time++; continue; }

        rem[best]--;
        time++;
        if (rem[best] == 0) {
            ct[best] = time;
            completed++;
        }
    }

    printf("\nProcess\tAT\tBT\tPriority\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i]; total_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               i + 1, at[i], bt[i], pr[i], wt[i], tat[i]);
    }
    printf("Average waiting time: %.2f\n", total_wt / n);
    printf("Average turnaround time: %.2f\n", total_tat / n);
    return 0;
}
