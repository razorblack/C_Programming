#include<stdio.h>
#include<stdlib.h>

struct node {
    int coefficient;
    int exponent;
    struct node *next;
};

struct node *poly1;
struct node *poly2;
struct node *addition;

void printPolynomial(struct node *p) {
    while (p != NULL) {
        if (p->exponent != 0) {
            if (p->coefficient != 0) {
                printf("%dx^%d + ",p->coefficient,p->exponent);
                p = p->next;
            }
        } else {
            if (p->coefficient != 0) {
                printf("%d",p->coefficient);
                p = p->next;
            }
        }
    }
    printf("\n");
}

void polynomialCreation(int expo, int choice) {

    struct node *current = (struct node *)malloc(sizeof(struct node));
    if (expo <= 0) {
        printf("Polynomial can't be created \n");
        exit(0);
    }
    current->exponent = expo;
    printf("Enter coefficient of x^%d \n",expo);
    scanf("%d",&current->coefficient);
    if (choice == 1) {
        poly1 = current;
    } else {
        poly2 = current;
    }
    for (int i = expo-1; i >= 0; i--) {
        current->next = malloc(sizeof(struct node));
        printf("Enter coefficient of x^%d \n",i);
        scanf("%d",&current->next->coefficient);
        current->next->exponent = i;
        current = current->next;
    }

}

void addPolynomial(int max) {
    struct node *add = malloc(sizeof(struct node));
    addition = add;
    for (int i = max; i >= 0; i--) {
        if (poly1->exponent == poly2->exponent) {
            add->exponent = poly1->exponent;
            add->coefficient = poly1->coefficient + poly2->coefficient;
            poly1 = poly1->next;
            poly2 = poly2->next;
           
        } else if (poly1->exponent > poly2->exponent) {
            add->exponent = poly1->exponent;
            add->coefficient = poly1->coefficient;
            poly1 = poly1->next;
            

        } else {
            add->exponent = poly2->exponent;
            add->coefficient = poly2->coefficient;
            poly2 = poly2->next;
            
        }
        add->next = malloc(sizeof(struct node));
        add = add->next;
    }

     
}

void main() {
    
    int expo1, expo2;
    printf("Enter maximum exponent of first polynomial \n");
    scanf("%d",&expo1);
    printf("Enter maximum exponent of second polynomial \n");
    scanf("%d",&expo2);

    int max;
    if (expo1 > expo2) {
        max = expo1;
    } else {
        max = expo2;
    }

    printf("For First Polynomial \n");
    polynomialCreation(expo1, 1);

    printf("For Second Polynomial \n");
    polynomialCreation(expo2, 2);
    
    printf("First polynomial is: \n");
    printPolynomial(poly1);

    printf("Second polynomial is: \n");
    printPolynomial(poly2);

    printf("Addition of polynomial first and polynomial second \n");
    addPolynomial(max);
    
    printPolynomial(addition);
}