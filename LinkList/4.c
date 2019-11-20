#include"linkhead.h"
int Len_List(Node* head)//求链表长度
{
	int len = 0;
	Node *p;
	initList(&p);
	p = head->next;
	while(p != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}
