#ifndef SORTS_H_
#define SORTS_H_
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define ElemenType int

void PrintArray(ElemenType* A,int i);//��ӡ����
void qsorts(ElemenType *A,int start,int end,int len);//��������
void patitionmod3(ElemenType* A,int low,int high);//ģ��ͬ����
void ShellSort(ElemenType *A,int len);
void printqsorts(ElemenType* A,int start,int end,int len);//��ӡ�����������
void HeapSort(ElemenType* A,int len);//������
int MergeSort(ElemenType* A,int low,int high);//�鲢����
#endif
