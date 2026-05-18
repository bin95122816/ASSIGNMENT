#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//풍선 터뜨리기
typedef struct ListNode
{
	int data;
	int number;
	struct ListNode* link;
}ListNode;

//삽입
ListNode* isert(ListNode* head, int data,int number)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = data;
	p->number = number;
	p->link = NULL;
	if (head == NULL)
	{
		head = p;
		p->link = head;
	}
	else
	{
		p->link = head->link;
		head->link = p;
		head = p;
	}
	return head;
}

//삭제
int delete(ListNode* head,int *move)
{
	ListNode* removed = head->link;
	int data = removed->data;
	*move = removed->number;
	head->link = removed->link;
	free(removed);
	return data;
}


int main(void)
{
	ListNode* head = NULL;
	int N;
	scanf("%d", &N);
	//값 먼저 넣기
	for (int i = 1; i <= N; i++)
	{
		int num;
		scanf("%d", &num);
		head = isert(head, i, num);
	}
	int move;
	int first = 1;
	//풍선에 적힌 숫자만큼 이동
	while (N > 0)
	{
		int data = delete(head, &move);
		if (!first) printf(" ");
		printf("%d", data);
		first = 0;
		N--;
		if (N == 0) break;
		//move 만큼 이동
		if (move > 0)
		{
			for (int i = 0; i < move - 1; i++)
				head = head->link;
		}
		else
		{
			for (int i = 0; i < -move; i++)
			{
				// 이전 노드 찾기
				ListNode* prev = head;
				while (prev->link != head)
					prev = prev->link;
				head = prev;
			}
		}
	}
	return 0;
}
