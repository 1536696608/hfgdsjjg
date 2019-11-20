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

void initSeqQueue(SeqQueue* s);//��ʼ��˳�����
int SeqIsEmpty(SeqQueue* s);//�ж�˳������Ƿ�Ϊ��
int SeqIsFull(SeqQueue* s);//�ж϶����Ƿ�������������1�����򷵻�0;
int inSeqQueue(SeqQueue* s,ElemenType x);//˳��������
ElemenType outSeqQueue(SeqQueue* s);//˳����г���
int SeqGetLen(SeqQueue* s);//���г���
ElemenType SeqGetFront(SeqQueue* s);//��ͷԪ��
void initLinkQueue(LinkQueue** q);//��ʼ��������
int LinkIsEmpty(LinkQueue *q);//�ж��������Ƿ�Ϊ��
int LinkIsFull(LinkQueue* q);//�ж��Ƿ���
int inLinkQueue(LinkQueue* q,ElemenType x);//��������
ElemenType outLinkQueue(LinkQueue* q);//��������
ElemenType LinkGetFristX(LinkQueue* q);//�õ���ͷԪ��
int LinkGetLen(LinkQueue* q);//���ض��г���
#endif 