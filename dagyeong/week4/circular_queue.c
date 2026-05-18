#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//원형 연결 리스트를 이용한 원형 큐
typedef int element;
typedef struct NodeType
{
	int val;
	struct NodeType* link;
}NodeType;

typedef struct linked_circular_queue
{
	struct NodeType* rear;
}linked_circular_queue;

//초기화 
void init(linked_circular_queue* q)
{
	q->rear = NULL;
}

//비어 있는지 검사
int is_empty(linked_circular_queue* q)
{
	return (q->rear == NULL);
}

//노드 삽입
void enqueue(linked_circular_queue* q, element var)
{
	NodeType* newQ = (NodeType*)malloc(sizeof(NodeType));
	newQ->val = var;
	if (is_empty(q))
	{
		q->rear = newQ;
		newQ->link = q->rear;
	}
	else
	{
		newQ->link = q->rear->link;
		q->rear->link = newQ;
		q->rear = newQ;
	}
}

//삭제하고 반환
element dequeue(linked_circular_queue* q)
{
	if (is_empty(q))
	{
		printf("비어있음\n");
		return -1; 
	}

	NodeType* removed = q->rear->link;
	int data = removed->val;

	// 노드가 1개일때
	if (q->rear == removed)
	{
		q->rear = NULL;
	}
	else
	{
		q->rear->link = removed->link;
	}

	free(removed);
	return data;
}



//출력
void print_queue(linked_circular_queue* q)
{
	if (is_empty(q))
	{
		printf("공백\n");
		return;
	}

	NodeType* p = q->rear->link;  

	do
	{
		printf("%d->", p->val);
		p = p->link;
	} while (p != q->rear->link);

	printf("\n");
}

int main(void)
{
	linked_circular_queue* q = (linked_circular_queue*)malloc(sizeof(linked_circular_queue));
	init(q);
	enqueue(q, 1);
	print_queue(q);
	enqueue(q, 2);
	print_queue(q);
	enqueue(q, 3);
	print_queue(q);
	dequeue(q);
	print_queue(q);
	enqueue(q, 4);
	print_queue(q);
	dequeue(q);
	print_queue(q);
	dequeue(q);
	print_queue(q);
	dequeue(q);
	print_queue(q);
	enqueue(q, 5);
	print_queue(q);
	return 0;
}
