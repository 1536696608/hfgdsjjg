#include"linkhead.h"
void DestoryList(Node** head)//��������
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
	printf("���ٳɹ�\n");
	(*head)->next = NULL;
}
