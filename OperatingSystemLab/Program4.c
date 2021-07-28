#include<stdio.h>

// structure of process
struct process {
    int arrivalTime;
    int burstTime;
    int processName;
    int waitingTime;
    int turnaroundTime;
};

// Method to display the content of structure
void display(struct process temp[], int size) {
    printf("\n");
    printf("Process Name \t Burst Time \t Arrival Time \t Waiting Time \t Turnaround Time \n");
    for (int i = 0; i < size; i++) {
        printf("P%d \t\t %d \t\t %d \t\t %d \t\t %d \n", temp[i].processName, temp[i].burstTime, temp[i].arrivalTime, temp[i].waitingTime, temp[i].turnaroundTime);
    }
}

// Method to sort structure for non zero arrival time 
void sorting(struct process processes[], int size) {
    // First sorting on basis of arrival time
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                struct process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    int tempBurst = 0;
    int tempArriv = 0;
    for (int i = 0; i < size - 1; i++) {
        tempArriv += processes[i].arrivalTime;
        for (int j = i; j < size - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime && (processes[j].arrivalTime >= processes[j + 1].arrivalTime || tempArriv <tempBurst)) {
                struct process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
        tempBurst += processes[i].burstTime; 
    }
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

    // Sorting structure processes according to arrival time of the processes
    sorting(processes, totalProcesses);

    // Array to implement gantt chart
    int ganttArray[totalProcesses + 1];
    ganttArray[0] = 0;
    for (int i = 1; i < (totalProcesses + 1); i++) {
        ganttArray[i] = processes[i - 1].burstTime + ganttArray[i - 1];
    }

    // Variable to store waiting time and turnaround time of all processess
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;

    // Calculation of waiting time and turn around time for each processes
    for (int i = 0; i < totalProcesses; i++) {
        processes[i].turnaroundTime = ganttArray[i + 1] - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
        
        totalWaitingTime = totalWaitingTime + processes[i].waitingTime;
        totalTurnaroundTime = totalTurnaroundTime + processes[i].turnaroundTime;
    }

    // Calculating the avgerage of waiting time and turn around time of array
    float avgWaitingTime = totalWaitingTime / totalProcesses;
    float avgTurnaroundTime = totalTurnaroundTime / totalProcesses;

    // Displaying the process details
    display(processes, totalProcesses);

    // Printing result
    printf("\n");
    printf("Avg. Waiting Time = %f \n", avgWaitingTime);
    printf("Avg. Turnaroud Time = %f \n", avgTurnaroundTime);
}