#include"linkhead.h"
Node* Head_Creat_list()//ͷ��
 {
 	Node* p1,*head;
 	int fal;
 	initList(&head);;
	if(head==NULL)
    	{
        	printf("����ռ�ʧ�ܣ�");
        	exit(1);
    	}
	head->next = NULL;
	printf("�Ƿ��������1����0�˳�");
	scanf("%d",&fal);
	while(fal)
	{
		initList(&p1);
		if(p1==NULL)
    	{
        	printf("����ռ�ʧ�ܣ�");
        	exit(1);
    	}
    	printf("������\n");
		scanf("%d",&p1->date);
		p1->next = head->next;
		head->next = p1;
		printf("�Ƿ��������1����0�˳�");
		scanf("%d",&fal);
	}
	return head;
  }
