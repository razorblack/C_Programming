/*Program to implement stack using array */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10    //Size of the stack
 
int STACK[MAX],TOP;

//Method to display stack
void display(int stack[])
{
    int i=0;
    if(TOP==-1)
    {
        printf("Stack is Empty .\n");
        
        return;
    }
 
    printf("%d = TOP ",stack[TOP]);
    for(i=TOP-1;i >=0;i--)
    {
        printf("\n%d",stack[i]);
    }
    printf("\n");
}

//Method to push element in stack
void push(int stack[],int item)
{
    if(TOP==MAX-1)
    {
        printf("\nSTACK is full can't add item \n");
        return;
    }
    TOP++;
    stack[TOP]=item;
}

//Method to pop out element at top
void pop(int stack[])
{
    int topItem;
    if(TOP==-1)
    {
        printf("STACK is empty.\n");
        return;
    }
 
    topItem=stack[TOP];
    TOP--;
    printf("%d Deleted successfully\n",topItem);
    return;
}

//Method to see the element at top
void peek(int stack[]) {
    if (TOP==-1) {
        printf("Stack is empty \n");
    } else {
        printf("%d",stack[TOP]);
    }
    printf("\n");

}

void main()
{
    int item=0;
    int choice=0;
    TOP=-1;
 
    while(1)
    {
        printf("Enter Choice--1: Display, 2: PUSH, 3:POP, 4:PEEK, 5: Exit \n");
        scanf("%d",&choice);
 
        switch(choice)
        {
            case 1:
                display(STACK);
                break;
            case 2:
                printf("Enter element to insert :");
                scanf("%d",&item);
                push(STACK,item);
                break;
            case 3:
                pop(STACK);
                break;
            case 4:
                peek(STACK);
                break;
            case 5:
                exit(0);
            default:
            printf("\nPlease enter valid choice.");
            break;
        }
    }
}
 
