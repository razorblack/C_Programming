/* Program to delete any existing element of the given linear array from any specified position/location. */

#include<stdio.h>

void main() {
    int size;
    printf("Enter size of array \n");
    scanf("%d",&size);
    int arr[size]; //Array of elements
    int location; // Location of element to be deleted
    // Array Input
    printf("Enter array of %d integers \n",size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Location Input
    do{
        printf ("Enter a location between 1 and %d to delete \n",size);
        scanf ("%d", &location);
    } while(location < 1 || location > size);

    //Deleting element logic
    for (int i = location - 1; i < size; i++) {
        arr[i] = arr[i + 1];
    }

    // Printing array without last element
    printf("Array after deletion \n");
    for (int i = 0; i < size - 1; i++) {
        printf("%d ", arr[i]);
    }
}