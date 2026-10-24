// Q5: Non-preemptive priority scheduling; smaller priority number means higher priority
// Assumption: all processes arrive at time 0.
#include <stdio.h>

int main(void) {
    int n, bt[50], pr[50], p[50], wt[50], tat[50], i, j, temp;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    if (n < 1 || n > 50) { printf("Invalid number of processes.\n"); return 1; }

    for (i = 0; i < n; i++) {
        printf("Enter burst time and priority for P%d: ", i + 1);
        scanf("%d%d", &bt[i], &pr[i]);
        if (bt[i] < 0) { printf("Burst time cannot be negative.\n"); return 1; }
        p[i] = i + 1;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[j] < pr[i]) {
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) wt[i] = wt[i - 1] + bt[i - 1];

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        total_wt += wt[i]; total_tat += tat[i];
        printf("P%d\t%d\t%d\t\t%d\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
    }
    printf("Average waiting time: %.2f\n", total_wt / n);
    printf("Average turnaround time: %.2f\n", total_tat / n);
    return 0;
}
