#include"SeqHead.h"
// #include"2.c"
int InsertSeq(SeqList* slist,mytype x)//递增数列添加元素 
{
	int n;//找到插入位置
	for(n = 0;n < slist->len;n++)
	{
		if(slist->array[n] > x)
		{
			break;
		}
	 }
	return Insert(slist,n,x);//调用插入函数 I 
}