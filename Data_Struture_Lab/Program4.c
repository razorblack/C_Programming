// Program in C to reverse a singly linked list

#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node {
  int data;
  struct node *next;
};

void printLinkedlist(struct node *p);

//Method to reverse linked list
void reverse(struct node *head) {
  struct node *prev = NULL;
  struct node *current = head;
  struct node *next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
  printLinkedlist(head);
}

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
    current->next->next= NULL;
    current = current->next;
  }
  printf("Linked List is: \t");
  printLinkedlist(head);
  printf("Reversed Linked List: \t");
  reverse(head);
  
}

// print the linked list
void printLinkedlist(struct node *p) {
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}