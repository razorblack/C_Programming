// Program in C to create a Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node {
  int data;
  struct node *next;
  struct node *previous;
};

void printLinkedlist(struct node *p);
void printLinkedlistReversed(struct node *p);

void main() {
  int nodes;
  int i;
  printf("Enter number of nodes to create \n");
  scanf("%d", &nodes);

  struct node *head;
  struct node *current = malloc(sizeof(struct node));
  printf("Enter data of 1 node \n");
  scanf("%d",&current->data);
  current->next= NULL;
  current->previous= NULL;
  head = current;
  for (i = 0; i < nodes - 1; i++) {
    current->next= malloc(sizeof(struct node));
    printf("Enter data of %d node \n",(i+2));
    scanf("%d", &current->next->data);
    current->next->next= NULL;
    current->next->previous= current;
    current = current->next;
  }
  printLinkedlist(head);
  printLinkedlistReversed(current);
}

// print the doubly linked list in forward order
void printLinkedlist(struct node *p) {
  printf("\nDoubly List in Forward Order \n");
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
}
// print the doubly linked list in reversed order
void printLinkedlistReversed(struct node *p) {
  printf("\nDoubly List in Reversed Order \n");
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->previous;
  }
}