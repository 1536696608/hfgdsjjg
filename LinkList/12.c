#include"linkhead.h"
void DeletR(Node* head)//ɾ���������������ظ�Ԫ��
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
	printf("ɾ���ɹ�\n");
}
