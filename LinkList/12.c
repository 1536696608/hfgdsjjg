#include"linkhead.h"
void DeletR(Node* head)//删除递增有序数列重复元素
{
	Node *p = head->next;
	Node *t;
	while(p != NULL&&p->next != NULL)
	{
		if(p->date < p->next->date)
		{
			p = p->next;
		}
		else
		{
			t = p->next;
			p->next = t->next;
			free(t);
		}
	}
	printf("删除成功\n");
}
