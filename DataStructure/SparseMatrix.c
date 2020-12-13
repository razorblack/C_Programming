/*Program to implement a Sparse Matrix in Triplet(Array) representation */

#include<stdio.h>
#include<stdlib.h>

void main() {
    int n,m;
    int i, j;
    printf("Enter row of matrix\n");
    scanf("%d",&n);
    printf("Enter column of matrix\n");
    scanf("%d",&m);
    int arr[n][m];
    printf("Enter sparse matrix \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int count = 0;  // To count the number of non zero elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 0) {
                count++;
            }
        }
    }
    int matrix[count][3]; //to store sparse equivalent
    int index = 0; // To store row of equivalent matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 0 && index < count) {
                matrix[index][0] = i;  
                matrix[index][1] = j;
                matrix[index][2] = arr[i][j];
                index++;
            }
        }

    }

    // Printing Sparse Equivalent matrix in form [i j NonZeroValue]
    printf("Sparese Matrix in Triplet form \n");
    printf("i j value \n");

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

}