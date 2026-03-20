#include <stdio.h>
#include "scheduler.h"

/* simple arrival time sort */

void sort_by_arrival(Process p[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].arrival > p[j+1].arrival)
            {
                Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void run_fcfs(Process p[], int n)
{
    int timeline[MAX_TIME];
    int time = 0;
    int t_index = 0;

    sort_by_arrival(p,n);

    printf("\nRunning FCFS Scheduler\n");

    for(int i=0;i<n;i++)
    {

        /* CPU idle if next process hasn't arrived */

        while(time < p[i].arrival)
        {
            timeline[t_index++] = -1;
            time++;
        }

        /* run process */

        for(int j=0;j<p[i].burst;j++)
        {
            timeline[t_index++] = p[i].pid;
            time++;
        }

        p[i].completion = time;
    }

    display_gantt(timeline,t_index);

    calculate_metrics(p,n);
}
