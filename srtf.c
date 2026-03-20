#include <stdio.h>
#include <limits.h>
#include "scheduler.h"

void run_srtf(Process p[], int n)
{
    int timeline[MAX_TIME];

    int time = 0;
    int completed = 0;
    int t_index = 0;

    printf("\nRunning SRTF Scheduler\n");
    for(int i=0;i<n;i++)
    p[i].remaining = p[i].burst;
    
     while(completed < n)
    {
        int shortest = -1;
        int min_remaining = INT_MAX;

        /* find process with smallest remaining burst */

        for(int i = 0; i < n; i++)
        {
            if(p[i].arrival <= time && p[i].remaining > 0)
            {
                if(p[i].remaining < min_remaining)
                {
                    min_remaining = p[i].remaining;
                    shortest = i;
                }
            }
        }

        /* if no process is ready → CPU idle */

        if(shortest == -1)
        {
            timeline[t_index++] = -1;
            time++;
            continue;
        }

        /* execute process for 1 unit */

        timeline[t_index++] = p[shortest].pid;

        p[shortest].remaining--;
        time++;

        /* if process finished */

        if(p[shortest].remaining == 0)
        {
            p[shortest].completion = time;
            completed++;
        }
    }

    display_gantt(timeline, t_index);

    calculate_metrics(p, n);
}
