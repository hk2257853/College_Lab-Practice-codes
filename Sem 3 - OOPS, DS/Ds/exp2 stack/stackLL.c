#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *Top1;
struct Node *Top2;

void push();
int pop();
void display();
int isempty();
void displaytop();
void reverse();

void displaytop()
{
	printf("Top element: %d", Top1->data);
}

void reverse()
{
	while (Top1 != NULL)
	{ // fill Top 2 with Top1's data(it gets filled in reverse)
		struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
		NewNode->data = pop();
		if (Top2 == NULL)
		{
			Top2 = NewNode;
			NewNode->next = NULL;
		}
		else
		{
			NewNode->next = Top2;
			Top2 = NewNode;
		}
	}
	Top1 = Top2;
	Top2 = NULL;
}

void display()
{
	struct Node *tmptr;
	tmptr = Top1;
	printf("Data: ");
	while (tmptr != NULL)
	{
		printf("%d ", tmptr->data);
		tmptr = tmptr->next;
	}
}

int isempty()
{
	if (Top1 == NULL)
	{
		return 1;
	}
	return 0;
}

int pop()
{
	if (isempty() != 1)
	{
		int x;
		x = Top1->data;
		struct Node *tmptr;
		tmptr = Top1;
		Top1 = Top1->next;
		free(tmptr);
		return x;
	}
	else
	{
		printf("Stack underflow");
		return 0;
	}
	return 0;
}

void push()
{
	struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter data: ");
	scanf("%d", &NewNode->data);

	if (Top1 == NULL)
	{
		Top1 = NewNode;
		NewNode->next = NULL;
	}
	else
	{
		NewNode->next = Top1;
		Top1 = NewNode;
	}
}

int main()
{
	while (1)
	{
		int n;
		printf("1 push\n");
		printf("2 pop\n");
		printf("3 Display\n");
		printf("4 Display top\n");
		printf("5 Reverse\n");
		printf("6 Exit\n");
		printf("Enter from options:\n");

		scanf("%d", &n);

		switch (n)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			displaytop();
			break;
		case 5:
			reverse();
			break;
		case 6:
			exit(0);
			break;

		default:
			printf("Invalid Input");
			break;
		}

		printf("\n\n");
	}

	return 0;
}
