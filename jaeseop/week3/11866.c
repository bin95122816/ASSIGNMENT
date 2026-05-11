// 요세푸스 문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

// 오류 처리 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// pre 가르키는 노드 다음 노드 삭제
ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

int main(void) {
    ListNode* head = NULL;
    int N, K;
    scanf("%d %d", &N, &K);
    if (K < 1 || N < 1) {   // N이나 K가 1보다 작을 시 
        error("해당 숫자는 유효하지 않습니다. \n");
    }

    for (int i = 0; i < N; i++) {   // 입력받은 N만큼 연결 리스트 만들기
        ListNode* josephus = (ListNode*)malloc(sizeof(ListNode));
        if (josephus == NULL) error("메모리 할당 실패");
        josephus->data = i + 1; // 입력받은 N을 data에 할당 (for문이므로 +1)
        if (head == NULL) {
            head = josephus;
            josephus->link = head;
        }
        else {
            josephus->link = head->link;
            head->link = josephus;  // 원형 연결 리스트의 insert_last 구현
            head = josephus;
        }
    }

    ListNode* pre = head;           // 마지막 노드부터 시작
    ListNode* cur = head->link;     // 1번 노드부터 카운트

    printf("<");
    for (int i = 0; i < N; i++) {   // N만큼 반복
        for (int j = 0; j < K - 1; j++) {   // K번째 제거
            // 노드 이동
            pre = cur;  
            cur = cur->link;
        }

        if (i > 0) printf(", ");    // 첫번째가 아니면 앞에 콤마를 붙임
        printf("%d", cur->data);    // 제거된 숫자를 제거된 순서대로 출력

        cur = cur->link;    // 다음 카운트 시작 위치 미리 저장
        delete(head, pre);  // pre의 다음 노드 제거
    }
    printf(">\n");

    return 0;
}