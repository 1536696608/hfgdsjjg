#include"linkhead.h"
int Delet(Node* head)//ɾ��Ԫ��
 {
 	int i;
 	Node* p = head;
 	Node* q;
 	printf("������ɾ��λ��\n");
	scanf("%d",&i);
 	if(i < 0)
 	{
 		printf("�������");
 		return -1;
	 }
    else if(i >= Len_List(head))
    {
        printf("�������");
 		return -1;
    }
	 while(i > 0)
	{
		if(p->next == NULL)
		{
			printf("ɾ������\n");
			return 0;
		}
		p = p->next;
		i--;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	printf("ɾ���ɹ�\n");
	return 1;
}
