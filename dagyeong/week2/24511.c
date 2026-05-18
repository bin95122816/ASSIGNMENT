#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef int element;

// 노드_28279때 썼던 연결리스트 코드 
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

// 덱 (연결 리스트)
typedef struct ListType {
    int size;
    ListNode* head;
    ListNode* tail;
} ListType;

// 생성
ListType* create()
{
    ListType* plist = (ListType*)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

// 공백 검사
int is_empty(ListType* q)
{
    return (q->size == 0);
}

// 앞에 삽입
void add_front(ListType* plist, element data)
{
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    temp->data = data;
    temp->link = plist->head;

    plist->head = temp;

    if (plist->tail == NULL)
        plist->tail = temp;

    plist->size++;
}

// 뒤에 삽입
void add_rear(ListType* plist, element data)
{
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    temp->data = data;
    temp->link = NULL;

    if (plist->tail == NULL)
    {
        plist->head = plist->tail = temp;
    }
    else
    {
        plist->tail->link = temp;
        plist->tail = temp;
    }

    plist->size++;
}

// 앞에서 삭제
int delete_front(ListType* plist)
{
    if (is_empty(plist)) return -1;

    ListNode* temp = plist->head;
    int data = temp->data;

    plist->head = temp->link;

    if (plist->head == NULL)
        plist->tail = NULL;

    free(temp);
    plist->size--;

    return data;
}

// 뒤에서 삭제
int delete_rear(ListType* plist)
{
    if (is_empty(plist)) return -1;

    ListNode* temp = plist->head;

    // 노드 1개일 때
    if (plist->head == plist->tail)
    {
        int data = temp->data;
        free(temp);
        plist->head = plist->tail = NULL;
        plist->size--;
        return data;
    }

    // tail 이전 노드 찾기
    while (temp->link != plist->tail)
        temp = temp->link;

    int data = plist->tail->data;
    free(plist->tail);
    plist->tail = temp;
    plist->tail->link = NULL;

    plist->size--;
    return data;
}

// 앞 값 보기
int peek_front(ListType* q)
{
    if (is_empty(q)) return -1;
    return q->head->data;
}

// 뒤 값 보기
int peek_rear(ListType* q)
{
    if (is_empty(q)) return -1;
    return q->tail->data;
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





