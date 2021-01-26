/* Program to implement sorting algorithms: Bubble sort, Selection sort, Insertion sort, Quick sort and Merge sort */

#include<stdio.h>
#include<stdlib.h>

//Method to display array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

// Function to swap position of elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

//Method to implement Bubble Sort
void bubbleSort(int arr[], int size) {
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

// Function to partition the array on the basis of pivot element
int partition(int array[], int low, int high) {
  
  // Select the pivot element
  int pivot = array[high];
  int i = (low - 1);

  // Put the elements smaller than pivot on the left and greater than pivot on the right of pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

//Method to implement Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Select pivot position and put all the elements smaller 
        // than pivot on left and greater than pivot on right
        int pi = partition(arr, low, high);
        // Sort the elements on the left of pivot
        quickSort(arr, low, pi - 1);
        // Sort the elements on the right of pivot
        quickSort(arr, pi + 1, high);
  }
}

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

//Method to implement Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
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

    printf("Entered Array is: \n");
    display(arr, size);

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
            quickSort(arr, 0, size -1);
            break;
        case 5:
            mergeSort(arr, 0, size - 1);
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
