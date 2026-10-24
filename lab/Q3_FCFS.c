// Q3: First Come First Served CPU scheduling (all arrival times are 0)
#include <stdio.h>

int main(void) {
    int n, bt[50], wt[50], tat[50], i;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    if (n < 1 || n > 50) { printf("Invalid number of processes.\n"); return 1; }

    for (i = 0; i < n; i++) {
        printf("Burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        if (bt[i] < 0) { printf("Burst time cannot be negative.\n"); return 1; }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) wt[i] = wt[i - 1] + bt[i - 1];

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time: %.2f\n", total_wt / n);
    printf("Average turnaround time: %.2f\n", total_tat / n);
    return 0;
}
