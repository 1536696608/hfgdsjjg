#include"linkhead.h"
Node* Find_element(Node* head,mytype x)//Ѱ��Ԫ��
 {
	 int l = 0;
 	Node* p = head->next;
 	while(p != NULL)
 	{
 		if(p->date == x)
 		{
			printf("��%dλ�ô�\n",l);
 			return p;
		 }
		 p = p->next;
		 l++;
	 }
	 printf("û�ҵ�\n");
	 return NULL;
  }
