#include<stdio.h>
#include<stdlib.h>

void indexed(int memory[], int indexBlock[]);

int indexOfBlock;
int numberOfFile;

void indexedFileAllocation(int memory[], int indexBlock[]) {
    int temp = 0;
    for (int i = 0; i < numberOfFile; i++){
        scanf("%d", &indexBlock[i]);
        if (memory[indexBlock[i]] == 0)
            temp++;
    }
    if (temp == numberOfFile){
        for (int j = 0; j < numberOfFile; j++){
            memory[indexBlock[j]] = 1;
        }
        printf("Allocated\n");
        printf("File Indexed\n");
        for (int k = 0; k  < numberOfFile; k++){
            printf("%d ------> %d : %d\n", indexOfBlock, indexBlock[k], memory[indexBlock[k]]);
        }
    }
    else{
        printf("File in the index is already allocated\n");
        printf("Enter another indexed file\n");
        indexedFileAllocation(memory, indexBlock);
    }

    int choice;
    printf("Do you want to enter more files?\n");
    printf("Enter 1 for Yes, Enter 0 for No: \n");
    scanf("%d", &choice);
    if (choice == 1)
        indexed(memory, indexBlock);
    else
        exit(0);
}

void indexed(int memory[], int indexBlock[]) {
    
    printf("Enter the index block: \n");
    scanf("%d", &indexOfBlock);
    if (memory[indexOfBlock] != 1){
        printf("Enter number of files needed for the index %d on the disk: ", indexBlock);
        scanf("%d", &numberOfFile);
    }
    else{
        printf("%d is already allocated\n", indexOfBlock);
        indexed(memory, indexBlock);
    }
    indexedFileAllocation(memory, indexBlock);
}

void sequential(int memory[]) {
    int temp = 0; 
    int startBlock, len;

    printf("Enter starting block and the length of file: \n");
    scanf("%d %d", &startBlock, &len);
    for (int j = startBlock; j < (startBlock + len); j++){
        if (memory[j] == 0)
            temp++;
    }
    if(len == temp) {
        int k;
        for (k = startBlock; k < (startBlock + len); k++){
            if (memory[k] == 0){
                memory[k] = 1;
                printf("%d \t %d \n", k, memory[k]);
            }
        }
        if (k != (startBlock+len-1))
            printf("The file is allocated to the disk \n");
    }
    else
        printf("The file is not allocated to the disk \n");

    int choice;
    printf("Do you want to enter more files? \n");
    printf("Enter 1 for YES, 0 for NO: \n");
    scanf("%d", &choice);
    if (choice == 1)
        sequential(memory);
    else
        exit(0);
}

void linked(int memory[]) {
    int startBlock, len;
    int k, j;

    printf("Enter the index of the starting block and its length: \n");
    scanf("%d %d", &startBlock, &len);

    k = len;
    if (memory[startBlock] == 0){
        for (j = startBlock; j < (startBlock + k); j++){
            if (memory[j] == 0){
                memory[j] = 1;
                printf("%d------>%d\n", j, memory[j]);
            }
            else {
                printf("The block %d is already allocated \n", j);
                k++;
            }
        }
    }
    else
        printf("The block %d is already allocated \n", startBlock);

    int choice;    
    printf("Do you want to enter more files? \n");
    printf("Enter 1 for Yes, Enter 0 for No: ");
    scanf("%d", &choice);
    if (choice == 1)
        linked(memory);
    else
        exit(0);
}

void main() {
    int memoryBlocks;
    int totalBlocksAllocated;
    int temp;
    printf("Enter total memory blocks\n");
    scanf("%d", &memoryBlocks);

    int memory[memoryBlocks];
    int indexBlock[memoryBlocks];
    for (int i = 0; i < memoryBlocks; i++) {
        memory[i] = 0;
    }

    printf("Enter the number of blocks already allocated: \n");
    scanf("%d", &totalBlocksAllocated);

    if (totalBlocksAllocated > 0) {
        printf("Enter the blocks already allocated: \n");
        for (int i = 0; i < totalBlocksAllocated; i++){
            scanf("%d", &temp);
            memory[temp] = 1;
        }
    }

    int choice;
    printf("Enter the choice: 1- Sequential File Allocation, 2- Indexed File Allocation, 3- Linked File Allocation \n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            sequential(memory);
            break;
        case 2:
            indexed(memory, indexBlock);
            break;
        case 3:
            linked(memory);
            break;
        default:
            printf("Enter valid choice\n");
            break;
    }
}