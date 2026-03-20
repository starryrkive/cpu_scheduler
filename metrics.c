#include <stdio.h>
#include "scheduler.h"

void calculate_metrics(Process p[], int n)
{
    float avg_wt = 0;
    float avg_tat = 0;

    printf("\nProcess Table\n\n");

    printf("%-5s %-5s %-5s %-5s %-5s %-5s\n",
           "PID","AT","BT","CT","WT","TAT");

    for(int i=0;i<n;i++)
    {
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;

        avg_wt += p[i].waiting;
        avg_tat += p[i].turnaround;

        printf("%-5d %-5d %-5d %-5d %-5d %-5d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].completion,
               p[i].waiting,
               p[i].turnaround);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_wt/n);
    printf("Average Turnaround Time: %.2f\n", avg_tat/n);
}
