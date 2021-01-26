// Roll No. 38 Program to print Cartesian Product of a two sets

#include<stdio.h>

// Method to print cartesian product of a entered sets
void cartesianProduct(int setA[],int setB[],int n,int m) {

    printf("Cartesian Product Of entered Sets: \n");
    printf("{ ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf(" (%d, %d) ",setA[i], setB[j]);
        }
    }
    printf(" }");
}

void main() {
    int n, m;
    printf("Enter number of elements in first set \n");
    scanf("%d", &n);
    printf("Enter number of elements in second set \n");
    scanf("%d", &m);

    int setA[n];
    int setB[m];
    
    printf("Enter %d elements of first set \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &setA[i]);
    }
    printf("Enter %d elements of second set \n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &setB[i]);
    }
    
    cartesianProduct(setA, setB, n, m);  //Method Call for Cartesian Products of sets
}

