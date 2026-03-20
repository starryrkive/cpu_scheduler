#include <stdio.h>
#include "scheduler.h"

void run_rr(Process p[], int n, int quantum)
{
    int timeline[MAX_TIME];

    int queue[MAX_TIME];
    int front = 0, rear = 0;

    int visited[MAX_PROCESSES] = {0};

    int time = 0;
    int completed = 0;
    int t_index = 0;

    printf("\nRunning Round Robin (q = %d)\n", quantum);

    /* reset remaining burst */
    for(int i = 0; i < n; i++)
        p[i].remaining = p[i].burst;

    /* initial arrival check */
    for(int i = 0; i < n; i++)
    {
        if(p[i].arrival <= time)
        {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while(completed < n)
    {
        /* if queue empty → CPU idle */
        if(front == rear)
        {
            timeline[t_index++] = -1;
            time++;

            /* check new arrivals */
            for(int i = 0; i < n; i++)
            {
                if(p[i].arrival <= time && visited[i] == 0)
                {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }

            continue;
        }

        int idx = queue[front++];

        int slice = (p[idx].remaining < quantum) ? p[idx].remaining : quantum;

        /* execute for 'slice' time */
        for(int i = 0; i < slice; i++)
        {
            timeline[t_index++] = p[idx].pid;
            time++;

            /* check arrivals during execution */
            for(int j = 0; j < n; j++)
            {
                if(p[j].arrival <= time && visited[j] == 0)
                {
                    queue[rear++] = j;
                    visited[j] = 1;
                }
            }
        }

        p[idx].remaining -= slice;

        /* if finished */
        if(p[idx].remaining == 0)
        {
            p[idx].completion = time;
            completed++;
        }
        else
        {
            /* re-add to queue */
            queue[rear++] = idx;
        }
    }

    display_gantt(timeline, t_index);
    calculate_metrics(p, n);
}
