#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void andLogic(int arr[4][3]) {
    //Logic for finding Boolean AND
    for (int i = 0; i < 4; i++) {
        arr[i][2] = arr[i][0] & arr[i][1];
    }

    printf("Boolean AND Table \n");
    printf("p \t q \t p & q \n");
    printf("----------------------\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d \t ",arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");

}

void orLogic(int arr[4][3]) {
    //Logic for finding Boolean OR
    for (int i = 0; i < 4; i++) {
        arr[i][2] = arr[i][0] | arr[i][1];
    }

    printf("Boolean OR Table \n");
    printf("p \t q \t p | q \n");
    printf("----------------------\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++ ) {
            printf("%d \t ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

void notLogic() {
     
    printf("Boolean NOT Table \n");
    printf("p \t ~p \n");
    printf("--------------\n");
    for (int i = 0; i <= 1; i++) {
        printf("%d \t %d \n",i, !i);
    }

}
int power(int base, int power) {
    int result = 1;
    if (base == 0 && power == 0) {
        return 0;
    } else if (base == 1 && power == 0) {
        return 0;
    }
    
    while (power > 0) {
        result = result * base;
        power--;
    }
    return result;
}

void main() {

    int arr[4][3];
    int i, j, result;

    // Logic for creating truth values in matrix
    for (i = 0; i <= 3; i++) {
        for (j = 0; j <= 1; j++) {
            arr[i][j] = power(i, j) % 2;
        }
    }

    andLogic(arr);
    orLogic(arr);
    notLogic();

}