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
void init(SeqStack* s);//初始化
void initL(LinkStack** l);//初始化链栈
void PushStack(SeqStack*s,Elemtype x);//顺序栈入栈
void PushStackL(LinkStack*s,Elemtype x);//链栈入栈
Elemtype PopStack(SeqStack*s);//顺序栈出栈
Elemtype PopStackL(LinkStack*s);//链栈出栈
int IsEmpty(SeqStack* s);//判断顺序栈是否为空
int IsEmptyL(LinkStack* s);//判断链栈是否为空
void Turn10to16(int i);//顺序栈将十进制转化为十六进制
void Turn10to16L(int i);//链栈将十进制转化为十六进制
int IsMatch(char* w);//顺序栈判断符号是否匹配，匹配返回1，否则返回0
int IsMatchL(char* w);//链栈判断符号是否匹配，匹配返回1，否则返回0
int IsRight(char* c);//3.4.1
#endif