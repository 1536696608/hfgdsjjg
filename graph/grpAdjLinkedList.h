//************************************************************//
//*    ͼ���ڽ������ʾ��ͷ�ļ����ļ�����GraphAdjLinkList.h  *//
//*                                                          *//
//************************************************************//
#ifndef GRPADJLINKEDLIST_H_
#define GRPADJLINKEDLIST_H_
#include "iostream"
#include<queue>
#include<stack>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;
#define INF 65535          //���������
#define MaxVerNum  100     //������󶥵����

typedef char elementType;  //����ͼ�ж������������
typedef int eInfoType;     //�������й��ڱߵ���Ϣ���������ͣ����磬��Ȩͼ�п��Ա�ʾ�ߵ�Ȩֵ  
typedef int cellType;      //�����ڽӾ�����Ԫ�ص���������
                           //����Ȩͼ��1-���ڣ��бߣ���0-�����ڣ��ޱߣ�
                           //����Ȩͼ��Ϊ�ߵ�Ȩֵ���ر��������
typedef enum{UDG, UDN, DG, DN} GraphKind;  //ö��ͼ������--����ͼ��������������ͼ��������

typedef struct eNode       //��������ṹ
{
	int adjVer;            //�ڽӶ����ַ���˴�Ϊ�����ڶ��������ţ���1��ʼ
	eInfoType eInfo;       //�������б�ʾ�ߵ������Ϣ��������Ȩֵ
	struct eNode* next;    //ָ��������е���һ�����
}EdgeNode;                 //������������

typedef struct vNode       //�������Ԫ�ؽṹ
{
	elementType data;      //���ͼ�ж��������
	EdgeNode* firstEdge;   //ָ��˶�������ĵ�һ���ߵ�ָ�룬���������ͷָ��
}VerNode;

typedef struct GraphAdjLinkList
{
	VerNode VerList[MaxVerNum+1];  //��Ŷ����˳�������0��Ԫ����
	int VerNum;                    //������
	int ArcNum;                    //�����ߣ���
	GraphKind gKind;               //ͼ������:0-����ͼ��1-��������2-����ͼ��3-������
}Graph;                            //ͼ��������

typedef struct csNode
{
	elementType data;					//������
	struct csNode *firstChild;		//����ָ��
	struct csNode *nextSibling;		//�ֵ�ָ��
}Node;

bool visited[MaxVerNum+1];  //ȫ�����飬��Ƕ����Ƿ��Ѿ������ʡ�0--δ���ʣ�1--�ѷ��ʡ�����0��Ԫ����

//******************* ����ͼ�ж���ĺ���*********************//
//* �������ܣ���ӡͼ�ж���Ԫ�أ������Ϊ�Ѿ�����            *//
//* ��ڲ���  Graph G�������ʵ�ͼ��int verID Ŀ�궥����   *//
//* ���ڲ�������                                            *//
//* �� �� ֵ����                                            *//
//* �� �� ����visit(Graph &G, int verID)                    *//
//***********************************************************//
void visit(Graph &G, int verID)
{         //�����Ŵ�1��ʼ������0��Ԫ����
	cout<<G.VerList[verID].data<<"\t";
	visited[verID]=true;
}

//*******************  ͼ�в���Ŀ�궥�� *********************//
//* �������ܣ���������Ԫ�أ���ͼ�в��Ҵ˶���Ԫ�صı��      *//
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
		if( G.VerList[i].data==v )
			return i;
	}
	return -1;
}

//��������v�ĵ�һ���ڽӶ���
int firstAdj(Graph &G, int v)
{
	EdgeNode *p;
	p=G.VerList[v].firstEdge;
	if(p)
		return p->adjVer;
	else
		return 0;
}

//��������vλ���ڽӵ�w֮�����һ���ڽӵ�
int nextAdj(Graph &G, int v, int w)
{
	EdgeNode *p;
	p=G.VerList[v].firstEdge;         //ȡ����v�ı�����ͷָ��
	while(p->next)
	{
		if(p->adjVer==w)
			return p->next->adjVer;  //����w֮����һ���ڽӵ���
		p=p->next;	
	}
	return 0;                        //δ�ҵ���һ���ڽӵ㣬����0

}


//******************** ��ӡͼ�������Ϣ *********************//
//* �������ܣ���ӡͼ�������Ϣ                              *//
//* ��ڲ���  Graph G������ӡ��ͼ                           *//
//* ���ڲ�������                                            *//
//* �� �� ֵ����                                            *//
//* �� �� ����printGraph(Graph &G)                          *//
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
	cout<<"���\t����\t������"<<endl;
    EdgeNode* p;    
	for(i=1;i<=G.VerNum;i++)
	{
		cout<<i<<"\t"<<G.VerList[i].data<<"\t";
		p=G.VerList[i].firstEdge;
		while(p!=NULL)
		{
			cout<<p->adjVer<<"\t";
			p=p->next;
		}
		cout<<endl;
	}
	cout<<endl;
	//��ӡ�ڽӾ���
	cout<<"�ڽӾ���"<<endl;
	for(i=1;i<=G.VerNum;i++)
	{   
		cout<<"\t";
		p=G.VerList[i].firstEdge;
		j=1;
		while(p!=NULL || j<=G.VerNum)
		{
			if((j<=G.VerNum) && (p!=NULL) && j==p->adjVer)  //�б�
			{
				cout<<p->eInfo<<"\t";
				j++;
				p=p->next;
			}
			else   //�ޱ�
			{
				if(G.gKind==UDN || G.gKind==DN)
					cout<<"INF"<<"\t";  //�����ޱ�ʱ��ӡȨֵΪ������á�INF����ʾ
				else
					cout<<"0"<<"\t";    //ͼ���ޱ�ʱ��0��ʾ
				j++;			
			}
			
		}
		cout<<endl;
	}
}
#endif
