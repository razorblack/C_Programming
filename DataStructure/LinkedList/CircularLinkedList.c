/* Program to implement circular liked list */

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

void createList(int nodes) {
    int i;
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
            current->next->next = head;
        } else {
            current->next->next = NULL;
        }
        current = current->next;
    }

}

void insertAtFront(int item) {
    struct node *p = malloc(sizeof(struct node));
    p->data = item;
    struct node *temp = head; 

    if (head == NULL) {
        head = p;
        p->next = head;
    } else {
        while(temp->next != head) {
            temp = temp->next;
        }
        p->next = head;
        temp->next = p;
        head = p;
    }

}

void insertAtLast(int item) {
    struct node *p = malloc(sizeof(struct node));
    p->data = item;
    struct node *temp = head;
    if (head == NULL) {
        head = p;
        p->next = head;
    } else {
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = p;
        p->next = head;
    }
}

void insertAtMiddle(int item, int location) {
    struct node *add = malloc(sizeof(struct node));
    add->data = item;
    struct node *p = head;
    struct node *temp;
    if (head->next == head) {
        printf("Can't insert \n");
    } else {
        for (int i = 0; i < location; i++) {
            temp = p;
            p = p->next;
        }
        temp->next = add;
        add ->next = p;
    }

}

void deleteAtFront() {
    struct node *p = head;
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        while(p->next != head) {
            p = p->next;
        }
        p->next = head->next;
        free(head);
        head = p->next;
    }

}

void deleteAtLast() {
    struct node *p = head;
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct node *temp;
        while(p ->next != head) {
            temp = p;
            p = p->next;
        }
        temp->next = head;
        free(p);
    }

}

void deleteAtMiddle(int location) {
    struct node *p = head;
    struct node *temp;
    if (head->next == head) {
        printf("Can't delete \n");
    } else {
        for (int i = 0; i <= location; i++) {
            temp = p;
            p = p->next;
        }
        temp->next = p->next;
        free(p);
    }

}

void display() {
    struct node *p = head;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

void main() {
    int nodes;
    printf("Enter no of nodes in list \n");
    scanf("%d",&nodes);

    createList(nodes);
    int choice;
    int location, item;
    while(1) {
        printf("Enter choice: 1: Display; Insertion- 2: At front, 3: At back, 4: At middle; Deletion- 5: At front, 6: At back, 7: At middle; 8: Exit \n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter a number to insert \n");
                scanf("%d",&item);
                insertAtFront(item);
                break;
            case 3:
                printf("Enter a number to insert \n");
                scanf("%d",&item);
                insertAtLast(item);
                break;
            case 4:
                printf("Enter a number to insert \n");
                scanf("%d",&item);
                printf("Enter location of node to insert \n");
                scanf("%d",&location);
                insertAtMiddle(item, location);
                break;
            case 5:
                deleteAtFront();
                break;
            case 6:
                deleteAtLast();
                break;
            case 7:
                printf("Enter location of node to delete \n");
                scanf("%d",&location);
                deleteAtMiddle(location);
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Enter valid choice \n");
                break;
        }
    } 

}