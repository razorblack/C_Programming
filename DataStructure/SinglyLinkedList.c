// Program in C to create a Linked List

#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node {
  int data;
  struct node *next;
};

void printLinkedlist(struct node *p);

void main() {
  int n, i;
  int dataNode;
  // Initialize nodes
  struct node *head=malloc(sizeof(struct node));
  printf("Enter no. of nodes\n");
  scanf("%d",&n);
  struct node *one = malloc(sizeof(struct node));
  printf("Enter data of 1 node \n");
  scanf("%d",&dataNode);
  head->data=dataNode;
  head->next=NULL;

  one = head;
  struct node *p;

  for (i = 1; i <= n-1; i++) {
    p = malloc(sizeof(struct node));
    printf("Enter data of %d node \n",(i+1));
    scanf("%d",&dataNode);
    one->next=malloc(sizeof(struct node));
    p->data=dataNode;
    p->next=NULL;

    one->next=p;
    one = one->next;

  }
  head = one;
  printLinkedlist(head);
}

// print the linked list value
void printLinkedlist(struct node *p) {
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
}