#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void concatenate(struct node *first, struct node *second) {
    while(first->next != NULL) {
        first= first->next;
    }
    first->next = second;
}
void print(struct node *p) {
    while (p != NULL) {
        printf("%d ",p->data);
        p = p->next;
    }
}

void main() {
    int nodes1;
    int nodes2;
    int i;
    printf("Enter number of nodes in first list\n");
    scanf("%d", &nodes1);

    struct node *head1;
    struct node *head2;
    struct node *first = malloc(sizeof(struct node));
    printf("Enter data of 1 node of first list \n");
    scanf("%d",&first->data);
    first->next= NULL;
    head1 = first;
    for (i = 0; i < nodes1 - 1; i++) {
        first->next= malloc(sizeof(struct node));
        printf("Enter data of %d node of first list \n",(i+2));
        scanf("%d", &first->next->data);
        first->next->next= NULL;
        first = first->next;
    }
    printf("Enter number of nodes in second list\n");
    scanf("%d", &nodes2);
    struct node *second = malloc(sizeof(struct node));
    printf("Enter data of 1 node of second list \n");
    scanf("%d",&second->data);
    second->next= NULL;
    head2 = first;
    for (i = 0; i < nodes2 - 1; i++) {
        second->next= malloc(sizeof(struct node));
        printf("Enter data of %d node of second list \n",(i+2));
        scanf("%d", &second->next->data);
        second->next->next= NULL;
        second = second->next;
    }
    concatenate(first,second);
    printf("Linked List after concatenation \n");
    print(head1);
}
