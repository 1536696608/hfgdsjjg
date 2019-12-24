#ifndef SORTS_H_
#define SORTS_H_
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define ElemenType int

void PrintArray(ElemenType* A,int i);//打印数列
void qsorts(ElemenType *A,int start,int end,int len);//快速排序
void patitionmod3(ElemenType* A,int low,int high);//模三同余类
void ShellSort(ElemenType *A,int len);
void printqsorts(ElemenType* A,int start,int end,int len);//打印快速排序过程
void HeapSort(ElemenType* A,int len);//堆排序
int MergeSort(ElemenType* A,int low,int high);//归并排序
#endif
