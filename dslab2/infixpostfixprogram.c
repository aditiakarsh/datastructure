#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 20

char stack[SIZE];
int top = -1;

void push(char ele)
{
	if(top >= SIZE)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = ele;
	}
}
char pop()
{
	char ele ;
	if(top==-1)
	{
		printf("stack under flow: invalid infix expression");
		getchar();
		exit(1);
	}
	else
	{
		ele = stack[top];
		top = top-1;
		return(ele);
	}
}
int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
        return 0;
	}
}
int higher(char symbol)
{
    switch(symbol)
    {
        case '^':
            return(3);
            break;
        case '*':
        case '/':
            return(2);
            break;
        case '+':
        case '-':
            return(1);
            break;
        default:
            return(0);
            break;
    }
}
void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
	int i=0, j=0;
	char ele;
	char x;
	push('(');
	strcat(infix_exp,")");
	ele=infix_exp[i];
	while(ele != '\0')
	{
		if(ele == '(')
		{
			push(ele);
		}
		else if(ele=='A' || ele=='B' || ele=='C' || ele=='D' || ele=='E' || ele=='F' || ele=='G' || ele=='H' || ele=='I' || ele=='J' || ele=='K' || ele=='L' || ele=='M' || ele=='N' || ele=='O' || ele=='P' || ele=='Q' || ele=='R' || ele=='S' || ele=='T' || ele=='U' || ele=='V' || ele=='W' || ele=='X' || ele=='Y' || ele=='Z' || ele=='0' || ele=='1' || ele=='2' || ele=='3' || ele=='4' || ele=='5' || ele=='6' || ele=='7' || ele=='8' || ele=='9')
		{
			postfix_exp[j] = ele;
			j++;
		}
		else if(is_operator(ele) == 1)
		{
			x=pop();
			while(is_operator(x) == 1 && higher(x)>= higher(ele))
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
			push(x);
			push(ele);
		}
		else if(ele == ')')
		{
			x = pop();
			while(x != '(')
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
			printf("\nInvalid infix Expression.\n");
			getchar();
			exit(1);
		}
		i++;
        ele = infix_exp[i];
	}
	postfix_exp[j] = '\0';
}
int main()
{
	char infix[SIZE], postfix[SIZE];
	printf("\nEnter Infix expression : ");
	gets(infix);
	InfixToPostfix(infix,postfix);
	printf("Postfix Expression is: ");
	puts(postfix);
	return 0;
}
