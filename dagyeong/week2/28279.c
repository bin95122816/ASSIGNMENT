#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

// 노드
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

// 메인
int main(void)
{
    ListType* q = create();

    int N;
    scanf("%d", &N);

    while (N--)
    {
        int order, x;
        scanf("%d", &order);

        switch (order)
        {
        case 1: // 앞에 넣기
            scanf("%d", &x);
            add_front(q, x);
            break;

        case 2: // 뒤에 넣기
            scanf("%d", &x);
            add_rear(q, x);
            break;

        case 3: // 앞에서 빼기
            printf("%d\n", delete_front(q));
            break;

        case 4: // 뒤에서 빼기
            printf("%d\n", delete_rear(q));
            break;

        case 5: // 크기
            printf("%d\n", q->size);
            break;

        case 6: // 비어있는지
            printf("%d\n", is_empty(q));
            break;

        case 7: // 앞 값
            printf("%d\n", peek_front(q));
            break;

        case 8: // 뒤 값
            printf("%d\n", peek_rear(q));
            break;
        }
    }

    return 0;
}
