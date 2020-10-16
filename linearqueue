#include<stdio.h>
#define maxsize 5
void enqueue(int *queue,int *front, int *rear)
    {
    int ele;
    if(*rear>=maxsize-1)
        {
        printf("queue overflow\n");
        return;
        }
    if(*front==-1)
        {
        (*front)++;
        }
    (*rear)++;
    printf("\nEnter the element:\n");
    scanf("%d",&ele);
    *(queue+*rear)=ele;
    }

void display(int *queue,int front,int rear)
    {
    if(front==-1&&rear==-1)
        printf("\nQueue is empty");
    else
        {
        printf("\nElements in Queue are:\n");
        for(int i=front;i<=rear;i++)
            {
            printf("%d ",*(queue+i));
            }
        }
    }

void dequeue(int *queue,int *front, int *rear)
    {
    int ele;
    if(*front==-1&&*rear==-1)
        {
        printf("\nQueue underflow.");
        return;
        }
    else if(*front==*rear)
        {
        ele=*(queue+*front);
        *front=-1;
        *rear=-1;
        }
    else
        {
        ele=*(queue+*front);
        (*front)++;
        }
    printf("\nDeleted Element= %d",ele);
    }

void main()
{
int front1=-1,rear1=-1;
int queue1[maxsize];
int choice;
    printf("\n[1] Enqueue");
    printf("\n[2] Dequque");
    printf("\n[3] Display");
    printf("\n[4] Exit");

do
    {
    printf("\nEnter your choice= ");
    scanf("%d",&choice);

    switch(choice)
        {
        case 1: enqueue(queue1,&front1,&rear1);
            break;
        case 2: dequeue(queue1,&front1,&rear1);
            break;
        case 3: display(queue1,front1,rear1);
        }
    }while(choice!=4);

}
