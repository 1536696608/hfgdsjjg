#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#ifndef _LINKHEAD_H_
#define _LINKHEAD_H_

#define mytype int

typedef struct Node
{
	mytype date;
	struct Node* next;
}Node;
Node* CreateRandList(int n);//生成随机顺序链表
void initList(Node** head);//(初始化头指针）
void Travel(Node* head);//（遍历）
//<1>尾插
Node* Tail_Creat_list();
//<2>头插
Node* Head_Creat_list();
//<3>销毁
void DestoryList(Node** head);
//<4>求链表长度
int Len_List(Node* head);
// <5>查找指定元素位置
int Find_Index(Node* head,int i);
// <6>插入元素到指定位置
int Insert(Node* head);
// <7>查找指定元素结点
Node* Find_element(Node* head,mytype x);
// <8>删除元素
int Delet(Node* head);
// <9>递增数列插入元素
int SeqLinkListInsert(Node* head);
// <10>将链表分为奇数链表与偶数链表
void SplitList(Node* head,Node** A,Node** B);
// <11>两个递增有序数列的集合
Node* AddCommonToList(Node* list1,Node* list2);
// <12>删除递增有序链表重复元素
void DeletR(Node* head);
// <13>合并有序链表
int UnitList(Node** lsa,Node* lsb);
#endif
