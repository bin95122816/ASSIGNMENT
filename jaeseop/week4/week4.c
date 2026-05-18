#include <stdio.h>
#include <stdlib.h>

typedef int element;

// a: nodetype 정의
typedef struct ListNode {
    element val;
    struct ListNode* link;
} nodetype;

// b: 원형 큐 타입 정의
typedef struct {
    nodetype* rear;
} linked_circular_queue;

// c: 큐 초기화
void init(linked_circular_queue* q) {
    q->rear = NULL;
}

// e: 공백 검사, 삽입, 삭제, 전체 노드 출력
int is_empty(linked_circular_queue* q) {    // 공백 검사
    return q->rear == NULL;
}

void enqueue(linked_circular_queue* q, element var) {   // 삽입
    nodetype* new_node = (nodetype*)malloc(sizeof(nodetype));
    if (new_node == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        return;
    }
    new_node->val = var;

    if (is_empty(q)) {
        new_node->link = new_node;      
        q->rear = new_node;
    }
    else {
        new_node->link = q->rear->link;  
        q->rear->link = new_node;       
        q->rear = new_node;              
    }
}

element dequeue(linked_circular_queue* q) { // 삭제
    if (is_empty(q)) {
        fprintf(stderr, "큐가 비어있습니다\n");
        exit(1);
    }

    nodetype* front = q->rear->link;
    element item = front->val;

    if (q->rear == front) {
        q->rear = NULL;
    }
    else {
        q->rear->link = front->link;
    }
    free(front);
    return item;
}

void print_queue(linked_circular_queue* q) {    // 전체 노드 출력
    if (is_empty(q)) {
        printf("큐가 비어있습니다.\n");
        return;
    }
    nodetype* p = q->rear->link;  
    printf("front -> ");
    do {
        printf("[%d] -> ", p->val);
        p = p->link;
    } while (p != q->rear->link);
    printf("(rear=%d)\n", q->rear->val);
}

// f: main문
int main() {
    linked_circular_queue q;

    init(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    print_queue(&q);    // 1, 2, 3 입력한 후 출력
    
    dequeue(&q);
    print_queue(&q);    // 한 항목 삭제 후 출력
    
    enqueue(&q, 4);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q, 5);
    print_queue(&q);

    return 0;
}