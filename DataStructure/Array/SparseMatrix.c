/* Program to convert 2D matrix into sparse representation and vice versa */

#include<stdio.h>
#include<stdlib.h>

void matrixToSparse(int n, int m) {
    int i, j;
    int arr[n][m];
    printf("Enter a matrix \n");
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
    printf("Matrix in Sparse format \n");
    printf("i j value \n");

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

}

//Method to convert sparse format into 3D matrix
void sparseToMatrix(int row, int column) {
    int matrix[row][column]; //Sparse format of matrix
    printf("Enter Sparse Format \n");
    printf("i j value \n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }

    int arr[row][row]; //2D matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (i == matrix[i][0] && j == matrix[i][1]) {
                arr[i][j] = matrix[i][2];
            } else {
                arr[i][j] = 0;
            }
        }
    }

    //Printing 2D matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void main() {
    
    int choice;
    int row, column;
    do {
        printf("Enter choice- 1: Matrix to Sparse, 2: Sparse To Matrix, 3: Exit\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
               
                printf("Enter row of matrix\n");
                scanf("%d",&row);
                printf("Enter column of matrix\n");
                scanf("%d",&column);
                matrixToSparse(row, column);
                break;
            case 2:
                printf("Enter no. of row entries \n");
                scanf("%d",&row);
                sparseToMatrix(row, 3);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Enter valid choice \n");
                break;
        }
    } while(choice < 1 || choice > 3);
}