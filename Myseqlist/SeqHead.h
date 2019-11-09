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

void createList(SeqList** L);//创建顺序表
void initialList(SeqList* L);//初始化
void Travel(SeqList* A);//遍历
mytype GetValue(SeqList* List,int n);//得到第n个元素的值 
int Insert(SeqList* list, int n, mytype x);
int Delet(SeqList* list, int n);//删除第i元素 
int InsertSeq(SeqList* slist,mytype x);//递增数列添加元素 
 void* SplitJandO(SeqList* list);//拆分成奇数与偶数
SeqList* Addcommon(SeqList* A,SeqList* B);//找到递增集合AB之中的共有元素放入C 
int DeletRepeat(SeqList** Lis);//删除递增有序表重复元素 

#endif
