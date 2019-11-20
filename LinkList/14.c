#include"linkhead.h"

Node* CreateRandList(int n)//随机生成递增数列
{
	Node *p,*q,*head;
	int m = n;
	int date = 0;
//	initList(&p);
	initList(&head);

//    head->next == NULL;
	for(m;m > 0;m--)
	{

		initList(&p);

		if(p == NULL)
		{
        	printf("分配空间失败！");
        	exit(1);
    	}
		date += (rand()%10+1);
		p->date = date;
		p->next = NULL;
		if(m == n)
		{
			initList(&head);
			if(head == NULL)
			{
        		printf("分配空间失败！");
        		exit(1);
    		}
			head->next = p;
		}

		else
		{
			q->next = p;
		}
		q = p;
	}
	q->next = NULL;
	return head;
}
