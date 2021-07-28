#include<stdio.h>
#include<stdlib.h>
 
int mutex = 1, full = 0, x = 0;
int empty;

int wait(int s)
{
    return (--s);
}
 
int signal(int s)
{
    return(++s);
}
 
void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("Producer produces the item %d \n", x);
    mutex=signal(mutex);
}
 
void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("Consumer consumes item %d \n", x);
    x--;
    mutex=signal(mutex);
}
 
void main()
{
    int n;
    printf("Enter Buffer size: \n");
    scanf("%d", &empty);
    
    void producer();
    void consumer();
    int wait(int);
    int signal(int);

    while(1)
    {
        printf("1.Producer \t 2.Consumer \t 3.Exit \n");
        printf("Enter your choice: \n");
        scanf("%d", &n);
        switch(n)
        {
            case 1: if ((mutex == 1) && (empty != 0))
                        producer();
                    else
                        printf("Buffer is full! \n");
                    break;
            case 2: if ((mutex == 1) && (full != 0))
                        consumer();
                    else
                        printf("Buffer is empty! \n");
                    break;
            case 3:
                printf("Program exit successfully \n");
                exit(0);
        }
    }
}
