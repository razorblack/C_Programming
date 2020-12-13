#include<stdio.h>

void cartesianProduct(int setA[],int setB[],int n,int m);

void main() {
    int n; 
    int m;
    printf("Enter elements in first set \n");
    scanf("%d", &n);
    printf("Enter elements in second set \n");
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

void cartesianProduct(int setA[],int setB[],int n,int m) {
    int i,j;
    printf("Cartesian Product Of Sets is : \n");
    printf("{ ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf(" (%d, %d) ",setA[i], setB[j]);
        }
    }
    printf(" }");
}
