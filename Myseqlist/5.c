#include"SeqHead.h"
void* SplitJandO(SeqList* list)//拆分成奇数与偶数
{
	int i;
	SeqList* A;//奇数集 
	SeqList* B;//偶数集 
	createList(&A);
	createList(&B);
	initialList(A);//初始化 
	initialList(B);
	for(i = 0;i < list->len;i++)
	{
		if(list->array[i] % 2 == 0)
		{
			B->array[B->len] = list->array[i];
			B->len++; 
		}
		else
		{
			A->array[A->len] = list->array[i];
			A->len++;
		}
	}
	printf("奇数集为:\n");
	Travel(A);
	printf("偶数集为:\n"); 
	Travel(B);
 }
