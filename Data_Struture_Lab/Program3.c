/* Program to implement linked list */

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
int nodes;

//Method to display Linked List
void display() {
    struct node *p = head;
    if (p == NULL) {
        printf("Linked List Empty \n");
    } else {
        while (p != NULL) {
            printf("%d ",p->data);
            p = p->next;
        }
        printf("\n");
    }
}

//Method to Insert element at front
void insertionAtFront(int item) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = item;
    temp->next = head;
    head = temp;
    nodes++;

}

// Method to insert element at end
void insertionAtEnd(int item) {
    struct node *p;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = item;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
    nodes++;

    
}

//Method to insert element at middle
void insertionAtMiddle(int item, int location) {
    struct node *p = malloc(sizeof(struct node));
    p->data = item;
    struct node *temp = head;
    if (temp == NULL) {
        printf("Element can't be inserted \n");
    } else {
        for (int i = 1; i < location; i++) {
            temp = temp->next;
            if (temp == NULL) {
                printf("Element can't be inserted \n");
                return;
            }
            p->next = temp->next;
            temp->next = p;
            nodes++;
        }


    }
}

//Method to deleter element at front
void deletionAtFront() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("Linked List empty, can't delete \n");
    } else {
        head = head->next;
        free(temp);
        nodes--;
    }
}

//Method to delete element at end
void deletionAtEnd() {
    struct node *temp = head;
    struct node *temp1 = head;
    if (head == NULL) {
        printf("Linked List empty, can't delete \n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        while (temp->next != NULL) {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = NULL; 
        free(temp);
        nodes--;
    }
    
}

//Method to delete element at middle
void deletionAtMiddle(int location) {
    struct node *temp = head;
    struct node *temp1;
    if (temp == NULL) {
        printf("Linked List empty, can't delete \n");
    } else {
        for (int i = 1; i <= location; i++) {
            temp1 = temp;
            temp = temp->next;

            if (temp == NULL) {
                printf("Element can't be deleted \n");
                return;
            }

        }
        temp1->next = temp->next;
        free(temp);
        nodes--;
    }
    
}

void main() {
    
    int data;
    int choice;
    printf("Enter no. of nodes \n");
    scanf("%d",&nodes);

    struct node *current = malloc(sizeof(struct node));
    printf("Enter data of 1 node \n");
    scanf("%d",&current->data);
    current->next = NULL;
    head = current;

    for (int i = 0; i < nodes - 1; i++) {
        current->next = malloc(sizeof(struct node));
        printf("Enter data of %d node \n", (i+2));
        scanf("%d",&current->next->data);
        current->next->next = NULL;
        current = current->next;
    }
    int item;
    int location;
    while(1) {
        printf("Enter choice: 1: Display; Insertion: 2-At Front, 3-At end, 4-At middle; Deletion: 5-At front, 6-At end, 7-At middle; 8:Exit \n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter an element to enter \n");
                scanf("%d",&item);
                insertionAtFront(item);
                break;
            case 3:
                printf("Enter an element to enter \n");
                scanf("%d",&item);
                insertionAtEnd(item);
                break;
            case 4:
                printf("Enter an element to enter \n");
                scanf("%d",&item);
                printf("Enter a location between 1 and %d to insert \n",nodes);
                scanf("%d",&location);
                insertionAtMiddle(item, location);
                break;
            case 5:
                deletionAtFront();
                break;
            case 6:
                deletionAtEnd();
                break;
            case 7:
                printf("Enter a location between 1 and %d to delete \n",nodes);
                scanf("%d",&location);
                deletionAtMiddle(location);
                break;
            case 8:
                exit(0);
            default:
                printf("Enter valid choice \n");
                break;
        }
    }
}