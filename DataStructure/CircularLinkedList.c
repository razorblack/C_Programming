// Program in C to create a Circular Linked List

#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node {
  int data;
  struct node *next;
};

void printLinkedlist(struct node *p);

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
  head = current;
  for (i = 0; i < nodes - 1; i++) {
    current->next= malloc(sizeof(struct node));
    printf("Enter data of %d node \n",(i+2));
    scanf("%d", &current->next->data);
    if (i == nodes - 2) {
        current->next->next= head;
    } else {
        current->next->next= NULL;
    }
    current = current->next;
  }
  printLinkedlist(head);
}

// print the linked list value
void printLinkedlist(struct node *p) {
  struct node *start = p;
  do {
    printf("%d ", p->data);
    p = p->next;
  } while (p != start);
}