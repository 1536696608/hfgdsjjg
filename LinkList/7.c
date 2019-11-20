#include"linkhead.h"
Node* Find_element(Node* head,mytype x)//寻找元素
 {
	 int l = 0;
 	Node* p = head->next;
 	while(p != NULL)
 	{
 		if(p->date == x)
 		{
			printf("在%d位置处\n",l);
 			return p;
		 }
		 p = p->next;
		 l++;
	 }
	 printf("没找到\n");
	 return NULL;
  }
