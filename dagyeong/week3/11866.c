#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//원형연결리스트로 요세푸스 문제 해결하기
typedef struct ListNode
{
   int data;
   struct ListNode* link;
}ListNode;

//삽입
ListNode* isert(ListNode *head, int data)
{
   ListNode* p = (ListNode*)malloc(sizeof(ListNode));
   p->data = data;
   p->link = NULL;
   if (head == NULL)
   {
      head = p;
      p->link = head;
   }
   else
   {
      p->link = head->link;
      head->link = p;
      head = p;
   }
   return head;
}

//삭제
int delete(ListNode* prev)
{
   ListNode* removed = prev->link;
   int data = removed->data;

   prev->link = removed->link;
   free(removed);
   return data;   
}


int main(void)
{
   ListNode* head = NULL;
   int N;
   
   int k;
   scanf("%d %d", &N, &k);
   for(int i=1;i <=N;i++)
   {
      head = isert(head, i);
   }

   //k칸 이동, 가리키고 있는 수 삭제, 
   //삭제 후에는 그 반시계 방향 바로 옆에 잇는 수 가르킴,
   while (N > 1)
   {
      for (int i = 0; i < k-1;i++)
         head = head->link;
      printf("%d",delete(head));
      N--;
   }
   return 0;
}
