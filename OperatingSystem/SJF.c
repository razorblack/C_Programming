// Program to implement Shortest Job First (SJF) CPU scheduling algorithm
// Non Preemptive Approach
// Also called Shortest Job next (SJN)

#include<stdio.h>

// structure of process
struct process {
    int arrivalTime;
    int burstTime;
    int processName;

};

// Method to display the content of structure
void display(struct process temp[], int size) {
    printf("\n");
    printf("Process Name \t Burst Time \t Arrival Time \n");
    for (int i = 0; i < size; i++) {
        printf("P%d \t\t %d \t\t %d \n", temp[i].processName, temp[i].burstTime, temp[i].arrivalTime);
    }
}

// Method to calculate the average in array
float avgCalculation(int arr[], int size) {
    float avg;
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }
    avg = sum / size;
    return avg;
}

// Method to sort structure based on burst time in ascending order
void sorting(struct process processes[], int size) {
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                struct process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
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

    // Displaying the process details
    display(processes, totalProcesses);

    // Sorting structure processes according to burst time of the processes
    sorting(processes, totalProcesses);

    // Displaying the process details after sorting
    display(processes, totalProcesses);

    // Array to implement gantt chart
    int ganttArray[totalProcesses + 1];
    ganttArray[0] = 0;
    for (int i = 1; i < (totalProcesses + 1); i++) {
        ganttArray[i] = processes[i - 1].burstTime + ganttArray[i - 1];
    }

    // Arrays to store waiting time and turnaround time of all processess
    int waitingTime[totalProcesses];
    int turnaroundTime[totalProcesses];

    // Calculation of waiting time and turn around time for each processes
    for (int i = 0; i < totalProcesses; i++) {
        // waiting time = starting time - arrival time 
        waitingTime[i] = ganttArray[i] - processes[i].arrivalTime;
        // turnaround time = completion time - arrival time
        turnaroundTime[i] = ganttArray[i + 1] - processes[i].arrivalTime;
    }

    // Calculating the avgerage of waiting time and turn around time of array
    float avgWaitingTime = avgCalculation(waitingTime, totalProcesses);
    float avgTurnaroundTime = avgCalculation(turnaroundTime, totalProcesses);

    // Printing result
    printf("\n");
    printf("Avg. Waiting Time = %f \n", avgWaitingTime);
    printf("Avg. Turnaroud Time = %f \n", avgTurnaroundTime);
}

