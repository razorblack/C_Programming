// Program to implement Priority CPU scheduling algorithm
// Non-preemptive Approach 
// Note: Smaller number greater priority

#include<stdio.h>

// structure of process
struct process {
    int arrivalTime;
    int burstTime;
    int processName;
    int priority;
};

// Method to display the content of structure
void display(struct process temp[], int size) {
    printf("\n");
    printf("Process Name \t Burst Time \t Arrival Time \t Priority \n");
    for (int i = 0; i < size; i++) {
        printf("P%d \t\t %d \t\t %d  \t\t %d \n", temp[i].processName, temp[i].burstTime, temp[i].arrivalTime, temp[i].priority);
    }
}

// Method to sort structure according to Priority of processes
void sorting(struct process processes[], int size) {
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                struct process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
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

        // Priority
        printf("Enter Priority of process P%d \n", i);
        scanf("%d", &processes[i].priority);

        // Process name
        processes[i].processName = i;
    }

    // Displaying the process details
    display(processes, totalProcesses);

    // Sorting structure processes according to Priority of the processes
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

    // Calculation of average waiting time and average turn around time
    for (int i = 0; i < totalProcesses; i++) {
        waitingTime[i] = ganttArray[i] - processes[i].arrivalTime;
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

