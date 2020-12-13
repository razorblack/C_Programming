/* Program to implement sorting algorithms: Bubble sort, Selection sort, Insertion sort, Quick sort and Merge sort */

#include<stdio.h>
#include<stdlib.h>

//Method to display array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ",arr[i]);
    }
}

//Method to implement Bubble Sort
void bubbleSort(int arr[], int size) {
    printf("Entered Array is: \n");
    display(arr, size);
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}

//Method to implement Selection Sort
void selectionSort(int arr[], int size) {
    printf("Entered Array is: \n");
    display(arr, size);

    int i, j, smallIndex, temp;
    for (i = 0; i < (size - 1); i++) {
      smallIndex = i;
      for (j = i + 1; j < size; j++) {
         if (arr[smallIndex] > arr[j])
            smallIndex = j;
      }
      if (smallIndex != i) {
         temp = arr[i];
         arr[i] = arr[smallIndex];
         arr[smallIndex] = temp;
      }
   }


}

//Method to implement Insertion Sort
void insertionSort(int arr[], int size) {
    printf("Entered Array is: \n");
    display(arr, size);

    int i, j, temp;
    for(i = 1; i < size; i++) {
      temp = arr[i];
      j = i - 1;
      while((temp < arr[j]) && j>=0) {
         arr[j+1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = temp;
   }

}

//Method to implement Quick Sort
void quickSort(int arr[], int size) {
    printf("Entered Array is: \n");
    display(arr, size);

}

//Method to implement Merge Sort
void mergeSort(int arr[], int size) {
    printf("Entered Array is: \n");
    display(arr, size);

}

void main() {
    int i;
    int size;
    printf("Enter size of array\n");
    scanf("%d",&size);
    int arr[size];
    printf("Enter %d elements of array \n",size);
    for (i = 0; i < size; i++) {
        scanf("%d",&arr[i]);
    }
    int choice;
    printf("Enter choice for sorting- 1: Bubble Sort, 2: Selection Sort, 3: Insertion Sort, 4: Quick Sort, 5: Merge Sort, 6: Exit \n");
    scanf("%d",&choice);
    switch(choice) {
        case 1:
            bubbleSort(arr, size);
            break;
        case 2:
            selectionSort(arr, size);
            break;
        case 3:
            insertionSort(arr, size);
            break;
        case 4:
            quickSort(arr, size);
            break;
        case 5:
            mergeSort(arr, size);
            break;
        case 6:
            exit(0);
        default:
            printf("Enter Valid Choice \n");
            break;
    }
    printf("\nArray after sorting \n");
    display(arr, size);

    

}
