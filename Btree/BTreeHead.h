#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef _BTREEHEAD_H_
#define _BTREEHEAD_H_
#define ElemType char
#define MAXLEN 50
#define Elemtype char
#define ElemenType Node*
typedef struct SeqStack//ջ�ṹ
{
   int top;
   int base[MAXLEN];
}SeqStack;


typedef struct Node
{
    ElemType data;
    struct Node* lchild;
    struct Node* rchild;
}Node;

typedef struct node
{
    ElemenType data;
    struct node*next;
}Nodel;

typedef struct LinkQueue
{
    Nodel* front;
    Nodel* rear;
}LinkQueue;

int ReadFileToArray(char* file,ElemType tem[100][3]);//���ļ����ݶ���������
int CreateTreeFromFile(Node** node,ElemType tem[100][3],int *now,int size);//�������д�����
int PreTravel(Node* T);//�������
int MidTravel(Node* T);//�������
int TailTravel(Node* T);//�������
int PrintNode(Node* T,int deep);//�����㼰����
int GetHeight(Node* T);//������ĸ߶�
int NumNodes(Node* T);//�õ����Ľ����
int LevelNodes(Node* T);//����Ҷ�ӽ����
int NumOfTwoNodes(Node* T);//���Ķ�Ϊ���Ľ��
int GetNodeFBC(Node* T,Node* Pa,char elem,int *flag);//����elementԪ�أ���������ĸ��ڵ㣬�ӽڵ㣬�ֵܽڵ�
int FindNode(Node* T,int *flag,int level,ElemType item);//����Ԫ�أ���������;

int ExchangeRL(Node* T);//��������������ֵ
int CopyTree(Node* T1,Node** T2);//����T1����T2
int PrintLeavePath(Node* T,SeqStack* s);//��ӡ·��Ҷ�ӵ�����·��
int LevelPrint(Node* T,LinkQueue** q);//��δ�ӡ������
int CommonAncestor(Node* T,ElemType node1,ElemType node2);//�ҵ����Ƚڵ�
int PrintLongPath(Node* T,SeqStack* s,SeqStack* save);//��ӡ�������·��



void PushStack(SeqStack*s,Elemtype x);//˳��ջ��ջ
Elemtype PopStack(SeqStack*s);//˳��ջ��ջ
void init(SeqStack* s);//��ʼ��
void PrintPath(SeqStack* s);//��ӡջ������Ԫ��

void initLinkQueue(LinkQueue** q);//����
int LinkIsFull(LinkQueue* q);
int LinkIsEmpty(LinkQueue *q);
int inLinkQueue(LinkQueue* q,ElemenType x);
ElemenType outLinkQueue(LinkQueue* q);

#endif