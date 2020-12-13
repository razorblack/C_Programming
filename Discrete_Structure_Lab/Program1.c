#include<stdio.h>

void unionOfSet(int set1[], int set2[],int n, int m);
int present(int arr[], int length, int item);

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
    unionOfSet(setA, setB, n, m);  //Method Call for Union of set
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

    printf("Element of Union of first set and second set \n");
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
