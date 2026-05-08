//2348


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int number;
	int paper;
	struct Node* prev;
	struct Node* next;
} Node;

Node* add(Node* head, int paper, int number)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->number = number;
	newNode->paper = paper;

	if (head == NULL)
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		head = newNode;
	}
	else
	{
		Node* temp = head->prev;

		temp->next = newNode;
		newNode->prev = temp;

		newNode->next = head;
		head->prev = newNode;
	}
	return head;
}



int main()
{
	Node* head = NULL;

	int number = 0;
	int paper = 0;


	scanf(" %d", &number);

	for(int i=0; i < number; i++)
	{
		
		scanf("	%d", &paper);
		head =add(head, paper, i+1);
	}

	
	Node* temp = head;
	int nextdelete = 0;


	for (int i = 0; i < number; i++)
	{
		printf("%d ", temp->number);
		nextdelete = temp->paper;

		if (temp->next == temp)
		{
			free(temp);
			break;
		}

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;

		Node* temp2 = temp;

		if (nextdelete > 0)
		{
			temp = temp->next;
			for (int j = 1; j < nextdelete; j++)
			{
				temp = temp->next;
			}
		}
		else
		{
			temp = temp->prev;
			for (int j = 1; j < -nextdelete; j++)
			{
				temp = temp->prev;
			}
		}

		free(temp2);
	}
	
}