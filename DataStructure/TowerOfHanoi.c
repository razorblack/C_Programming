#include<stdio.h>

// Method to solve Tower Of Hanoi Puzzle
void towerOfHanoi(int n, char currentRod, char auxRod, char finalRod) {
    if (n == 1) {
        printf("%c -> %c \n",currentRod,finalRod);
        return;
    } else {
        towerOfHanoi(n-1, currentRod, finalRod, auxRod);
        printf("%c -> %c \n",currentRod,finalRod);
        towerOfHanoi(n-1, auxRod, currentRod, finalRod);
    }
}

void main() {
    int stackSize; // To store no. of disks in stack
    printf("Enter no. of disks \n");
    scanf("%d",&stackSize);

    // Calling method for solution
    towerOfHanoi(stackSize,'A', 'B', 'C');
}