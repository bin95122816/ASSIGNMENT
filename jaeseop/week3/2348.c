// 풍선 터뜨리기 문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element id; // 풍선 번호
    element data;
    struct ListNode* rlink;
    struct ListNode* llink;
}ListNode;

// 오류 처리 함수
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 이중 연결 리스트 삽입 함수
void insert(ListNode* before, int id, element value) {
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    if (newnode == NULL) error("메모리 할당 실패");
    newnode->id = id;
    newnode->data = value;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

// pre 가르키는 노드 다음 노드 삭제
void delete(ListNode* removed) {
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

int main(void) {
    ListNode* head = NULL;
    int N, K;
    scanf("%d", &N);
    if ( N < 1) {   // N이 1보다 작을 시 
        error("해당 숫자는 유효하지 않습니다.\n");
    }


    for (int i = 1; i <= N; i++) {
        scanf("%d", &K);
        if (head == NULL) {
            head = (ListNode*)malloc(sizeof(ListNode));
            if (head == NULL) error("메모리 할당 실패");
            head->id = i;   // 풍선 번호
            head->data = K; // 풍선에 들어갈 정수
            head->rlink = head;
            head->llink = head;
        }
        else {
            insert(head->llink, i, K);
        }
    }

    ListNode* current = head;  // 1번 풍선부터 시작

    for (int i = 0; i < N; i++) {
        printf("%d ", current->id);   // 터지는 풍선 번호 출력

        int v = current->data;
        ListNode* next_balloon = NULL;

        if (i < N - 1) {  // 마지막 풍선이 아닐 때만 다음 위치 계산
            if (v > 0) {
                next_balloon = current->rlink;          // 일단 한 칸 이동
                delete(current);                        // 먼저 삭제
                for (int j = 0; j < v - 1; j++)         // 1번 더 이동
                    next_balloon = next_balloon->rlink;
            }
            else {  // v < 0일 때
                next_balloon = current->llink;          // 일단 한 칸 이동
                delete(current);
                for (int j = 0; j < -v - 1; j++)        // 1번 더 이동
                    next_balloon = next_balloon->llink;
            }
            current = next_balloon;
        }
        else {
            delete(current);
            current = NULL;
        }
    }
    printf("\n");

    return 0;
}