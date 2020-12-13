// Program in C to create a Doubly Circular Linked List

#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node {
  int data;
  struct node *previous;
  struct node *next;
};

void printLinkedlist(struct node *p, struct node *start);
void printLinkedlistReversed(struct node *p, struct node *start); 

void main() {
  // Initialize nodes
  struct node *head;
  struct node *one = NULL;
  struct node *two = NULL;
  struct node *three = NULL;

// Allocating Memory
  one = malloc(sizeof(struct node));
  two = malloc(sizeof(struct node));
  three = malloc(sizeof(struct node));

  // Assign data values
  one->data = 1;
  two->data = 2;
  three->data = 3;
 
 // Connecting Nodes
  one->next = two;
  one->previous= three;

  two->next = three;
  two->previous= one;

  three->next = one;
  three->previous= two;

  head = one;
  printLinkedlist(head, head);  //Forward Circular Order
  printLinkedlistReversed(head, head); //Backward order

}

// print the linked list value in forward order
void printLinkedlist(struct node *p, struct node *start) {
  do {
    printf("%d ", p->data);
    p = p->next;
  } while (p->data != start->data);
}

// print the linked list value in backward order
void printLinkedlistReversed(struct node *p, struct node *start) {
  do {
    p = p->previous;
    printf("%d ", p->data);
  } while (p != start);
}