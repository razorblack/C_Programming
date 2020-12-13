/* Program in C to delete any element in a linear array on the basis of its value*/

#include<stdio.h>

int isPresent(int arr[], int x);

void main() {
    int i = 0;
    int arr[5];
    int isElementPresent = 0;
    int value;
    printf("Enter 5 elements of a array \n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter a value of element to remove \n");
    scanf("%d", &value);
    isElementPresent = isPresent(arr, value);
    if (isElementPresent == -1) {
        printf("Enter correct value to remove \n");
    } else {
        for (i = isElementPresent; i < 4; i++) {
            arr[i] = arr[i+1];
        }
        printf("Array Elements after deletion \n");
        for (i = 0; i < 4; i++) {
            printf("%d ", arr[i]);
        }

    }
}
int isPresent(int arr[], int x) {
    for (int i = 0; i < 5; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}