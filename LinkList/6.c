#include"linkhead.h"
int Insert(Node* head)//����Ԫ��
{
	int x,i;
	Node* p = head;
	Node* q = (Node*)malloc(sizeof(Node));
	printf("���������Ԫ�ز���λ��\n");
	scanf("%d%d",&x,&i);
	if(q==NULL)
    	{
        	printf("����ռ�ʧ�ܣ�");
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
			printf("�������\n");
			return 0;
		}
		p = p->next;
		i--;
	}
	q->date = x;
	q->next = p->next;
	p->next = q;
	printf("����ɹ�\n");
	return 1;
 }
