#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef char element;	// 문자 element를 구조체로 설정
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

// 삽입함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;	// 스택이 포화 상태가 아니라면 top을 증가시킨 후 입력받은 데이터 저장
}
// 삭제함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];	// top값을 반환하고 top을 1 감소시켜 스택에서의 삭제 구현
}
// 피크함수
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];	// top값 반환
}

int check_matching(const char* in) {
	StackType s;
	char ch, open_ch;	
	int i, n = strlen(in);	// n = 문자열의 길이
	init_stack(&s);	// 스택의 초기화 (init_stack함수가 매개변수를 포인터로 받으므로 &사용)

	for (i = 0; i < n; i++) {
		ch = in[i];	//다음에 들어오는 문자
		switch(ch) {
			case '(':
			case '[':
			case '{':
				push(&s, ch);	// 입력된 ch값이 '(', '[', '{'이라면 스택에 추가
				break;
			case ')':
			case ']':
			case '}':
				if (is_empty(&s))	// 스택이 공백이라면
					return 0;	// 오류
				else {
					open_ch = pop(&s);	// 스택의 최상단에 있는 문자를 반환하여 open_ch에 저장
					if ((open_ch == '(' && ch != ')') ||	// 스택에서 나온 값이 '('일 때 ch값이 ')'이 아니거나
						(open_ch == '[' && ch != ']') ||	// 스택에서 나온 값이 '['일 때 ch값이 ']'이 아니거나
						(open_ch == '{' && ch != '}')) {		// 스택에서 나온 값이 '{'일 때 ch값이 '}'이 아니라면
						return 0;	// 오류
						break;
					}
				}
		}
	}
	if (!is_empty(&s))	// for반복문이 끝나도 스택이 공백이 아니라면
		return 0;	// 오류
	return 1;
}

int main(void) {
	int num = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		char p [MAX_STACK_SIZE];
		scanf("%s", p);

		if (check_matching(p) == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}