#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head;
struct node* temp;

void display()
{
    struct node *current;
    current = head;
    if(current!= NULL)
    {
        do
        {
            printf("%d ",current->data);
            current = current->next;
        }
        while (current!= NULL);
        printf("\n");
    }
    else
    {
        printf("The Stack is empty\n");
    }
}

void push(int data)
{
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Node can't be created\n");
    } else {
         temp->data = data;
         temp->next = head;
         head = temp;
    }
}

void pop()
{
    if (head == NULL) {
        printf("Stack is empty\n");
    } else {
        struct node* temp = head;
        int element = head->data;
        head = head->next;
        free(temp);
    }
}

void peek() {
    if (head == NULL) {
        printf("Stack empty\n");
    } else {
        printf("Element at TOP is %d \n",head->data);
    }
}

void main() {
    head = NULL;
    int choice, item;
    while(1)
    {
        printf("Enter Choice--1: Display, 2: PUSH, 3:POP, 4:PEEK, 5: Exit \n");
        scanf("%d",&choice);
 
        switch(choice)
        {
            case 1:
                display();
                break;
            case 2:
                printf("Enter element to insert :");
                scanf("%d",&item);
                push(item);
                break;
            case 3:
                pop();
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(0);
            default:
            printf("\nPlease enter valid choice.");
            break;
        }
    }
}

