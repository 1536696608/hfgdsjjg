#include"SeqHead.h"
mytype GetValue(SeqList* List,int n)//得到第n个元素的值 
{
	if(n > List->len||n <= 0)
	{
		printf("erro");
		return -1;
	}
	else
	{
		return List->array[n-1];
	}
}
