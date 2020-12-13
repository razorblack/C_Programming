// Program in C to create a Linked List

#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node {
  int data;
  struct node *next;
};

void printLinkedlist(struct node *p, struct node *start);

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
  two->next = three;
  three->next = one;

  head = one;
  printLinkedlist(head, one);
}

// print the linked list value
void printLinkedlist(struct node *p, struct node *start) {
  do {
    printf("%d ", p->data);
    p = p->next;
  } while (p->data != start->data);
}