#include<stdio.h>
#include<stdlib.h>

void main() {
    int n,m;
    int i, j;
    printf("Enter row \n");
    scanf("%d",&n);
    printf("Enter column \n");
    scanf("%d",&m);
    int arr[n][m];
    printf("Enter sparse matrix \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 0) {
                count++;
            }
        }
    }
    int matrix[count][3]; //to store sparse equivalent
    int index =0;
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
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

}