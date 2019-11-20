#include"linkhead.h"
#include"linkhead.h"
int UnitList(Node** lsa,Node* lsb)
{
    if(lsb == NULL)
    {
        printf("合并成功\n");
        return 1;
    }
    else if(*lsa == NULL)
    {
        *lsa = lsb;
        printf("合并成功\n");
        return 1;
    }
	Node* p = *lsa;
	Node* q = lsb->next;
	Node* t = NULL;
    
	while(p->next != NULL&&q != NULL)
	{
		
		if(p->next->date > q->date)
		{
			t = q;

			q = q->next;
			t->next = p->next;
			p->next = t;
			p = p->next;

		}
		else if(p->next->date < q->date)
		{
			p = p->next;
		}
		else if(p->next->date == q->date)
		{
			p = p->next;
			q = q->next;
		}
		else
		{
			break;
		}
	}

	if(p->next == NULL)
	{
		p->next = q;
	}
	printf("合并成功\n");
    return 1;
}
