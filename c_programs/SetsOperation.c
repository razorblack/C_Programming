#include<stdio.h>

int present(int arr[], int length, int item) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == item) {
            return 1;
        }
        
    }
    return 0;
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

    
    for (i = 0; i < temp; i++) {
        printf("%d \t", setC[i]);
    }

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

void selectedChoice(int choice) {
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

    switch(choice) {
        case 1:
            printf("Element of Union of first set and second set \n");
            unionOfSet(setA, setB, n, m);
            break;
        case 2:
            intersectionOfSet(setA, setB, n, m);
            break;
        case 3:
            difference(setA, setB, n, m);
            break;
    }

}

void main() {
    
    int choice;
    printf("Enter choice: 1-Union, 2-Intersection, 3-Difference\n");
    scanf("%d",&choice);

    if (choice >=1 && choice <= 3) {
        selectedChoice(choice);
    } else {
        printf("Enter valid choice\n");
    }
    
}



