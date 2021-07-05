// Program to implement Round Robin CPU scheduling algorithm

// Preemptive Approach

#include<stdio.h>

// structure of process
struct process {
    int arrivalTime;
    int burstTime;
    int processName;

    int tempBurstTime; // To store copy of burst time
};

void main() {
    // Total number of processes
    int totalProcesses;
    printf("Enter the number of processes:\n");
    scanf("%d", &totalProcesses);

    // Array of structure to store processes content
    struct process processes[totalProcesses];
    
    // Taking input through user
    for (int i = 0; i < totalProcesses; i++) {
        // Arrival time
        printf("Enter arrival time of process P%d \n", i);
        scanf("%d", &processes[i].arrivalTime);

        // Burst time
        printf("Enter burst time of process P%d \n", i);
        scanf("%d", &processes[i].burstTime);

        // Storing copy of burst time
        processes[i].tempBurstTime = processes[i].burstTime;

        // Process name
        processes[i].processName = i;
    }

    // Time Quantum for processes
    int timeQuantum;
    printf("Enter the time quantum:\n");
    scanf("%d", &timeQuantum);

    
}