#include"linkhead.h"
int Delet(Node* head)//É¾³ıÔªËØ
 {
 	int i;
 	Node* p = head;
 	Node* q;
 	printf("ÇëÊäÈëÉ¾³ıÎ»ÖÃ\n");
	scanf("%d",&i);
 	if(i < 0)
 	{
 		printf("ÊäÈë´íÎó");
 		return -1;
	 }
    else if(i >= Len_List(head))
    {
        printf("ÊäÈë´íÎó");
 		return -1;
    }
	 while(i > 0)
	{
		if(p->next == NULL)
		{
			printf("É¾³ı´íÎó\n");
			return 0;
		}
		p = p->next;
		i--;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	printf("É¾³ı³É¹¦\n");
	return 1;
}
