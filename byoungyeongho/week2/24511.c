#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int type;
	int data;
	struct element* n;//아직 아래의 element는 읽기 전이랑 위에 elemt적기
}element;


int main()
{
	int n;//초기 원소개수
	int type;//큐인지 스택인지 임시저장
	int data;//데이터 임시저장
	int nextdata;//삽입시 다음으로 넘어가는 데이터 임시저장
	int m;//추가되는 데이터 길이

	scanf("%d", &n);
	element* head = (element*)malloc(sizeof(element));
	head->n = NULL;

	element* h = head;
	//연결리스트 만들기
	for (int i = 0; i < n-1; i++)
	{
		
		element* p = (element*)malloc(sizeof(element));
		p->n = NULL;
		h->n = p;
		h =h->n;
	}
	
	//type입력받기
	h = head;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &type);
		h->type = type;
		h = h->n;
	}
	//초기 데이터입력
	h = head;
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		h->data = data;
		h = h->n;
	}


	//추가되는 데이터
	scanf("%d", &m);

	element* head2 = (element*)malloc(sizeof(element));
	element* h2 = head;
	h2 = head2;
	scanf("%d", &data);
	h2->n = NULL;
	h2->data = data;


	for (int i = 0; i < m-1; i++)
	{
		scanf("%d", &data);
		element* p = (element*)malloc(sizeof(element));
		p->n = NULL;
		p->data = data;
		h2->n = p;
		h2 = h2->n;
	}
	



	//데이터 추가
	
	h2 = head2;
	for (int i = 0; i < m; i++)
	{
		h = head;
		nextdata = h2->data;
		while (h != NULL)
		{
			if (h->type == 0)//큐이면
			{
				int nd = h->data;
				h->data=nextdata;
				nextdata = nd;
				
			}
			else if(h->type==1) //스택이면
			{
				h->data = h->data;//전부그대로
				
			}
			h = h->n;
			
		} 
		printf("%d ", nextdata);
		h2 = h2->n;
	}


}