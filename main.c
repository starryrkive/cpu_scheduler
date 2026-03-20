#include <stdio.h>
#include "scheduler.h"

Process processes[MAX_PROCESSES];
int n = 0;

int main()
{
    int choice;
    int quantum;

    while(1)
    {
        printf("\n=================================\n");
        printf("      CPU Scheduler Simulator\n");
        printf("=================================\n\n");

        printf("1 Manual Process Input\n");
        printf("2 Random Workload Generator\n");
        printf("3 Display Process Table\n\n");

        printf("Scheduling Algorithms\n");
        printf("4 FCFS\n");
        printf("5 SJF\n");
        printf("6 SRTF\n");
        printf("7 Round Robin\n");
        printf("8 Priority Scheduling\n\n");

        printf("9 Algorithm Race Mode\n");
        printf("10 Exit\n");

        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {

            case 1:
                manual_input(processes,&n); wait_for_enter();
                break;

            case 2:
                generate_random(processes,&n); wait_for_enter();
                break;

            case 3:
                print_processes(processes,n); wait_for_enter();
                break;

            case 4:
                run_fcfs(processes,n); wait_for_enter();
                break;

            case 5:
                run_sjf(processes,n); wait_for_enter();
                break;

            case 6:
                run_srtf(processes,n); wait_for_enter();
                break;

            case 7:

                printf("\nEnter time quantum: ");
                scanf("%d",&quantum);

                run_rr(processes,n,quantum); wait_for_enter();
                break;

            case 8:
                run_priority(processes,n); wait_for_enter();
                break;

            case 9:
                race_algorithms(processes,n); wait_for_enter();
                break;

            case 10:
                printf("\nExiting simulator\n"); 
                return 0;

            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}
