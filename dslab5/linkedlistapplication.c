#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int sem;
	char name[30];
	char ID[30];
	struct node *next;
}node;

node* removed = NULL;
node* start = NULL;
node* end = NULL;


void insert()
{
	fflush(stdin);
	printf("\nEnter the student ID :\n");
	char I[30];
	scanf("%s", I);
	printf("Enter the student name:\n");
	char n[30];
	scanf("%s", n);
	printf("Enter the semester the student is in: ");
	int s =0;
	scanf("%d", &s);
	fflush(stdin);
	node* temp = (node*)malloc(sizeof(node));
	memcpy(temp->name, n, 20);
	memcpy(temp->ID, I, 20);
	temp->sem = s;
	temp->next = start;
	start = temp;
	node* forEnd;
			forEnd = start;
			while(forEnd != NULL && forEnd->next != NULL)
			{
				forEnd = forEnd->next;
				
			}
			end = forEnd;
}
void insertAtI(int i)
{
	node* current = (node*)malloc(sizeof(node));
	node* previous = (node*)malloc(sizeof(node));
	current = start;
	previous = start;
	int j = 0;
	while(current != NULL)
	{
		if(j == i)
		{
			fflush(stdin);
			printf("\nEnter the student ID :\n");
			char I[30];
			scanf("%s", I);
			printf("Enter the student name:\n");
			char n[30];
			scanf("%s", n);
			printf("Enter the semester the student is in:\n");
			int s =0;
			scanf("%d", &s);
			fflush(stdin);
			node* temp = (node*)malloc(sizeof(node));
			memcpy(temp->name, n, 20);
			memcpy(temp->ID, I, 20);
			temp->sem = s;
			temp->next = current->next;
			if(i != 0)
				previous->next = temp;
			else
				start = temp;
			node* forEnd;
			forEnd = start;
			while(forEnd != NULL && forEnd->next != NULL)
			{
				forEnd = forEnd->next;
			}
			end = forEnd;
			return;
		}
		previous = current;
		current = current->next;
		j++;
	}
	if(start == NULL && i == 0)
	{	
			fflush(stdin);
			printf("\nEnter the student ID :\n");
			char I[30];
			scanf("%s", I);
			printf("Enter the student name:\n");
			char n[30];
			scanf("%s", n);
			printf("Enter the semester the student is in:\n");
			int s =0;
			scanf("%d", &s);
			fflush(stdin);
			node* temp = (node*)malloc(sizeof(node));
			memcpy(temp->name, n, 20);
			memcpy(temp->ID, I, 20);
			temp->sem = s;
			temp->next = NULL;
			start = temp;
			end = temp;
			node* forEnd;
			forEnd = start;
			while(forEnd != NULL && forEnd->next != NULL)
			{
				forEnd = forEnd->next;
			}
			end = forEnd;
	}
	else
		printf("\n\t\tIndex is out of bounds!!!\n");
}
void display()
{
	node* temp = (node*)malloc(sizeof(node));
	temp = start;
	while(temp != NULL)
	{
		printf("\nName: %s\nID: %s\nSemester: %d\n", temp->name, temp->ID, temp->sem);
		temp = temp->next;
	}
	printf("\nList empty now!!\n");
}

void displayN(node* toP)
{
	printf("\nName: %s\nID: %s\nSemester: %d\n", toP->name, toP->ID, toP->sem);
}

void removeE()
{
	node* temp;
	temp = start;
	
	if(temp != NULL)
	{
		removed = start;
		start = start->next;
		printf("\n\t\tRemoved the first element\n");
		displayN(removed);
	}
	else
	{
		removed = NULL;
		printf("\n\t\tNo element is in the list\n");
	}
	
}
void insertEnd()
{
	node* temp;
	int i = 0;
	while(temp != NULL && temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}
	insertAtI(i);
}
int main()
{
	int choice = 0;
	do{
		printf("Enter - \n1 to insert at the start of the list\n2 to insert at index 'i'(starting at 0)\n3 to remove an element\n4 to insert at the end\n5 to display the list\n6 to exit\nYourchoice:\n");
		scanf("%d", &choice);
		fflush(stdin);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				printf("\nEnter an index:\n");
				int k = 0;
				scanf("%d", &k);
				fflush(stdin);
				insertAtI(k);
				break;
			case 3:
				removeE();
				break;
			case 4:
				insertEnd();
				break;
			case 5:
				display();
				break;
			case 6:
				printf("\n\t\texiting......\n");
				break;
			default:
				printf("\n\t\tInvalid choice.\n\t\tTry again.....\n");
		}
	}while(choice != 6);
	return 0;
}
