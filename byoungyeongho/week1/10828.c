#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000

int stack[MAX_SIZE];
int top_i = -1;

void push(int x) {
    stack[++top_i] = x;
}

int pop() {
    if (top_i == -1) return -1;
    return stack[top_i--];
}

int size() {
    return top_i + 1;
}

int empty() {
    return (top_i == -1);
}

int top() {
    if (top_i == -1) return -1;
    return stack[top_i];
}

int main() {
    int n;
    scanf("%d", &n);

    char cmd[10];
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%s", cmd);

        if (strcmp(cmd, "push") == 0) {
            scanf("%d", &x);
            push(x);
        }
        else if (strcmp(cmd, "pop") == 0) {
            printf("%d\n", pop());
        }
        else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(cmd, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(cmd, "top") == 0) {
            printf("%d\n", top());
        }
    }
    return 0;
}