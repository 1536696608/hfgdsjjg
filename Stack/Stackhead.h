#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef _STACKHEAD_H_
#define _STACKHEAD_H_
#define MAXLEN 50
#define Elemtype int
typedef struct SeqStack
{
   int top;
   int base[MAXLEN];
}SeqStack;
typedef struct LinkStack
{
   int data;
   struct LinkStack* next;
}LinkStack;
void init(SeqStack* s);//��ʼ��
void initL(LinkStack** l);//��ʼ����ջ
void PushStack(SeqStack*s,Elemtype x);//˳��ջ��ջ
void PushStackL(LinkStack*s,Elemtype x);//��ջ��ջ
Elemtype PopStack(SeqStack*s);//˳��ջ��ջ
Elemtype PopStackL(LinkStack*s);//��ջ��ջ
int IsEmpty(SeqStack* s);//�ж�˳��ջ�Ƿ�Ϊ��
int IsEmptyL(LinkStack* s);//�ж���ջ�Ƿ�Ϊ��
void Turn10to16(int i);//˳��ջ��ʮ����ת��Ϊʮ������
void Turn10to16L(int i);//��ջ��ʮ����ת��Ϊʮ������
int IsMatch(char* w);//˳��ջ�жϷ����Ƿ�ƥ�䣬ƥ�䷵��1�����򷵻�0
int IsMatchL(char* w);//��ջ�жϷ����Ƿ�ƥ�䣬ƥ�䷵��1�����򷵻�0
int IsRight(char* c);//3.4.1
#endif