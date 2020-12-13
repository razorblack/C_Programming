#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *previous;
    struct node *next;
};

typedef struct node st;


int front = -1;
int rear = -1;
int n;
st *head;

void insertAtFront(st *list, st *p) {
    p->next = list;
    list->previous= p;
    head = p;
    rear++;

}

void insertAtRear(st *list, st *p) {
    while(list->next != NULL) {
        list=list->next;
    }
    list->next= p;
    p->previous = list;
    rear++;

}
void print(st *p) {
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    
    
}

void main() {
    printf("Enter the no. of elements in queue \n");
    scanf("%d", &n);
    st *current =malloc(sizeof(st));
    printf("Enter data of element \n");
    int data;
    int choice;
    scanf("%d", &data);
    current->data= data;
    current->next=NULL;
    current->previous= NULL;
    front = 1;
    rear = 1;
    head= current;
    for (int i = 1; i <= n-1; i++) {
        st *temp = malloc(sizeof(st));
        printf("Enter data of element \n");
        scanf("%d", &data);
        temp->data=data;
        temp->next=NULL;
        temp->previous=NULL;
        
        do
        {
            printf("Enter choice 1- Insert at front 2- Insert at rear \n");
            scanf("%d",&choice);
            if(choice == 1) {
                insertAtFront(head,temp);

            } else if (choice == 2) {
                insertAtRear(head,temp);

            } else {
                printf("Enter correct choice\n");
            }
        } while (choice!= 1 && choice != 2);
        
    }
    print(head);

}


