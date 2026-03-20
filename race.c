#include <stdio.h>
#include <string.h>
#include "scheduler.h"

/* helper: copy process array */
void copy_processes(Process src[], Process dest[], int n)
{
    for(int i = 0; i < n; i++)
        dest[i] = src[i];
}

/* helper: compute avg waiting time */
float avg_waiting(Process p[], int n)
{
    float sum = 0;

    for(int i = 0; i < n; i++)
    {
        int tat = p[i].completion - p[i].arrival;
        int wt = tat - p[i].burst;
        sum += wt;
    }

    return sum / n;
}

void race_algorithms(Process original[], int n)
{
    Process temp[MAX_PROCESSES];

    float fcfs_wt, sjf_wt, srtf_wt, rr_wt, prio_wt;

    printf("\n=========== ALGORITHM RACE ===========\n");

    /* FCFS */
    copy_processes(original, temp, n);
    run_fcfs(temp, n);
    fcfs_wt = avg_waiting(temp, n);

    /* SJF */
    copy_processes(original, temp, n);
    run_sjf(temp, n);
    sjf_wt = avg_waiting(temp, n);

    /* SRTF */
    copy_processes(original, temp, n);
    run_srtf(temp, n);
    srtf_wt = avg_waiting(temp, n);

    /* Round Robin */
    int q;
    printf("\nEnter quantum for RR: ");
    scanf("%d", &q);

    copy_processes(original, temp, n);
    run_rr(temp, n, q);
    rr_wt = avg_waiting(temp, n);

    /* Priority */
    copy_processes(original, temp, n);
    run_priority(temp, n);
    prio_wt = avg_waiting(temp, n);

    /* Results Table */

    printf("\n========== RESULTS ==========\n");

    printf("%-15s %-10s\n", "Algorithm", "Avg WT");
    printf("-----------------------------\n");

    printf("%-15s %-10.2f\n", "FCFS", fcfs_wt);
    printf("%-15s %-10.2f\n", "SJF", sjf_wt);
    printf("%-15s %-10.2f\n", "SRTF", srtf_wt);
    printf("%-15s %-10.2f\n", "Round Robin", rr_wt);
    printf("%-15s %-10.2f\n", "Priority", prio_wt);

    /* Find best */

    float best = fcfs_wt;
    char best_name[20] = "FCFS";

    if(sjf_wt < best) { best = sjf_wt; strcpy(best_name, "SJF"); }
    if(srtf_wt < best) { best = srtf_wt; strcpy(best_name, "SRTF"); }
    if(rr_wt < best) { best = rr_wt; strcpy(best_name, "Round Robin"); }
    if(prio_wt < best) { best = prio_wt; strcpy(best_name, "Priority"); }

    printf("\nBest Algorithm: %s (Avg WT = %.2f)\n", best_name, best);
}
