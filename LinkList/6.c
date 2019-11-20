#include"linkhead.h"
int Insert(Node* head)//插入元素
{
	int x,i;
	Node* p = head;
	Node* q = (Node*)malloc(sizeof(Node));
	printf("请输入插入元素插入位置\n");
	scanf("%d%d",&x,&i);
	if(q==NULL)
    	{
        	printf("分配空间失败！");
        	exit(1);
    	}
	if(i < 0)
	{
		printf("erro\n");
		return -1;
	}
	while(i > 0)
	{
		if(p->next == NULL)
		{
			printf("插入错误\n");
			return 0;
		}
		p = p->next;
		i--;
	}
	q->date = x;
	q->next = p->next;
	p->next = q;
	printf("插入成功\n");
	return 1;
 }
