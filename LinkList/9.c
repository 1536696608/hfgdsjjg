#include"linkhead.h"
int SeqLinkListInsert(Node* head)//�������в���Ԫ��
{
	Node* p = head;
	Node* q = (Node*)malloc(sizeof(Node));
	printf("���������Ԫ��\n");
	scanf("%d",&q->date);
	q->next =NULL;
	while(1)
	{
		if(q->date < p->next->date)
		{
			q->next = p->next;
			p->next = q;
			printf("����ɹ�\n");
			return 1;
		}
        else if(p->next->next == NULL)
        {
            q->next = p->next->next;
			p->next->next = q;
			printf("����ɹ�\n");
			return 1;
        }
		else
		{
			p = p->next;
		}
	}
}
