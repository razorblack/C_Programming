#include<stdio.h>
#include<stdlib.h>

int difference(int setA[], int setB[], int n, int m) {
    int differ[n];
    int index=0;
    int present = 0;
    int data = 0;
    int i, j;
    for (i = 0; i < n; i++) {
        data = setA[i];
        for (j = 0; j < m; j++) {
            if (data == setB[j]) {
                present=1;
            }
        }
        if (present == 0) {
            differ[index] = data;
            index++;
        } else {
            present = 0;
        }
    }
    printf("Differnce of two sets i.e. A-B \n");
    for (i = 0; i < index; i++) {
        printf("%d ",differ[i]);
    }

}


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
    difference(setA, setB, n, m);  //Method Call for Difference of set i.e A-B
}