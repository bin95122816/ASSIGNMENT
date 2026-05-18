#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

typedef int element;
typedef struct nodetype
{
	element val;
	struct nodetype* link;

} nodetype;

typedef struct linkled_circular_queue
{
	nodetype* rear;
} linkled_circular_queue;

void init(linkled_circular_queue* q)
{
	q->rear = NULL;
}

void enqueue(linkled_circular_queue* q, int item)
{
	nodetype* newNode = (nodetype*)malloc(sizeof(nodetype));
	newNode->val = item;
	if (is_empty(q)==1)
	{
		q->rear = newNode;
		newNode->link = newNode;
	}
	else
	{
		newNode->link = q->rear->link;
		q->rear->link = newNode;
		q->rear = newNode;
	}
	
}

int is_empty(linkled_circular_queue* q)
{
	return q->rear == NULL;
}

element dequeue(linkled_circular_queue* q)
{
	if(is_empty(q)==1)
	{
		printf("큐가 빈 상태");
		exit(1);
	}
	else
	{
		int last = 0;
		if (q->rear->link == q->rear)
		{
			last = 1;
		}

		nodetype* deleteNode;
		deleteNode = q->rear->link;
		q->rear->link = deleteNode->link;
		element returnint = deleteNode->val;
		free(deleteNode);
		if(last==1)
		{
			q->rear = NULL;
		}
		return returnint;


	}

}

void print_queue(linkled_circular_queue* q)
{
	nodetype* printNode;
	if (is_empty(q) == 1)
	{
		printf("연결리스트 큐가 빈상태입니다\n");
		
	}
	else
	{
		printNode = q->rear;
		printf("연결리스트 큐의 모든노드의 값: ");
		do
		{
			printNode = printNode->link;
			printf("%d ", printNode->val);
			
			
		} while (printNode != q->rear);
		printf("\n");
	}
}

void print_current_rear(linkled_circular_queue* q)
{
	if (is_empty(q))
	{
		printf("큐가 비어 있습니다.\n");
	}
	else
	{
		printf("현재큐의 rear의 값: %d\n", q->rear->val);
	}
}

int main()
{
	linkled_circular_queue* q = (linkled_circular_queue*)malloc(sizeof(linkled_circular_queue));
	
	init(q);

	//123삽입후 큐 출력
	enqueue(q, 1);
	print_current_rear(q);
	enqueue(q, 2); 
	print_current_rear(q);
	enqueue(q, 3); 
	print_current_rear(q);
	print_queue(q);

	//한항목 삭제후 출력
	dequeue(q); 
	print_current_rear(q);
	print_queue(q);

	//4삽입후 3개 항목삭제후 5삽입후 출력
	enqueue(q, 4);
	print_current_rear(q);
	dequeue(q); 
	print_current_rear(q);
	dequeue(q); 
	print_current_rear(q);
	dequeue(q); 
	print_current_rear(q);
	enqueue(q, 5); 
	print_current_rear(q);
	print_queue(q);

}