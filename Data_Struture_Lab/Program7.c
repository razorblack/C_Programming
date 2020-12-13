/* Program to implement Circular Queue as an array */

#include<stdio.h>
#include<stdlib.h>

#define MAX 10  //Circular Queue Size

int queue[MAX],FRONT, REAR;

//Method to check if circular queue is empty
int isEmpty() {
    if (FRONT == -1 || FRONT > REAR) {
        return 1;
    } else {
        return 0;
    }
}

//Method to check if circular queue is full
int isFull() {
    if (REAR == MAX-1) {
        return 1;
    } else {
        return 0;
    }
}

//Method to print the element at front
void peek() {
    if(isEmpty()== 1) {
        printf("Queue is empty \n");
    } else {
        printf("Element at front is: %d \n",queue[FRONT]);
    }
}

//Method to enter an element in circular queue
void enqueue(int item) {
    if (isFull() == 1) {
        printf("Queue is Full: Element can't be inserted \n");
    } else {
        REAR++;
        queue[REAR] = item;
        if (FRONT == -1) {
            FRONT++;
        }
    }
}

//Method to remove an element from circular queue
void dequeue() {
    if (isEmpty() == 1) {
        printf("Queue is Empty: Element can't be removed \n");
    } else {
        printf("Element removed is: %d \n",queue[FRONT]);
        FRONT++;
    }
}

//Method to display the elements of circular queue
void display() {
    if (isEmpty() == 1) {
        printf("Queue is Empty \n");
    } else {
        printf("Elements of Queue are: \n");
        for (int i = FRONT; i <= REAR; i++) {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

void main() {
    FRONT = -1;
    REAR = -1;
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