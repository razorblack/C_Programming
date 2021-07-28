#include<stdio.h>

// structure of process
struct process {
    int arrivalTime;
    int burstTime;
    int processName;
    int waitingTime;
    int turnaroundTime;
    int priority;
};

// Method to display the content of structure
void display(struct process temp[], int size) {
    printf("\n");
    printf("Process Name \t Burst Time \t Arrival Time \t Waiting Time \t Turnaround Time \n");
    for (int i = 0; i < size; i++) {
        printf("P%d \t\t %d \t\t %d \t\t %d \t\t %d \n", temp[i].processName, temp[i].burstTime, temp[i].arrivalTime, temp[i].waitingTime, temp[i].turnaroundTime);
    }
}

void priorityScheduling(struct process processes[], int size) {
    // Entering priority of processes
    printf("Enter priority of each process\n");
    printf("Note: Lower number higher priority \n");
    for (int i = 0; i < size; i++) {
        printf("Priority for P%d = ",i);
        scanf("%d",&processes[i].priority);
    }

    // Sorting processes on the basis of priority
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                struct process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Array to implement gantt chart
    int ganttArray[size + 1];
    ganttArray[0] = 0;
    for (int i = 1; i < (size + 1); i++) {
        ganttArray[i] = processes[i - 1].burstTime + ganttArray[i - 1];
    }

    // Variable to store waiting time and turnaround time of all processess
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;

    // Calculation of waiting time and turn around time for each processes
    for (int i = 0; i < size; i++) {
        processes[i].turnaroundTime = ganttArray[i + 1] - processes[i].arrivalTime;
        processes[i].waitingTime = ganttArray[i];
        
        totalWaitingTime = totalWaitingTime + processes[i].waitingTime;
        totalTurnaroundTime = totalTurnaroundTime + processes[i].turnaroundTime;
    }

    // Calculating the avgerage of waiting time and turn around time of array
    float avgWaitingTime = totalWaitingTime / size;
    float avgTurnaroundTime = totalTurnaroundTime / size;

    // Displaying the process details
    display(processes, size);

    // Printing result
    printf("\n");
    printf("Avg. Waiting Time = %f \n", avgWaitingTime);
    printf("Avg. Turnaroud Time = %f \n", avgTurnaroundTime);
}

void roundRobinScheduling(struct process processes[], int size) {
    int timeQuantum;
    printf("Enter time quantum \n");
    scanf("%d",&timeQuantum);

    // Sorting processes on the basis of arrival time
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                struct process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Gantt Chart 
    int totalBurstTime = 0;
    int burst[size];
    for (int i = 0; i < size; i++) {
        totalBurstTime += processes[i].burstTime;
        burst[i] = processes[i].burstTime;
    }

    int ganttSize;
    if (totalBurstTime % timeQuantum == 0) {
        ganttSize = totalBurstTime / timeQuantum;
    } else {
        ganttSize = totalBurstTime / timeQuantum + 1;
    }

    // Array to implement gantt chart
    int ganttArray[ganttSize];
    for (int i = 0; i < ganttSize; i++) {
        int index = i % size;
        if (burst[i] - timeQuantum > 0) {
            ganttArray[i] = index;
            burst[i] -= timeQuantum;
        }
    }

    // Variable to store waiting time and turnaround time of all processess
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;

    // Calculation of waiting time and turn around time for each processes
    for (int i = 0; i < size; i++) {
        int index = -1;
        for (int j = 0; j < ganttSize; j++) {
            if (ganttArray[j] == i) {
                index = j;
            }
        }

        processes[i].turnaroundTime = (index + 1) * timeQuantum - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
        
        totalWaitingTime = totalWaitingTime + processes[i].waitingTime;
        totalTurnaroundTime = totalTurnaroundTime + processes[i].turnaroundTime;
    }

    // Calculating the avgerage of waiting time and turn around time of array
    float avgWaitingTime = totalWaitingTime / size;
    float avgTurnaroundTime = totalTurnaroundTime / size;

    // Displaying the process details
    display(processes, size);

    // Printing result
    printf("\n");
    printf("Avg. Waiting Time = %f \n", avgWaitingTime);
    printf("Avg. Turnaroud Time = %f \n", avgTurnaroundTime);
}

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

        // Process name
        processes[i].processName = i;
    }

    int choice;
    printf("Enter the choice: 1- Priority Scheduling, 2- Round Robin \n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            priorityScheduling(processes, totalProcesses);
            break;
        case 2:
            roundRobinScheduling(processes, totalProcesses);
            break;
        default:
            printf("Enter valid choice\n");
            break;
    }
}

