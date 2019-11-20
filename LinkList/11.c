#include"linkhead.h"
Node* AddCommonToList(Node* list1,Node* list2)//递增有序链表相同元素
{
	
	Node* p = list1;
	Node* q = list2;
	Node* head;
	initList(&head);
	Node* m = head;
	if(head==NULL)
		{
				printf("分配空间失败！");
				exit(1);
		}
	if(p != NULL&&q != NULL)
	{
		p = p->next;
		q = q->next;
	}
	while(p != NULL&&q != NULL)
	{
		Node* n;
		initList(&n);
		if(n==NULL)
    	{
        	printf("分配空间失败！");
        	exit(1);
    	}
		if(p->date == q->date)
		{
			n->date = p->date;
			m->next = n;
			m = n;
            p = p->next;
		    q = q->next;
		}
		else if(p->date < q->date)
		{
			p = p->next;
		}
		else if(p->date > q->date)
		{
			q = q->next;
		}
	 }
	 return head;
}
