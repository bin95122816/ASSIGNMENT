//11866

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int number;
	struct Node* pre;
	struct Node* next;
} Node;

int main() {
	int number;
	int deletegap;
	scanf("%d %d", &number, &deletegap);

	Node* head = NULL;

	for (int i = 1; i <= number; i++) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->number = i;

		if (head == NULL) {
			head = newNode;
			head->next = head;
			head->pre = head;
		}
		else {
			Node* temp = head->pre;
			temp->next = newNode;
			newNode->pre = temp;
			newNode->next = head;
			head->pre = newNode;
		}
	}

	printf("<");;

	Node* temp = head;
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < deletegap - 1; j++) {
			temp = temp->next;
		}

		printf("%d", temp->number);

		if (i < number - 1) {
			printf(", ");
		}

		temp->pre->next = temp->next;
		temp->next->pre = temp->pre;

		Node* Delete = temp;
		temp = temp->next;
		free(Delete);
	}

	printf(">\n");

	return 0;
}