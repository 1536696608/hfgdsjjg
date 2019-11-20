#include"linkhead.h"
void SplitList(Node* head,Node** A,Node** B)//将链表分为奇数链表与偶数链表
{

	int i;
	Node* n = NULL;
	Node* t = NULL;
	Node* p = head->next;
	Node* q = *A;
	Node* r = *B;
	while(p != NULL)
	{

		n = (Node*)malloc(sizeof(Node));
		n->date = p->date;

		n->next = NULL;

		if(n->date % 2 == 1)
		{
			q->next = n;
			q = n;
		}
		else
		{
			r->next = n;
			r = n;
		}

		p = p->next;
	}
	printf("奇数为:\n");
	Travel(*A);
	printf("偶数为:\n");
	Travel(*B);
}
