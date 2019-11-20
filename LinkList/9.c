#include"linkhead.h"
int SeqLinkListInsert(Node* head)//递增数列插入元素
{
	Node* p = head;
	Node* q = (Node*)malloc(sizeof(Node));
	printf("请输入插入元素\n");
	scanf("%d",&q->date);
	q->next =NULL;
	while(1)
	{
		if(q->date < p->next->date)
		{
			q->next = p->next;
			p->next = q;
			printf("插入成功\n");
			return 1;
		}
        else if(p->next->next == NULL)
        {
            q->next = p->next->next;
			p->next->next = q;
			printf("插入成功\n");
			return 1;
        }
		else
		{
			p = p->next;
		}
	}
}
