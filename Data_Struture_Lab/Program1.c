/* Program to insert a new element in the existing linear array at any specified position/location.*/


#include<stdio.h>

void main() {
    int size;
    printf("Enter size of array \n");
    scanf("%d",&size);
    int arr[size + 1];  // Array of entered size
    int location; //Location to enter element
    int item; // Element to be inserted
    printf("Enter array of %d integers \n",size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf ("Enter a element to insert \n");
    scanf ("%d", &item);
    do {
        printf ("Enter a location between 1 and %d to insert \n",size);
        scanf ("%d", &location);
    } while(location < 1 || location > size);

    //Inserting element logic
    for (int i = size; i >= location-1; i--) {
        arr[i + 1] = arr[i];

    }
    arr[location - 1] = item;
    printf("Array after insertion \n");
    for (int i = 0; i < size + 1; i++) {
        printf("%d ", arr[i]);
    }
}