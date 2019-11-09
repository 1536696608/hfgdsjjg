#include"SeqHead.h"
int Delet(SeqList* list, int n)//删除第i元素 
{
	int i;
	if(n > list->len||n <= 0)
	{
		printf("erro");
		return -1;
	}
	else
	{
		for(i = n;i < list->len;i++)
		{
			list->array[i-1] = list->array[i];
		}
	}
	list->len--;
	printf("删除成功\n");
    return 1;
}