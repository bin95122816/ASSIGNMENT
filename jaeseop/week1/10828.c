#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 10000

typedef int element;	// 문자 element를 구조체로 설정
typedef struct {
	element data[MAX_STACK_SIZE];	// 크기가 100인 정수 배열 
	int top;	// 스택 top 정의
}StackType;

// 스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1;	// top를 -1로 초기화
}

// 공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s) {
	return(s->top == (MAX_STACK_SIZE - 1));
}

// 삽입함수 (스택에 들어있는 정수가 없는 경우에는 -1을 출력)
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;	// 스택이 포화 상태가 아니라면 top을 증가시킨 후 입력받은 데이터 저장
}
// 삭제함수 (스택이 비어있으면 1, 아니면 0을 출력)
element pop(StackType* s) {
	if (is_empty(s)) {
		return -1;	// -1
	}
	else return s->data[(s->top)--];	// top값을 반환하고 top을 1 감소시켜 스택에서의 삭제 구현
}
// 피크함수
element peek(StackType* s) {
	if (is_empty(s)) {
		return -1;
	}
	else return s->data[s->top];	// top값 반환
}
// 스택에 들어있는 정수 개수 출력 (스택에 아무것도 없으면 -1출력
int size(StackType* s) {
	return s->top + 1;
}



int main(void) {
    StackType s;
    init_stack(&s);

    int n;
    scanf("%d", &n);        // 명령의 수 입력

    for (int i = 0; i < n; i++) {
        char cmd[10];
        scanf("%s", cmd);

        if (strcmp(cmd, "push") == 0) {
            int x;
            scanf("%d", &x);
            push(&s, x);
        }
        else if (strcmp(cmd, "pop") == 0) {
            printf("%d\n", pop(&s));
        }
        else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", size(&s));
        }
        else if (strcmp(cmd, "empty") == 0) {
            printf("%d\n", is_empty(&s));
        }
        else if (strcmp(cmd, "top") == 0) {
            printf("%d\n", peek(&s));
        }
    }

	return 0;
}