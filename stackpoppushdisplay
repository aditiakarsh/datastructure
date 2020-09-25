#include <stdio.h>
#define size 3
int top=-1,choice,num,stack[size];
void push();
void pop();
void display(int []);
int main()
{  
   
    do
    {
    printf("Enter your choice\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
                push();
                break;
            
            case 2:
                pop();
                break;
            
            case 3:
                display(stack);
                break;
            
            case 4:
                printf("EXIT");
                break;
            
            default:
            
                printf ("\nINVALID OPTION\n");
    }  
    }
    while(choice!=4);
    return 0;
}


void push()
{
    if (top>=size-1)
    {
        printf("Stack overflow");
    }
    else
    {   printf(" Enter a number to be pushed:");
        scanf("%d",&num);
        top++;
        stack[top]=num;
    }
}

void pop()
{
    
    if(top<=-1)
    {
        printf(" Stack is under flow\n");
    }
    else
    {
        printf("The popped elements is %d\n",stack[top]);
        top--;
    }
     
     
}

void display(int stack[])
{
    printf("The stack elemements\n");
    for(int i=top;i>=0;i--)
        printf("%d\t",stack[i]);
    
}
