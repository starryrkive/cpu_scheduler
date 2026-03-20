#include <stdio.h>
#include "scheduler.h"

void run_sjf(Process p[], int n)
{
    int timeline[MAX_TIME];

    int completed = 0;
    int time = 0;
    int t_index = 0;

    int visited[MAX_PROCESSES] = {0};

    printf("\nRunning SJF Scheduler\n");

    while(completed < n)
    {
        int shortest = -1;

        /* find shortest job among arrived processes */

        for(int i = 0; i < n; i++)
        {
            if(p[i].arrival <= time && visited[i] == 0)
            {
                if(shortest == -1 || p[i].burst < p[shortest].burst)
                {
                    shortest = i;
                }
            }
        }

        /* if no process has arrived yet → CPU idle */

        if(shortest == -1)
        {
            timeline[t_index++] = -1;
            time++;
            continue;
        }

        /* run selected process completely */

        for(int j = 0; j < p[shortest].burst; j++)
        {
            timeline[t_index++] = p[shortest].pid;
            time++;
        }

        p[shortest].completion = time;

        visited[shortest] = 1;
        completed++;
    }

    display_gantt(timeline, t_index);

    calculate_metrics(p, n);
}
