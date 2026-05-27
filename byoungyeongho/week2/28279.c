#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* a;
	struct Node* b;
}Node;

typedef struct head
{
	struct Node* f;
	struct Node* l;
	int count;
}head;

head* fp(head* h, int x)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = x;
	node->a = NULL;
	node->b = h->f;

	if (h->f != NULL)
	{
		h->f->a = node;
		h->f = node;
	}
	else
	{
		h->f = node;
		h->l = node;
	}
	h->count++;
	return h;
}

head* lp(head* h, int x)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = x;
	node->b = NULL;
	node->a = h->l;

	if (h->l != NULL)
	{
		h->l->b = node;
		h->l = node;
	}
	else
	{
		h->f = node;
		h->l = node;
	}
	h->count++;
	return h;
}

void fd(head* h)
{
	if (h->f == NULL)
	{
		printf("-1\n");
	}
	else
	{
		Node* tmp = h->f;
		printf("%d\n", tmp->data);
		h->f = tmp->b;
		if (h->f != NULL) h->f->a = NULL;
		else h->l = NULL;
		free(tmp);
		h->count--;
	}
}

void ld(head* h)
{
	if (h->l == NULL)
	{
		printf("-1\n");
	}
	else
	{
		Node* tmp = h->l;
		printf("%d\n", tmp->data);
		h->l = tmp->a;
		if (h->l != NULL) h->l->b = NULL;
		else h->f = NULL;
		free(tmp);
		h->count--;
	}
}

void s(head* h)
{
	printf("%d\n", h->count);
}

void ie(head* h)
{
	if (h->count == 0)
	{
		printf("%d\n",1);
	}
	else
	{
		printf("%d\n",0);
	}
	
}

void pf(head* h)
{
	if (h->f != NULL) printf("%d\n", h->f->data);
	else printf("-1\n");
}

void pl(head* h)
{
	if (h->l != NULL) printf("%d\n", h->l->data);
	else printf("-1\n");
}

int main()
{
	head* dec = (head*)malloc(sizeof(head));
	dec->f = NULL;
	dec->l = NULL;
	dec->count = 0;

	int n;
	int d;
	int x;

	if (scanf("%d", &n) != 1) return 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &d);
		if (d == 1)
		{
			scanf("%d", &x);
			fp(dec, x);
		}
		else if (d == 2)
		{
			scanf("%d", &x);
			lp(dec, x);
		}
		else if (d == 3)
		{
			fd(dec);
		}
		else if (d == 4)
		{
			ld(dec);
		}
		else if (d == 5)
		{
			s(dec);
		}
		else if (d == 6)
		{
			ie(dec);
		}
		else if (d == 7)
		{
			pf(dec);
		}
		else if (d == 8)
		{
			pl(dec);
		}
	}
// 설명만 잘 하면 될 듯.
	return 0;
}
