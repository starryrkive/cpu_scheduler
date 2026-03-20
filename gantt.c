#include <stdio.h>
#include "scheduler.h"

void display_gantt(int timeline[], int length)
{
    printf("\nGantt Chart\n\n");

    /* top border */
    for(int i = 0; i < length; i++)
        printf("------");
    printf("-\n");

    /* process blocks */
    for(int i = 0; i < length; i++)
    {
        if(timeline[i] == -1)
            printf("| IDLE ");
        else
            printf("| P%-2d ", timeline[i]);
    }
    printf("|\n");

    /* bottom border */
    for(int i = 0; i < length; i++)
        printf("------");
    printf("-\n");

    /* time scale */
    for(int i = 0; i <= length; i++)
        printf("%-6d", i);

    printf("\n\n");
}
