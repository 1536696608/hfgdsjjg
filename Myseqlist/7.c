#include"SeqHead.h"
int DeletRepeat(SeqList** Lis)//ɾ������������ظ�Ԫ�� 
{
	int i;
	SeqList* A =*Lis;
	if(A->len == 0)
	{
		printf("ɾ��ʧ��");
		return -1;
	 } 
	SeqList* C = (SeqList*)malloc(sizeof(SeqList));//������ʱ����
	
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
	for(i = 0;i < A->len;i++)//��C���ƻ�A 
	{
		A->array[i] =  C->array[i];
	}
	printf("ɾ���ɹ�");
	
	return 1;
}