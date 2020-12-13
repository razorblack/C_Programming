// Program in C to create a Linked List Inversion

#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node {
  int data;
  struct node *next;
};

void printLinkedlist(struct node *p);
void reverseLinkedList(struct node *head);

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
  printLinkedlist(head);
  reverseLinkedList(head);
}

// print the linked list value
void printLinkedlist(struct node *p) {
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
}


//reverse of linked list
void reverseLinkedList(struct node *head) {
    printf("\nList in reversed order \n");
    struct node *reverse;
    struct node *previous = head;
    struct node *newNext = head->next;
    previous->next=NULL;
    newNext->next= previous;

    while (newNext != NULL) {
        
        previous = newNext;
        newNext = newNext->next;
        newNext->next=previous;
    }
    reverse =newNext;


    printf("List in reversed order \n");
    printLinkedlist(reverse);
}