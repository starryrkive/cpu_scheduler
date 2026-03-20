#ifndef SCHEDULER_H
#define SCHEDULER_H

#define MAX_PROCESSES 100
#define MAX_TIME 1000

typedef struct
{
    int pid;
    int arrival;
    int burst;
    int remaining;
    int priority;

    int completion;
    int waiting;
    int turnaround;

} Process;


/* input utilities */

void manual_input(Process p[], int *n);
void generate_random(Process p[], int *n);
void print_processes(Process p[], int n);
void wait_for_enter();

/* schedulers */

void run_fcfs(Process p[], int n);
void run_sjf(Process p[], int n);
void run_srtf(Process p[], int n);
void run_rr(Process p[], int n, int quantum);
void run_priority(Process p[], int n);


/* visualization + metrics */

void display_gantt(int timeline[], int length);
void calculate_metrics(Process p[], int n);


/* algorithm race */

void race_algorithms(Process p[], int n);

#endif
