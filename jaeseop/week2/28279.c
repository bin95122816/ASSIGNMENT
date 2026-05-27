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
    int N;
    scanf("%d", &N);

    ListNode* head = NULL;
    ListNode* tail = NULL;   // 뒤쪽 삽입을 위한 포인터
    int size = 0;            // 명령 5번을 위한 개수 카운터

    for (int i = 0; i < N; i++) {
        int cmd;
        scanf("%d", &cmd);

        switch (cmd) {
        case 1: {  // 앞에 삽입
            int x;
            scanf("%d", &x);
            head = insert_first(head, x);
            if (tail == NULL) tail = head;   // 첫 원소면 tail도 설정
            size++;
            break;
        }

        case 2: {  // 뒤에 삽입
            int x;
            scanf("%d", &x);
            if (head == NULL) {              // 비어있을때
                head = insert_first(head, x);
                tail = head;
            }
            else {
                head = insert(head, tail, x); // tail 뒤에 삽입
                tail = tail->link;            // tail을 새 노드로 갱신
            }
            size++;
            break;
        }

        case 3: {  // 앞에서 삭제 후 출력
            if (head == NULL) {
                printf("-1\n");
            }
            else {
                printf("%d\n", head->data);
                head = delete_first(head);
                size--;
                if (head == NULL) tail = NULL;  // 비었으면 tail도 NULL
            }
            break;
        }

        case 4: {  // 뒤에서 삭제 후 출력
            if (head == NULL) {
                printf("-1\n");
            }
            else {
                printf("%d\n", tail->data);
                if (head == tail) {           // 원소가 하나뿐일 때
                    head = delete_first(head);
                    tail = NULL;
                }
                else {  // tail의 직전 노드를 찾기
                    ListNode* pre = head;
                    while (pre->link != tail) {
                        pre = pre->link;
                    }
                    head = delete(head, pre); // pre 다음을 삭제
                    tail = pre;               // tail 갱신
                }
                size--;
            }
            break;
        }

        case 5:  // 개수 출력
            printf("%d\n", size);
            break;

        case 6:  // 비었는지 확인
            printf("%d\n", head == NULL ? 1 : 0);
            break;

        case 7:  // 맨 앞 값 출력
            printf("%d\n", head == NULL ? -1 : head->data);
            break;

        case 8:  // 맨 뒤 값 출력
            printf("%d\n", tail == NULL ? -1 : tail->data);
            break;
        }
    }

    return 0;
}