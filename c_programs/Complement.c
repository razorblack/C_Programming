#include<stdio.h>

void complement(int setA[], int setB[], int n, int m) {
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
    printf("Complement of set \n");
    for (i = 0; i < index; i++) {
        printf("%d ",differ[i]);
    }

}
void main() {
    int n;
    int i,j;
    printf("Enter no. of elements in a universal set \n");
    scanf("%d",&n);
    int universal[n];
    printf("Enter elements of Universal Set \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &universal[i]);
    }
    int m; 
    printf("Enter no of elements in a set \n");
    scanf("%d",&m);
    int set[m];
    printf("Enter elements of set \n");
    for (i = 0; i < m; i++) {
        scanf("%d", &set[i]);
    }
    complement(universal,set,n,m);
}