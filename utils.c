#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "scheduler.h"

void manual_input(Process p[], int *n)
{
    printf("\nEnter number of processes: ");
    scanf("%d", n);

    for(int i=0;i<*n;i++)
    {
        p[i].pid = i + 1;

        printf("\nProcess P%d\n", p[i].pid);

        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);

        printf("Burst Time: ");
        scanf("%d", &p[i].burst);

        printf("Priority: ");
        scanf("%d", &p[i].priority);

        p[i].remaining = p[i].burst;
    }
}

void generate_random(Process p[], int *n)
{
    srand(time(NULL));

    printf("\nEnter number of processes: ");
    scanf("%d", n);

    printf("\nGenerated Processes\n");

    for(int i=0;i<*n;i++)
    {
        p[i].pid = i+1;

        p[i].arrival = rand() % 6;
        p[i].burst = rand() % 9 + 1;
        p[i].priority = rand() % 5 + 1;

        p[i].remaining = p[i].burst;
    }

    print_processes(p, *n);
}

void print_processes(Process p[], int n)
{
    printf("\nProcess Table\n");
    printf("-----------------------------\n");
    printf("PID\tArrival\tBurst\tPriority\n");

    for(int i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\n",
            p[i].pid,
            p[i].arrival,
            p[i].burst,
            p[i].priority);
    }

    printf("\n");
}
void wait_for_enter()
{
    printf("\nPress ENTER to return to the menu...");
    getchar();   // consume leftover newline
    getchar();   // wait for actual Enter
}
