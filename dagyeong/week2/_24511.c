#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
	return (q->front == q->rear);
	
}

//가득 차 있는 경우
int is_full(Deque* q)
{
	return (q->rear == 9);
	
}

//앞에 값 넣기
void Add_front(Deque* q, int item)
{
	if (is_full(q))
	{
		return ;
	}
	else
	{
		q->data[(q->front)--] = item;
	}
}
//뒤에 값 넣기
void Add_rear(Deque* q, int item)
{
	if (is_full(q))
	{
		return;
	}
	else
	{
		q->data[++(q->rear)] = item;
	}
}



//뒤에 값 뺴기
int Delete_front(Deque* q)
{
	if (is_empty(q))
	{
		return -1;
	}
	return q->data[++(q->front)];
}

// 뒤에서 삭제
int Delete_rear(Deque* q)
{
	if (is_empty(q))
	{
		return -1;
	}
	return q->data[(q->rear)--];
}

int main(void)
{
    int n;
    scanf("%d", &n);

    // malloc 사용 , 그냥 A[n]으로 하면 오류 나서..
    int* A = (int*)malloc(sizeof(int) * n);
    int* B = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    int m;
    scanf("%d", &m);

    int* C = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &C[i]);
    }

  //큐 값만 저장
    int* queue = (int*)malloc(sizeof(int) * n);
    int size = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (A[i] == 0) {
            queue[size++] = B[i];
        }
    }

    int front = 0;

    // 결과 출력
    for (int i = 0; i < m; i++) {
        if (front < size) {
            printf("%d ", queue[front++]);
        }
        else {
            printf("%d ", C[i]);
        }
    }

    free(A);
    free(B);
    free(C);
    free(queue);

	return 0;
}





