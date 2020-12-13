/*Program to implement linear search and binary search */

#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[], int size) {
    int i;
    printf("Current state of array: \n");
    for (i = 0; i < size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

// Arranging elements in order for Binary Search
void sort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size -1; i++) {
        for (j = 0; j < size -i- 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Method to perform Linear Search
void linearSearch(int arr[], int size, int item) {
    printArray(arr, size);
    int i;
    int index = -1;
    for (i = 0; i < size; i++) {
        if (arr[i] == item) {
            index = i;
        }
    }
    if (index == -1) {
        printf("Search Unsuccessful: Element not found \n");
    }
    else {
        printf("Search Successful: Element is present at index %d \n",index);
    }

}

//Method to perform Binary Search
void binarySearch(int arr[], int size, int item) {
    sort(arr, size);
    printArray(arr, size);
    int start = 0;
    int end = size -1;
    int mid = (start + end) / 2;
    int index = -1;
    while (index == -1 && start <= end) {
        if (arr[mid] == item) {
            index = mid;
        } else if (arr[mid] > item) {
            end = mid -1;
            mid = (start + end) / 2;
        } else {
            start = mid + 1;
            mid = (start + end) / 2;
        }
    }
    if (index == -1) {
        printf("Search Unsuccessful: Element not found \n");
    }
    else {
        printf("Search Successful: Element is present at index %d \n",index);
    }
}

void main() {
    int size;
    int i;
    printf("Enter size of array \n");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements of array \n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int searchItem;
    printf("Enter a number to search \n");
    scanf("%d",&searchItem);

    int choice;
    printf("Enter choice: 1- Linear Search, 2- Binary Search, 3- Exit \n");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                linearSearch(arr, size, searchItem);
                break;
            case 2:
                binarySearch(arr, size, searchItem);
                break;
            case 3:
                exit(0);
            default :
                printf("Enter Valid Choice \n");
        }
}