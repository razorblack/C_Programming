#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void andLogic(int a, int b) {
    //Logic for finding Boolean AND
    int result;
    result = a & b;
    printf("%d & %d is : %d",a,b,result);
    printf("\n");

}

void orLogic(int a, int b) {
     //Logic for finding Boolean OR
    int result;
    result = a | b;
    printf("%d | %d is : %d",a,b,result);
    printf("\n");


}

void notLogic(int a) {
     
     //Logic for finding Boolean NOT
    int result;
    result = !a;
    printf("Negation of %d is : %d",a,result);
    printf("\n");


}

void nandLogic(int a, int b) {
    int result;
    result = !(a & b);
    printf("Negation of %d & %d is : %d",a,b,result);
    printf("\n");

}

void norLogic(int a, int b) {
    int result;
    result = !(a | b);
    printf("Negation of %d | %d is : %d",a,b,result);
    printf("\n");

}

void xorLogic(int a, int b) {
    int result;
    result = (a | b) & (!a | !b);
    printf("%d XOR %d is : %d",a,b,result);
    printf("\n");
}


void main() {
    int choice;
    int a, b;

    printf("Choices: 1-AND, 2-OR, 3-NOT, 4-NAND, 5-NOR, 6-XOR\n");
    printf("Enter choice\n");
    scanf("%d",&choice);

    switch(choice) {
        case 1: 
                printf("Enter two truth value in 0/1\n");
                scanf("%d %d", &a, &b);
                andLogic(a, b);
                break;
        case 2: 
                printf("Enter two truth value in 0/1 \n");
                scanf("%d %d", &a, &b);
                orLogic(a, b);
                break;
        case 3: 
                printf("Enter a truth value in 0/1\n");
                scanf("%d",&a);
                notLogic(a);
                break;
        case 4: 
                printf("Enter two truth value in 0/1\n");
                scanf("%d %d", &a, &b);
                nandLogic(a, b);
                break;
        case 5: 
                printf("Enter two truth value in 0/1 \n");
                scanf("%d %d", &a, &b);
                norLogic(a, b);
                break;
        case 6: 
                printf("Enter two truth value in 0/1\n");
                scanf("%d %d", &a, &b);
                xorLogic(a, b);
                break;
        default: printf("Enter valid choice\n");
                 break;
    }
}