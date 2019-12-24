//************************************************************//
//*    ͼ���ڽӾ���洢��ͷ�ļ����ļ�����grpAdjMatrix.h      *//
//*                                                          *//
//************************************************************//
#ifndef GREADJMATRIX_H_
#define GREADJMATRIX_H_
#include "iostream"
#include<queue>
#include<stack>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define INF 65535          //���������
#define MaxVerNum  100     //������󶥵����
using namespace std;
//typedef int elementType;  //����ͼ�ж������������
typedef char elementType;  //����ͼ�ж������������
typedef int cellType;      //�����ڽӾ�����Ԫ�ص���������
                           //����Ȩͼ��1-���ڣ��бߣ���0-�����ڣ��ޱߣ�
                           //����Ȩͼ��Ϊ�ߵ�Ȩֵ���ر��������
                           //ö��ͼ������--����ͼ(UDG)��������(UDN)������ͼ(DG)��������(DN)
typedef enum{UDG, UDN, DG, DN} GraphKind;  


typedef struct csNode
{
	elementType data;					//������
	struct csNode *firstChild;		//����ָ��
	struct csNode *nextSibling;		//�ֵ�ָ��
}Node;


bool visited[MaxVerNum+1];  //ȫ�����飬��Ƕ����Ƿ��Ѿ����ʣ�visited[0]��Ԫ����

//****************************************************//
//*  �����ڽӾ����ʾ��ͼ�ṹ��5��������ɣ�         *//
//*      data[]���鱣��ͼ�ж�������Ԫ��              *//
//*      AdjMatrix[][]�ڽӾ���                       *//
//*      VerNum�������                              *//
//*      ArcNum�ߣ���������                          *//
//*      gKindö��ͼ������                           *//
//*  ���ǵ����Ƶ�ͳһ�ԣ�ͼ�������ƶ���ΪGraph       *//
//****************************************************//
typedef struct GraphAdjMatrix
{
	elementType Data[MaxVerNum+1];                 //�������飬��Ŷ���Ԫ�ص�ֵ��Data[0]��Ԫ����
	cellType AdjMatrix[MaxVerNum+1][MaxVerNum+1];  //�ڽӾ��������±�Ϊ0��Ԫ���ã���AdjMatrix[1][1]��Ԫ��ʼ
	int VerNum;       //������
	int ArcNum;       //�����ߣ���
	GraphKind gKind;  //ͼ������:0-����ͼ��1-��������2-����ͼ��3-������
} Graph;  //ͼ��������

//******************* ����ͼ�ж���ĺ���*********************//
//* �������ܣ���ӡͼ�ж���Ԫ�أ������Ϊ�Ѿ�����            *//
//* ��ڲ���  Graph G�������ʵ�ͼ��int verID Ŀ�궥����   *//
//* ���ڲ�������                                            *//
//* �� �� ֵ����                                            *//
//* �� �� ����visit(Graph &G, int verID)                    *//
//***********************************************************//
void visit(Graph &G, int verID)
{        //�����Ŵ�1��ʼ������0��Ԫ����
	cout<<G.Data[verID]<<"\t";
	visited[verID]=true;
}

//*******************  ͼ�в���Ŀ�궥�� *********************//
//* �������ܣ���������Ԫ�أ���ͼ�в��Ҵ˶���Ԫ��            *//
//* ��ڲ���  Graph G�������ʵ�ͼ��elementType v Ŀ�궥��   *//
//* ���ڲ�������                                            *//
//* �� �� ֵ��int�����Ŀ�궥����ڣ����ض����ţ�         *//
//*                �����Ŵ�1��ʼ�����򷵻�-1              *//
//* �� �� ����visit(Graph &G, int verID)                    *//
//***********************************************************//
int LocateVertex(Graph &G, elementType v)
{
	for(int i=1;i<=G.VerNum;i++)
	{
		if( G.Data[i]==v )
			return i;
	}
	return -1;
}
//�󶥵�v�ĵ�һ���ڽӵ�
int firstAdj(Graph &G,int v)
{
	int w;
	for(w=1;w<=G.VerNum;w++)
	{
		if((G.AdjMatrix[v][w]>=1)   &&
		   (G.AdjMatrix[v][w])<INF)
		   return w;    //���ص�һ���ڽӵ���
	}
	 return 0;          //δ�ҵ��ڽӵ㣬����0
}
//�󶥵�v��λ���ڽӵ�w�����һ���ڽӵ�
int nextAdj(Graph &G,int v,int w)
{
	int k;
	for(k=w+1;k<=G.VerNum;k++)
	{
		if((G.AdjMatrix[v][k]>=1)   &&
		   (G.AdjMatrix[v][k])<INF)
		   return k;    //����v��λ��w֮�����һ���ڽӵ�k
	}
	return 0;           //��������һ���ڽӵ㣬����0
}



//******************** ��ӡͼ�������Ϣ *********************//
//* �������ܣ���ӡͼ�������Ϣ                              *//
//* ��ڲ�����Graph G������ӡ��ͼ                           *//
//* ���ڲ�������                                            *//
//* �� �� ֵ����                                            *//
//* �� �� ����GraphPrint(Graph &G)                          *//
//***********************************************************//
void printGraph(Graph &G)
{
	int i=0,j=0;
	//��ӡͼ������
	switch(G.gKind)
	{
	case UDG:
		cout<<"ͼ���ͣ�����ͼ"<<endl;
		break;
	case UDN:
		cout<<"ͼ���ͣ�������"<<endl;
		break;
	case DG:
  	    cout<<"ͼ���ͣ�����ͼ"<<endl;
		break;
	case DN:
		cout<<"ͼ���ͣ�������"<<endl;
		break;
	default:
		cout<<"ͼ���ʹ���"<<endl;
		break;
	}
	//��ӡͼ�Ķ�����
	cout<<"��������"<<G.VerNum<<endl;
	//��ӡͼ�ı���
	cout<<"��  ����"<<G.ArcNum<<endl;
	//��ӡ���㼰����
	cout<<"��  �ţ�";
	for(i=1;i<=G.VerNum;i++)
	{
		cout<<i<<"\t";
	}
	cout<<endl;
	cout<<"��  �㣺";
	for(i=1;i<=G.VerNum;i++)
	{
		cout<<G.Data[i]<<"\t";
	}
	cout<<endl;

	//��ӡ�ڽӾ���
	cout<<"ͼ���ڽӾ���"<<endl;
	for(i=1;i<=G.VerNum;i++)
	{   
		cout<<"\t";
		for(j=1;j<=G.VerNum;j++)
		{
			if((G.gKind==UDN || G.gKind==DN) && G.AdjMatrix[i][j]==INF)
				cout<<"INF"<<"\t";  //���������ʱ����ӡ��INF����ʾ
			else
				cout<<G.AdjMatrix[i][j]<<"\t";
		}
		cout<<endl;
	}

}
#endif
