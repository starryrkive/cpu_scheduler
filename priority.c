#include <stdio.h>
#include "scheduler.h"

void run_priority(Process p[], int n)
{
    int timeline[MAX_TIME];

    int completed = 0;
    int time = 0;
    int t_index = 0;

    int visited[MAX_PROCESSES] = {0};

    printf("\nRunning Priority Scheduling\n");

    while(completed < n)
    {
        int highest = -1;

        /* find highest priority among arrived processes */
        for(int i = 0; i < n; i++)
        {
            if(p[i].arrival <= time && visited[i] == 0)
            {
                if(highest == -1 || p[i].priority < p[highest].priority)
                {
                    highest = i;
                }
            }
        }

        /* CPU idle */
        if(highest == -1)
        {
            timeline[t_index++] = -1;
            time++;
            continue;
        }

        /* run process completely */
        for(int j = 0; j < p[highest].burst; j++)
        {
            timeline[t_index++] = p[highest].pid;
            time++;
        }

        p[highest].completion = time;

        visited[highest] = 1;
        completed++;
    }

    display_gantt(timeline, t_index);
    calculate_metrics(p, n);
}
