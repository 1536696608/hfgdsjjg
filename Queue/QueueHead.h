#include<stdlib.h>
#include<stdio.h>
#ifndef _QUEUEHEAD_H_
#define _QUEUEHEAD_H
#define ElemenType int  
#define maxlen 100
typedef struct SeqQueue
{
    ElemenType Queue[maxlen];
    int roar,fron;
}SeqQueue;

typedef struct Node
{
    ElemenType data;
    struct Node*next;
}Node;

typedef struct LinkQueue
{
    Node* front;
    Node* rear;
}LinkQueue;

void initSeqQueue(SeqQueue* s);//初始化顺序队列
int SeqIsEmpty(SeqQueue* s);//判断顺序队列是否为空
int SeqIsFull(SeqQueue* s);//判断队列是否满，队满返回1，否则返回0;
int inSeqQueue(SeqQueue* s,ElemenType x);//顺序队列入队
ElemenType outSeqQueue(SeqQueue* s);//顺序队列出队
int SeqGetLen(SeqQueue* s);//队列长度
ElemenType SeqGetFront(SeqQueue* s);//队头元素
void initLinkQueue(LinkQueue** q);//初始化链队列
int LinkIsEmpty(LinkQueue *q);//判断链队列是否为空
int LinkIsFull(LinkQueue* q);//判断是否满
int inLinkQueue(LinkQueue* q,ElemenType x);//入链队列
ElemenType outLinkQueue(LinkQueue* q);//出链队列
ElemenType LinkGetFristX(LinkQueue* q);//得到队头元素
int LinkGetLen(LinkQueue* q);//返回队列长度
#endif 