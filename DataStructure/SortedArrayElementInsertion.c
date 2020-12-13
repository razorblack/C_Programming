/* WAP to insert a new element in the existing sorted linear array (1D array) according to
its value. Take input the element from the user.*/
#include<stdio.h>
void main() {
    int i = 0; //Iterator variable
    int item = 0; // Element to be inserted
    int arr[6]; // Array of 6 elements
    // Taking Input (Assuming array is sorted)
    printf("Enter a sorted array of 5 elements \n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    // Entering element to be inserted
    printf("Enter a element to be inserted \n");
    scanf("%d", &item);
    
    // Logic to insert element in array
    for (i = 4; arr[i] >= item; i--) {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = item;

    // Printing Result
    printf("Array after inserting element \n");
    for (i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
}