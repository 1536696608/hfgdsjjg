#include<stdio.h>
#include<stdlib.h>
#ifndef _SEQHEAD_H_
#define _SEQHEAD_H_
#define ERROR 0
#define mytype int
#define MAXLEN 100
typedef struct SeqList{
	int len;
	mytype array[MAXLEN];
}SeqList;

void createList(SeqList** L);//����˳���
void initialList(SeqList* L);//��ʼ��
void Travel(SeqList* A);//����
mytype GetValue(SeqList* List,int n);//�õ���n��Ԫ�ص�ֵ 
int Insert(SeqList* list, int n, mytype x);
int Delet(SeqList* list, int n);//ɾ����iԪ�� 
int InsertSeq(SeqList* slist,mytype x);//�����������Ԫ�� 
 void* SplitJandO(SeqList* list);//��ֳ�������ż��
SeqList* Addcommon(SeqList* A,SeqList* B);//�ҵ���������AB֮�еĹ���Ԫ�ط���C 
int DeletRepeat(SeqList** Lis);//ɾ������������ظ�Ԫ�� 

#endif
