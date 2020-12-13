#include<stdio.h>
#include<stdlib.h>

struct node {
    int coefficient;
    int exponent;
    struct node *next;
};

void printPolynomial(struct node *p) {
    while (p != NULL) {
        if (p->exponent != 0) {
            if (p->coefficient != 0) {
                printf("%dx^%d +",p->coefficient,p->exponent);
                p = p->next;
            }
        } else {
            if (p->coefficient != 0) {
                printf("%d",p->coefficient);
                p = p->next;
            }
        }
    }
}

void main() {
    int expo;
    printf("Enter maximum exponent of polynomial \n");
    scanf("%d",&expo);
    struct node *head;
    struct node *current = malloc(sizeof(struct node));
    
    if (expo <= 0) {
        printf("Polynomial can't be created \n");
        exit(0);
    }
    current->exponent = expo;
    printf("Enter coefficient of x^%d \n",expo);
    scanf("%d",&current->coefficient);
    head = current;

    for (int i = expo-1; i >= 0; i--) {
        current->next = malloc(sizeof(struct node));
        printf("Enter coefficient of x^%d \n",i);
        scanf("%d",&current->next->coefficient);
        current->next->exponent = i;
        current = current->next;
    }
    printf("Entered polynomial is: \n");
    printPolynomial(head);

}