#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct stack{
int data;
struct node *next;
};

struct stack *top=NULL;

struct stack *push(struct stack *,int );
struct stack *display(struct stack * );
struct stack *pop(struct stack * );
int peek(struct stack *);

int main(){
int val,option;
do{printf("\nMENU");
 printf("\n 1.PUSH");
printf("\n 2.POP");
printf("\n 3.PEEK");
printf("\n 4.DISPLAY");
printf("\n 5.EXIT");
printf("\n Enter your option");
scanf("%d",& option);
switch(option){
case 1:
  printf("Enter the value to be pushed on stack");
  scanf("%d",&val);
  top=push(top,val);
  break;
case 2:
  top=pop(top);
  break;
case 3:
  val=peek(top);
  if(val!=-1)
    printf("\n The value of the top element is %d ",val);
  else
    printf("\n Stack is EMPTY");
  break;
case 4:
  top=display(top);
  break;
}
}while(option!=5);
return 0;
}

struct stack *push (struct stack *top,int val){
struct stack *p;
p=(struct stack *)malloc (sizeof(struct stack));
p->data=val;
if(top==0){
  p->next=0;
  top=p;
}
else {
  p->next=top;
  top=p;
}
return top;
}

struct stack *display (struct stack *top){
struct stack *p;
p=top;
if(top==NULL)
  printf("\n Stack is Empty");
else {
  while(p!=NULL)
  {
    printf("\n %d",p->data);
    p=p->next;
  }
}
return top;
}

struct stack *pop(struct stack *top){
struct stack *p;
p=top;
if(top==0)
  printf("Stack Underflow");
else {
  top=top->next;
  printf("\n The value of the item deleted is %d",p->data);
  free(p);
}
return top;
}

int peek (struct stack *top ){
if(top==NULL)
  return -1;
else
  return top->data;
}
