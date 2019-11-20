#include"linkhead.h"
int Find_Index(Node* head,int i)//查找指定位置元素
{
	int n = i;
	Node* p;
	initList(&p);
	p = head->next;
	if(i < 0||i >= Len_List(head)||head == NULL)
	{
		printf("查找失败/n");
		return -1;
	}
	else
	{
		while(n > 0)
		{
			n--;
			p = p->next;
		}
	}
	return p->date;
}
