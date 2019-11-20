#include"linkhead.h"
Node* Head_Creat_list()//头插
 {
 	Node* p1,*head;
 	int fal;
 	initList(&head);;
	if(head==NULL)
    	{
        	printf("分配空间失败！");
        	exit(1);
    	}
	head->next = NULL;
	printf("是否继续输入1继续0退出");
	scanf("%d",&fal);
	while(fal)
	{
		initList(&p1);
		if(p1==NULL)
    	{
        	printf("分配空间失败！");
        	exit(1);
    	}
    	printf("请输入\n");
		scanf("%d",&p1->date);
		p1->next = head->next;
		head->next = p1;
		printf("是否继续输入1继续0退出");
		scanf("%d",&fal);
	}
	return head;
  }
