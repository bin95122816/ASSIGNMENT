#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
}ListNode;

// 오류처리 함수
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 삽입 함수
ListNode* insert_first(ListNode* head, int value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}
ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

// 삭제 함수
ListNode* delete_first(ListNode* head) {
    ListNode* removed;
    if (head == NULL) return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}
ListNode* delete(ListNode* head, ListNode* pre) {
    ListNode* removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

//리스트 출력
void print_list(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->link) {
        printf("%d->", p->data);
    }
    printf("NULL\n");
}


int main() {
    // 길이 N 입력받기
    int N;
    scanf("%d", &N);

    int* A = (int*)malloc(sizeof(int) * N); // 수열 A
    int* B = (int*)malloc(sizeof(int) * N); // 수열 B
    if (A == NULL || B == NULL) error("메모리 할당 실패");

    // A[i] = 0 이면 큐, 1 이면 스택
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    // B[i] : i번 자료구조의 초기 원소
    for (int i = 0; i < N; i++) scanf("%d", &B[i]);

    // 큰 큐 구성: 큐 타입(A[i]==0)인 원소만, 인덱스 역순으로 삽입
    // tail 포인터를 따로 관리하여 O(1) 뒤쪽 삽입 가능
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int i = N - 1; i >= 0; i--) {
        if (A[i] == 0) {  // 큐인 경우만 처리
            if (head == NULL) {
                head = insert_first(head, B[i]);
                tail = head;
            }
            else {
                head = insert(head, tail, B[i]); // tail 뒤에 삽입
                tail = tail->link;               // 새 노드가 새 tail
            }
        }
    }

    int M;
    scanf("%d", &M);

    for (int j = 0; j < M; j++) {
        int x;
        scanf("%d", &x);

        if (head == NULL) {
            printf("%d ", x);
        }
        else {
            // 1) 큰 큐 뒤(tail)에 x 삽입
            head = insert(head, tail, x);
            tail = tail->link;

            // 2) 큰 큐 앞(head)에서 pop
            printf("%d ", head->data);
            head = delete_first(head);
        }
    }
    printf("\n");


    while (head != NULL)
        head = delete_first(head);
    // 수열 A, B 헤제
    free(A);
    free(B);

    return 0;
}