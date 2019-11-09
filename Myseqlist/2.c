#include"SeqHead.h"
int Insert(SeqList* list,int n,mytype x)//插入元素到第n个，错误返回-1，成功返回1 
{
	int i;
	if(n > list->len)
	{
		printf("erro");
		return -1; 
	}
	else if(list->len == MAXLEN)
	{
		printf("erro");
		return -1;
	}
	else if(n < 0)
	{
		printf("erro");
		return -1;
	}
	else
	{
		for(i = list->len;i > (n);i--)
		{
			list->array[i] = list->array[i-1];
			
		 }
		 list->array[i] = x;
		 list->len++;
		 printf("插入成功1\n");
		 return 1; 
	}
	return 1;
 }