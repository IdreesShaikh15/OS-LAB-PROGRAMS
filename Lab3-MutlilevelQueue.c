#include<stdio.h>
#define MAX_PROCESSES 10

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int type;
} Processes;

void sort_by_arrival(Processes queue[], int n) {
    for (int i = 0; i < n-1; i++) { 
        for (int j = 0; j < n-1-i; j++) {  
            if (queue[j].arrival_time > queue[j + 1].arrival_time) {
                Processes temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }
}

void round_robin_scheduling(Processes queue[], int n, int time_quantum) {

    int wait_time = 0, turnaround_time = 0, completion_time = 0;
    int total_wait_time = 0, total_turnaround_time = 0;
   
    printf("\nProcess Execution Order:\n");
    for (int i = 0; i < n; i++) {
        if (completion_time < queue[i].arrival_time) {
            completion_time = queue[i].arrival_time;
        }
        wait_time = completion_time - queue[i].arrival_time;
        completion_time += queue[i].burst_time;
        turnaround_time = completion_time - queue[i].arrival_time;
       
        total_wait_time += wait_time;
        total_turnaround_time += turnaround_time;
       
        printf("Process %d $$ Arrival Time: %d $$ Burst Time: %d $$ Waiting Time: %d $$ Turnaround Time: %d\n",
                queue[i].pid, queue[i].arrival_time, queue[i].burst_time, wait_time, turnaround_time);
    }
   
    if (n > 0) {
        printf("\n Average Waiting Time: %.2f\n", (float)total_wait_time / n);
        printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
    }
}

int main() {
    Processes process_queue[MAX_PROCESSES];
    int total_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &total_processes);

    for (int i = 0; i < total_processes; i++) {
        printf("Enter Process ID, Arrival Time, Burst Time, and Type (0 for System, 1 for User): ");
        scanf("%d %d %d %d", &process_queue[i].pid, &process_queue[i].arrival_time, &process_queue[i].burst_time, &process_queue[i].type);
    }

    sort_by_arrival(process_queue, total_processes);
   
    Processes sorted_queue[MAX_PROCESSES];
    int index = 0;
   
    for (int i = 0; i < total_processes; i++) {
        if (process_queue[i].type == 0) {
            sorted_queue[index++] = process_queue[i];
        }
    }
    for (int i = 0; i < total_processes; i++) {
        if (process_queue[i].type == 1) {
            sorted_queue[index++] = process_queue[i];
        }
    }
   
    printf("\nExecuting Processes (Multi-Level Queue Scheduling)\n");
    round_robin_scheduling(sorted_queue, total_processes, 4); // Assuming a time quantum of 4

   
    return 0;
}
