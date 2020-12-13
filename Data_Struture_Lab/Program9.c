#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;                
    struct Node* next;        
};

struct Node *rear = NULL;
struct Node *front = NULL;

void dequeue() 
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }
 
    struct Node *temp = front;
    printf("Element at front is %d\n", temp->data);
 
    front = front->next;
    if(front == NULL)
        rear = NULL;

    free(temp);
    printf("\n");
}
 
void enqueue(int item) // insertion at the end
{
    
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = item;
    node->next = NULL;

    printf("Inserting %d\n", item);
    
    //when queue is empty
    if (front == NULL && rear == NULL)
    {
        front = node;
        rear = node;
    }
    else
    {
        rear->next = node;
        rear = node;
    }
    printf("\n");
}
 
void peek()
{
    if (front != NULL)
        printf("Element at front is %d:",front->data);
    else
        printf("Queue is empty \n");
    
    printf("\n");
}

void display() {
    
    struct Node *temp = front;
    while(temp)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");

}
 
void main() {
    int choice=0;
    int item;
    while(1) {
        printf("Enter a choice: 1. Enqueue, 2. Dequeue, 3. Peek, 4. Display, 5. Exit \n");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter a number \n");
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Enter valid choice \n");
                break;
        }
    }
}