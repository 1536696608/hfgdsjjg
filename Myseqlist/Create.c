#include"SeqHead.h"
void createList(SeqList** L)
{
	*L = (SeqList*)malloc(sizeof(SeqList));
}
void initialList(SeqList* L)
{
	L->len = 0;
}

void Travel(SeqList* A)
{
	SeqList *q = A;
	int i;
	for(i = 0;i < A->len;i++)
	{
		printf("%4d",A->array[i]);
	}
}