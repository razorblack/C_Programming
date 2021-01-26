// Program to find the complement of a set 

#include<stdio.h>
#include<stdlib.h>

// Method to find the complement of a set
void complement(int universal[], int sizeUni, int set[], int sizeSet) {
    printf("Complement of the set is\n");
    
}

void main() {
    int size1; // Variable to store number of elements in universal set
    int size2; // Varible to store number of elements in given set

    printf("Enter the size of Universal set\n");
    scanf("%d",&size1);
    int universal[size1];
    printf("Enter elements of uniersal set\n");
    for(int i = 0; i < size1; i++) {
        scanf("%d",&universal[i]);
    }

    printf("Enter the size of set\n");
    scanf("%d",&size2);
    int set[size2];
    printf("Enter elements of the set\n");
    for(int i = 0; i < size2; i++) {
        scanf("%d",&set[i]);
    }

    if (size2 > size1) {
        printf("Size of can't be greater than Universal set\n");
        exit(0);
    }

    // Method calling to print complement of the set
    complement(universal, size1, set, size2);

}