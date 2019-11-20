#include"linkhead.h"
void DestoryList(Node** head)//销毁链表
{
	Node* p,*q;
	// initList(&p);
	// initList(&q);
	p = q = (*head)->next;
	while(p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	printf("销毁成功\n");
	(*head)->next = NULL;
}
