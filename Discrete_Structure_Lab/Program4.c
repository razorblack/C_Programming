#include<stdio.h>
#include<stdlib.h>

int difference(int setA[], int setB[], int n, int m, int differ[]) {
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

}

void unionOfSet(int set1[], int set2[], int n, int m) {
    int setC[n + m]; // To store Union of set A and set B
    int i;
    for (i = 0; i < n; i++) {
        setC[i] = set1[i];
    }
    int temp = n;
    for (i = 0; i < m; i++) {
        if (present(set1, n, set2[i]) == 0) {
            setC[temp] = set2[i];
            temp++;
        }
    }

    printf("Symmetric Difference of Two Sets is:\n");
    for (i = 0; i < temp; i++) {
        printf("%d \t", setC[i]);
    }

}
int present(int arr[], int length, int item) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == item) {
            return 1;
        }
        
    }
    return 0;
}

int commonElements(int setA[], int setB[], int n, int m) {
    int count = 0;
    int i, j, data;
    for (i = 0; i < n; i++) {
        data = setA[i];
        for (j = 0; j < m; j++) {
            if (data == setB[j]) {
                count++;
            }
        }
    }
    return count;
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
    int common= commonElements(setA, setB, n, m);
    int AminusB[n-common];
    int BminusA[m-common];
    difference(setA, setB, n, m, AminusB);  //Method Call for Difference of set i.e A-B
    difference(setB, setA, m, n, BminusA);  //Method Call for Difference of set i.e B-A
    unionOfSet(AminusB, BminusA, n-common, m-common); //Method call for Union of differences of both sets
}