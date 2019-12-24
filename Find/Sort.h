#ifndef SORT_H_
#define SORT_H_
#include<stdio.h>
#include<stdlib.h>
#define Mytype int
#define ElemenType Node*

typedef struct Sort
{
    Mytype data;
    struct Sort* lchild;
    struct Sort* rchild;
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
void init(Node** T);
int Binarysearch(Mytype* A,int len,Mytype x);//二分查找
int BinarySortingTree(Node** T,Mytype x);//插入二叉排序树
Node* SearchSortingTree(Node* T,Mytype x,int level,int* flag);//寻找二叉排序树中节点
Node* DeleteBST(Node *b, int x);//删除节点
Node* sortedArrayToBST(Mytype A[],int start,int end);//有序数组构造平衡二叉树
int LevelPrint(Node* T,LinkQueue** q);//层次打印
void initLinkQueue(LinkQueue** q);//初始化
int MidTravel(Node* T);//中序遍历
#endif