#include<stdio.h>

struct system {
    // Variable for individual process number
    int process;

    // Array for allocation of 3 resources (say A, B, C) for individual process
    int allocation[3];
    
    // Array for max requirement of 3 resources (say A, B, C) for individual process
    int max[3];
};

// Array to keep record for 3 available resources (say A, B, C)
int available[3];

void main() {
    int totalProcess;
    printf("Enter the number of process\n");
    scanf("%d",&totalProcess);

    struct system systemResource[totalProcess];

    for (int i = 0; i < totalProcess; i++) {
        // Process Number
        systemResource[i].process = i;

        // Input Allocation resources (A, B, C) of processes
        printf("Enter Allocation resource (A, B, C) for process P%d \n", i);
        scanf("%d %d %d",&systemResource[i].allocation[0], &systemResource[i].allocation[1], &systemResource[i].allocation[2]);

        // Input Max resources (A, B, C) of processes
        printf("Enter Max resource (A, B, C) for process P%d \n", i);
        scanf("%d %d %d",&systemResource[i].max[0], &systemResource[i].max[1], &systemResource[i].max[2]);
    }

    // Input Available resources (A, B, C) of processes
    printf("Enter Available resource (A, B, C) for system \n");
    scanf("%d %d %d",&available[0], &available[1], &available[2]);

    // Printing need matrix
    int needMatrix[totalProcess][3];

    for (int i = 0; i < totalProcess; i++) {
        for (int j = 0; j < 3; j++) {
            needMatrix[i][j] = systemResource[i].max[j] - systemResource[i].allocation[j];
        }
    }
    printf("Need Matrix is as follows: \n");
    printf("Process \t A  B  C \n");
    for (int i = 0; i < totalProcess; i++) {
        printf("P%d \t\t ",i);
        for (int j = 0; j < 3; j++) {
            printf("%d  ",needMatrix[i][j]);
        }
        printf("\n");
    }

    // Checking for safe sequence
    int safeSequence[totalProcess];
    int index = 0;
    int finish[totalProcess];

    for (int i = 0; i < totalProcess; i++) {
        finish[i] = 0;
    }

    for (int i = 0; i < totalProcess; i++) {
        for (int j = 0; j < totalProcess; j++) {
            if (finish[j] == 0) {
                int temp = 0;
                for (int k = 0; k < 3; k++) {
                    if (needMatrix[j][k] > available[k]) {
                        temp = 1;
                        break;
                    }
                }

                if (temp == 0) {
                    safeSequence[index++] = j;
                    for (int k = 0; k < 3; k++) {
                        available[k] += systemResource[j].allocation[k];
                    }
                    finish[j] = 1;
                }
            }
        }
    }

    printf("SAFE Sequence is as follows:\n");
    for (int i = 0; i < totalProcess - 1; i++) {
        printf(" P%d ->", safeSequence[i]);
    }
    printf(" P%d", safeSequence[totalProcess - 1]);
}