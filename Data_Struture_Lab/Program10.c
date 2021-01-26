#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;                
    struct Node* next;        
};

struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty() {
  if (front == NULL){
      return 1;
  } else {
      return 0;
  }
}

void peek()
{
    if (front != NULL) {
        printf("Element at front is %d:\n",front->data);
    } else {
        printf("Queue is empty \n");
    }
}

void enqueue(int item) // insertion in circular queue
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = item;

    printf("Inserting %d\n", item);
    //when queue is empty
    if (isEmpty() == 1)
    {
        front = node;
    } else {
        rear->next = node;
    }

    rear = node;
    rear->next = front;
    printf("Element Inserted\n");
}
 
void dequeue() // deletion from circular queue
{
    int item;
    if (isEmpty() == 1)
    {
        printf("Queue is empty\n");
        return;
    } else {
        if (front == rear) {
            item = front->data;
            printf("Element removed: %d \n",item);
            free(front);
            front = NULL;
            rear = NULL;
        } else {
            struct Node *q;
            q = front;
            item = q->data;

            front = front->next;
            rear->next = front;

            free(q);
            printf("Element removed: %d \n",item);
        }
    }
}

void display() {
    if (isEmpty() == 1) {
        printf("Queue is empty\n");
    } else {
        struct Node *temp = front;
        do
        {
            printf("%d ",temp->data);
            temp = temp->next;
        } while(temp != front);
        printf("\n");
    }
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