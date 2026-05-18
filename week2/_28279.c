#include <stdio.h>
# define _CRT_SECURE_NO_WARNINGS

typedef struct Deque {
	int data[10];
	int rear, front;
} Deque;

//초기값 할당
void init(Deque* q)
{
	q->front = -1;
	q->rear = -1;
}

//비어있는 경우
int is_empty(Deque* q)
{
	if (q->front == q->rear == -1)
	{
		printf("비어있음\n");
		return 1;
	}
	else
		return 0;
}

//가득 차 있는 경우 
int is_full(Deque* q)
{
	if (q->rear == 9)
	{
		printf("비어있음\n");
		return 1;
		//1리턴 하는 이유..
	}
	else
		return 0;
}
//void peek
//앞에 값 넣기
void Add_front(Deque* q,int item)
{
	if (is_full(q))
		return;
	q->data[++(q->front)] = item;
}
//뒤에 값 넣기
void Add_rear(Deque* q, int item )
{
	if (is_full(q))
		return;
	q->data[++(q->rear)] = item;
}

//앞에 값 빼기
int Delete_front(Deque* q)
{
	if (is_empty(q))
		return -1;
	int item = q->data[++(q->front)];
	printf("%d", &item);
	return item;
}

//뒤에 값 뺴기
int Delete_rear(Deque* q)
{
	if (is_empty(q))
		return -1;
	int item = q->data[++(q->rear)];
	printf("%d", &item);
	return item;
}

int main(void)
{
	Deque *q;
	int item = 0; 
	//몇 번 명령 받을 건지 입력 받기
	int N;
	printf("N 입력 : ");
	scanf("%d", &N);
	printf("\n");
	//입력받은 N만큼 반복
	for (int i = 0; i< N;i++)
	{
		//사용자에게 명령 입력 받기
		int order;
		scanf("%d", &order);

		//1번인 경우 : 덱의 앞에 넣기 Add_front
		if (order == 1)
		{
			scanf("%d", &item);
			printf("\n");
			Add_front(q, item);
		}

		//2번인 경우 : 덱의 뒤에 넣기 Delete_rear
		else if (order == 2)
		{
			scanf("%d", &item);
			printf("\n");
			Delete_front(q, item);
		}
		
		//3번인 경우 : 정수가 있다면 맨 앞의 정수 빼고 출력, 없으면 -1 출력 Delete _front
		else if (order == 3)
		{
			Delete_front(q);
		}
		//4번인 경우 : Delete_rear 없으면 -1
		else if (order == 4)
		{
			Delete_rear(q);
		}
		//5번인 경우 : 덱에 들어있는 정수의 개수 출력
		else if (order == 5)
		{
			
		}
		//6번인 경우 : is_empty
		else if (order == 6)
		{
			int i = is_empty(q);
			printf("%d", &i);
		}
		//7번인 경우 : 맨앞의 정수 출력  print(peek_front)
		//8번인 경우 : 맨 뒤의 정수 출력 (peek_rear)
	}

	return 0;
}
