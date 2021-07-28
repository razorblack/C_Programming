#include<stdio.h>

void firstFit(int blockSize[], int totalBlocks, int processSize[], int totalProcess) {
    int allocation[totalProcess];

    for (int i = 0; i < totalProcess; i++) {
        allocation[i] = -1;   
    }

    for (int i = 0; i < totalProcess; i++) {
        for (int j = 0; j < totalBlocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] = blockSize[j] - processSize[i];
                break;
            }
        }
    }

    printf("Process NO. \t Process Size \t Block Number \n");
    for (int i = 0; i < totalProcess; i++) {
        printf("%d \t\t %d \t\t ", (i+1), processSize[i]);
        if (allocation[i] == -1) {
            printf("Not allocated");
        } else {
            printf("%d", allocation[i] + 1);
        }
        printf("\n");
    }
}

void bestFit(int blockSize[], int totalBlocks, int processSize[], int totalProcess) {
    int allocation[totalProcess];

    for (int i = 0; i < totalProcess; i++) {
        allocation[i] = -1;   
    }

    for (int i = 0; i < totalProcess; i++) {
        int bestIndex = -1;
        for (int j = 0; j < totalBlocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIndex == -1) {
                    bestIndex = j;
                } else if (blockSize[bestIndex] > blockSize[j]) {
                    bestIndex = j;
                }
            }
        }

        if (bestIndex != -1) {
            allocation[i] = bestIndex;
            blockSize[bestIndex] = blockSize[bestIndex] - processSize[i];
        }
    }

    printf("Process NO. \t Process Size \t Block Number \n");
    for (int i = 0; i < totalProcess; i++) {
        printf("%d \t\t %d \t\t ", (i+1), processSize[i]);
        if (allocation[i] == -1) {
            printf("Not allocated");
        } else {
            printf("%d", allocation[i] + 1);
        }
        printf("\n");
    }
}

void worstFit(int blockSize[], int totalBlocks, int processSize[], int totalProcess) {
    int allocation[totalProcess];

    for (int i = 0; i < totalProcess; i++) {
        allocation[i] = -1;   
    }

    for (int i = 0; i < totalProcess; i++) {
        int worstIndex = -1;
        for (int j = 0; j < totalBlocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIndex == -1) {
                    worstIndex = j;
                } else if (blockSize[worstIndex] < blockSize[j]) {
                    worstIndex = j;
                }
            }
        }

        if (worstIndex != -1) {
            allocation[i] = worstIndex;
            blockSize[worstIndex] = blockSize[worstIndex] - processSize[i];
        }
    }

    printf("Process NO. \t Process Size \t Block Number \n");
    for (int i = 0; i < totalProcess; i++) {
        printf("%d \t\t %d \t\t ", (i+1), processSize[i]);
        if (allocation[i] == -1) {
            printf("Not allocated");
        } else {
            printf("%d", allocation[i] + 1);
        }
        printf("\n");
    }
}



void main() {
    int numberOfBlocks;
    int numberOfProcess;

    printf("Enter number of partition blocks \n");
    scanf("%d", &numberOfBlocks);
    printf("Enter number of processes \n");
    scanf("%d", &numberOfProcess);

    int blockSize[numberOfBlocks];
    int processSize[numberOfProcess];

    printf("Enter blocks sizes \n");
    for (int i = 0; i < numberOfBlocks; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter process sizes \n");
    for (int i = 0; i < numberOfProcess; i++) {
        scanf("%d", &processSize[i]);
    }

    int choice;
    printf("Enter the choice: 1- Worst Fit, 2- Best Fit, 3- First Fit \n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            worstFit(blockSize, numberOfBlocks, processSize, numberOfProcess);
            break;
        case 2:
            bestFit(blockSize, numberOfBlocks, processSize, numberOfProcess);
            break;
        case 3:
            firstFit(blockSize, numberOfBlocks, processSize, numberOfProcess);
            break;
        default:
            printf("Enter valid choice\n");
            break;
    }
}