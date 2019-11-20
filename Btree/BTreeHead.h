#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef _BTREEHEAD_H_
#define _BTREEHEAD_H_
#define ElemType char
#define MAXLEN 50
#define Elemtype char
#define ElemenType Node*
typedef struct SeqStack//栈结构
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

int ReadFileToArray(char* file,ElemType tem[100][3]);//将文件数据读入数组中
int CreateTreeFromFile(Node** node,ElemType tem[100][3],int *now,int size);//从数组中创建树
int PreTravel(Node* T);//先序遍历
int MidTravel(Node* T);//中序遍历
int TailTravel(Node* T);//后序遍历
int PrintNode(Node* T,int deep);//输出结点及其层次
int GetHeight(Node* T);//输出树的高度
int NumNodes(Node* T);//得到树的结点数
int LevelNodes(Node* T);//树的叶子结点数
int NumOfTwoNodes(Node* T);//树的度为二的结点
int GetNodeFBC(Node* T,Node* Pa,char elem,int *flag);//查找element元素，并输出它的父节点，子节点，兄弟节点
int FindNode(Node* T,int *flag,int level,ElemType item);//查找元素，并输出层次;

int ExchangeRL(Node* T);//交换左右子树的值
int CopyTree(Node* T1,Node** T2);//复制T1树给T2
int PrintLeavePath(Node* T,SeqStack* s);//打印路径叶子到跟的路径
int LevelPrint(Node* T,LinkQueue** q);//层次打印二叉树
int CommonAncestor(Node* T,ElemType node1,ElemType node2);//找到祖先节点
int PrintLongPath(Node* T,SeqStack* s,SeqStack* save);//打印二叉树最长路径



void PushStack(SeqStack*s,Elemtype x);//顺序栈入栈
Elemtype PopStack(SeqStack*s);//顺序栈出栈
void init(SeqStack* s);//初始化
void PrintPath(SeqStack* s);//打印栈中所有元素

void initLinkQueue(LinkQueue** q);//队列
int LinkIsFull(LinkQueue* q);
int LinkIsEmpty(LinkQueue *q);
int inLinkQueue(LinkQueue* q,ElemenType x);
ElemenType outLinkQueue(LinkQueue* q);

#endif