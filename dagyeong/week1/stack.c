#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 10000 +1

typedef int element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType* s) {
    s->top = -1;
}

int is_empty(StackType* s) {
    return (s->top == -1);
}

int is_full(StackType* s) {
    return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType* s, element item) {
    if (is_full(s)) return;
    s->data[++(s->top)] = item;
}

element pop(StackType* s) {
    if (is_empty(s)) return -1;
    return s->data[(s->top)--];
}

element peek(StackType* s) {
    if (is_empty(s)) return -1;
    return s->data[s->top];
}

int main(void)
{
    StackType s;
    init_stack(&s);

    int n;
    scanf_s("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char user[10];
        scanf_s("%s", user);

        if (strcmp(user, "push") == 0)
        {
            int data;
            scanf_s("%d", &data);
            push(&s, data);
        }
        else if (strcmp(user, "pop") == 0)
        {
            printf("%d\n", pop(&s));
        }
        else if (strcmp(user, "top") == 0)
        {
            printf("%d\n", peek(&s));
        }
        else if (strcmp(user, "size") == 0)
        {
            printf("%d\n", s.top + 1);
        }
        else if (strcmp(user, "empty") == 0)
        {
            printf("%d\n", is_empty(&s));
        }
    }

    return 0;
}
//
