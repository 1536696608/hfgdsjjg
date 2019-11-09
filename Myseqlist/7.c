#include"SeqHead.h"
int DeletRepeat(SeqList** Lis)//删除递增有序表重复元素 
{
	int i;
	SeqList* A =*Lis;
	if(A->len == 0)
	{
		printf("删除失败");
		return -1;
	 } 
	SeqList* C = (SeqList*)malloc(sizeof(SeqList));//保存临时数据
	
	C->array[0] = A->array[0];
	C->len = 1;
	for(i = 1;i < A->len;i++)
	{
		if(C->array[C->len - 1] != A->array[i])
		{
			C->array[C->len] = A->array[i];
			C->len++;
		}
	}
	A->len = C->len;
	for(i = 0;i < A->len;i++)//将C复制回A 
	{
		A->array[i] =  C->array[i];
	}
	printf("删除成功");
	
	return 1;
}