#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;

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

int check_matching(const char* in)
{
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in);
    init_stack(&s);

    for (int i = 0; i < n; i++)
    {
        ch = in[i];
        switch (ch)
        {
        case '(':
            push(&s, ch);
            break;
        case ')':
            if (is_empty(&s))return 0;
            else
            {
                open_ch = pop(&s);
                if ((open_ch == '(') && ch != ')')
                    return 0;
            }
            break;
        }

    }
}

int main(void)
{
    int n;
    scanf_s("%d", &n);

    for (int i = 0; i < n; i++)
    {
        charp[101];
        scanf_("%s", &p);

        if (check_matching(p) == 1)
            printf("Yes\n");
        else
            printf("NO\n");

    }

    return 0;
}
