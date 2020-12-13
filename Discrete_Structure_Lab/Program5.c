#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main() {
    int sizeOfSet;
    int sizeOfPowerset;
    printf("Enter size of the set \n");
    scanf("%d", &sizeOfSet);

    int set[sizeOfSet];
    sizeOfPowerset = pow(2, sizeOfSet);
    int powerset[sizeOfPowerset];

    printf("Enter a set of size %d:\n",sizeOfSet);
    for(int i = 0; i < sizeOfSet; i++) {
        scanf("%d",&set[i]);
    }

    //Logic for power set operation on set
    for(int i = 0; i < sizeOfPowerset; i++) {
        if (i == 0) {
            powerset[i] = -1;
        } else {
            int result = 0;
            for(int j = 0; j < sizeOfSet; j++) {
                if (i & (1<< j)) {
                    result = result * 10 + set[j];
                }
                powerset[i] = result;
            }
        }
        
    }

    printf("Power Set of the entered set is: \n");
    for(int i = 0; i < sizeOfPowerset; i++) {
        printf("%d \t",powerset[i]);
    }
}