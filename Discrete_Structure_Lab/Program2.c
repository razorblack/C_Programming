#include<stdio.h>

int present(int arr[], int length, int item);
void intersectionOfSet(int set1[], int set2[],int n, int m);

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
    intersectionOfSet(setA, setB, n, m);  //Method Call for Intersection of set
}

void intersectionOfSet(int set1[], int set2[], int n, int m) {
    int min; 
    if (n >= m) {
        min = n;
    } else {
        min = m;
    }
    int setC[min]; // To store intersection of set A and set B
    int i, j;
    int temp = 0; 
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (set1[i] == set2[j]) {
                if (present(setC, min, set1[i]) == 0) {
                    setC[temp] = set1[i];
                    temp++;
                }
            }
        }
    }

    printf("Element of Intersection of first set and second set \n");
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
