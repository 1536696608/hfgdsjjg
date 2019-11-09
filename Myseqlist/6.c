#include"SeqHead.h"
SeqList* Addcommon(SeqList* A,SeqList* B)//找到递增集合AB之中的共有元素放入C 
{
	int i = 0;
	int j = 0;//存放AB长度 
	SeqList* C = (SeqList*)malloc(sizeof(SeqList));
	initialList(C);
	while(i < A->len&&j < B->len)
	{
		if(A->array[i] == B->array[j])
		{
			C->array[C->len] = A->array[i];
			C->len++;
			i++;
			j++;
		}
		else if(A->array[i] < B->array[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	 }
	 return C; 
}