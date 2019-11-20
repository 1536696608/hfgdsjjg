#include"linkhead.h"


void initList(Node** head)
{
	*head = (Node*)malloc(sizeof(Node));
	(*head)->next == NULL;
}
void Travel(Node* head)
{
	Node *p = head->next;
	while(p != NULL)
	{
		printf("%d\n",p->date);
		p = p->next;
	}
}
