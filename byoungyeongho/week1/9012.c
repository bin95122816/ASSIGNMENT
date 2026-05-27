//9012

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void check_vps(char* str) {
    int count = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            count++;
        }
        else if (str[i] == ')') {
            count--;
        }

        if (count < 0) {
            printf("NO\n");
            return;
        }
    }

    if (count == 0) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);

    char str[55];

    for (int i = 0; i < t; i++) {
        scanf("%s", str);
        check_vps(str);
    }

    return 0;
}