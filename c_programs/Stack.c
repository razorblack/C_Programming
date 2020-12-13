#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct stack {
    int item[MAX];
    int top;
};
typedef struct stack st;
int count = 0;




void createEmptyStack(st *s) {
    s->top=-1;
}
int isEmpty(st *s) {
    if (s->top== -1) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(st *s) {
    if (s->top==MAX) {
        return 1;
    } else {
        return 0;
    }
}

void peek(st *s) {
    if (isEmpty(s)) {
        printf("Stack empty");
    } else {
        int item = s->item[s->top];
        printf("%d",item);
    }

}

void push(st *s, int item) {
    if (isFull(s)) {
        printf("Stack full");
    } else {
        s->top= s->top +1;
        s->item[s->top]=item;
        count++;
    }
}

int pop(st *s) {
    if(isEmpty(s)) {
        printf("Stack empty");
        return;
    } else {
        int item = s->item[s->top];
        s->top= s->top -1;
        count--;
        return item;
    }
}

void display(st *s) {
    int i;
    if (isEmpty(s)) {
        printf("Stack empty");
    } else {
        for (i = count-1; i >= 0; i--) {
            printf("%d",s->item[i]);
            printf("\n");
        }
    }
}
void main() {
    st *s = malloc(sizeof(st));
    createEmptyStack(s);

    push(s, 22);
    push(s, 2);
    push(s, 5);

    display(s);

    pop(s);

    printf("After pop\n");
    display(s);
}

