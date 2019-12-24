#ifndef CREATETREE_H_
#define CREATETREE_H_
//����ɭ�֣���˫�ױ�ʾ������㷨--------------------------------------------
#define MAXLEN 100
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
typedef char elementType;
   //���Ľ��ṹ
typedef struct pNode
{
	elementType data;   //���������
	int parent;         //�����ָ�루�±꣩

}PTNode;

    //˫�ױ�ʾ������ɭ�֣��ṹ
typedef struct pTree
{
	PTNode node[MAXLEN];   //�������
	int n;              //�������
}pTree;



//��ʼ����
void initialTree(pTree **T)
{
	(*T)->n=0;   //�������ʼ��Ϊ0
}

//�����Ƚ��
int getAncestor(pTree *T, elementType x)
{
	int w=0;
	elementType y;
	y=x;
	
	for(w=0;w<T->n;w++)
	{
		if(T->node[w].data==y)
		{
			w=T->node[w].parent;     //ȡ��x�ĸ����
			y=T->node[w].data;
			printf("%c\n",y);
			break;
		}
	}
	if(w>=T->n)    //x�������ϣ�����false
		return 0;
	
	             //����x�����֮����������Ƚ��
	while(w!=-1)
	{
		if(T->node[w].data==y)
		{
			w=T->node[w].parent;     //ȡ��w��˫�׽���±�
			y=T->node[w].data;
			printf("%c\n",y);
		}
		else
			w=(w+1)%T->n;
	}
	return 1;
}

//���ӽ��
void getChildren(pTree *T, elementType x)
{
	int i,w;
	for(w=0;w<T->n;w++)     //��ȡx�ڽ�������е��±�
	{
		if(T->node[w].data==x)
			break;
	}
	if(w>=T->n)  //x���ڱ���
		return;
	for(i=0;i<T->n;i++)
	{
		if(T->node[i].parent==w)   //�ҵ��ӽ�㣬��ӡ
		printf("%3c",T->node[i].data);
	}
	printf("\n");
}

//�������
int firstChild(pTree *T,int v)    //�����±�Ϊv�Ľ��ĵ�һ�����ӽ���±�
{
	int w;
	if(v==-1)
		return -1;

	for(w=0;w<T->n;w++)
	{
		if(T->node[w].parent==v)
			return w;
	}
	return -1;
}
int nextSibling(pTree *T,int v,int w)  //����v���±�λ��w֮�����һ�����ӽ���±�
{
	int i;
	for(i=w+1;i<T->n;i++)
		if(T->node[i].parent==v)
			return i;
	return -1;
}
void preOrder(pTree *T,int v)
{
	int w;
	printf("%c\n",T->node[v].data);

	w=firstChild(T,v);
	while(w!=-1)
	{

		preOrder(T,w);
		w=nextSibling(T,v,w);	
	}
}


void preTraverse(pTree *T)
{
	int i;
	int visited[MAXLEN];
	for(i=0;i<T->n;i++)
	{
		visited[i]=0;	
	}
	    //��������㣬������ɭ�֣��ж�������
	for(i=0;i<T->n;i++)
	{
		if(T->node[i].parent==-1)
			preOrder(T,i);
	}	
}

void postOrder(pTree *T,int v)
{
	int w;
	w=firstChild(T,v);
	while(w!=-1)
	{
		postOrder(T,w);
		w=nextSibling(T,v,w);	
	}
	printf("%c\n",T->node[v].data); //���ʸ����
}
void MidTraverse(pTree* T)
{
    int i;
	int visited[MAXLEN];
	for(i=0;i<T->n;i++)
	{
		visited[i]=0;	
	}
    for(i=0;i<T->n;i++)
	{
		if(T->node[i].parent==-1)
			postOrder(T,i);
	}	
}//����

void LevelOrder(pTree* T)//��α���
{
	int w,i = 0;
	int n;
	Queue* q = (Queue*)malloc(sizeof(Queue));
	queue_init(q);
	queue_push(q,T->node[0].data);
	for(i=0;i<T->n;i++)
		{
			if(T->node[i].parent==-1)
			queue_push(q,i);
		}	
	while (!queue_empty(q))
	{
		queue_pop(q,&n);
		printf("%c",T->node[n].data);
		
		for(i = 0;i < T->n;i++)
		{
			if(T->node[i].parent == n)
			{
				queue_push(q,i);
			}
		}
	}
	
}

int GetTreesHeight(pTree* T)
{
	int hight = 0;
	int w,i = 0;
	int n;
	int nlast,rlast;
	Queue* q = (Queue*)malloc(sizeof(Queue));
	queue_init(q);
	queue_push(q,T->node[0].data);
	for(i=0;i<T->n;i++)
		{
			if(T->node[i].parent==-1)
			{
				queue_push(q,i);
				nlast = i;
			}
		}
	 hight++;
	queue_pop(q,&n);	
	while (!queue_empty(q))
	{
		
		queue_pop(q,&n);
		for(i = 0;i < T->n;i++)
		{
			if(T->node[i].parent == n)
			{
				queue_push(q,i);
				if(nlast == n)
				{
					hight++;
					nlast = i;
				}
			}
		}
		
	}
	return hight;
}

int GetNodes(pTree* T)
{
	return T->n;
}

int GetLeave(pTree* T)
{
	int num = 0;
	int i;
	for(i = 0;i < T->n;i++)
	{
		if(firstChild(T,i) == -1)
		{
			num++;
		}
	}
	return num;
}
int Getdegree(pTree* T)
{
	int i;
	int nums = 0;
	for(i = 0;i < T->n;i++)
	{
		if(T->node[i].parent == -1)
		{
			nums++;
		}
	}
	return T->n - nums;
}

void preOrder2(pTree *T,int v,int level)
{
	int w;
	printf("(%c,%d)\n",T->node[v].data,level);

	w=firstChild(T,v);
	while(w!=-1)
	{

		preOrder2(T,w,level+1);
		w=nextSibling(T,v,w);	
	}
}

int OutPutTrees(pTree* T)
{
	int i;
	int visited[MAXLEN];
	for(i=0;i<T->n;i++)
	{
		visited[i]=0;	
	}
	    //��������㣬������ɭ�֣��ж�������
	for(i=0;i<T->n;i++)
	{
		if(T->node[i].parent==-1)
			preOrder2(T,i,1);
	}	
}

void PrintAsTable(pTree* T,int v)
{
	printf("%c",T->node[v].data);
	int n = firstChild(T,v);
	int m;
	if(n != -1)
	{
		
		printf("(");
		m = n;
		while (m != -1)
		{
			PrintAsTable(T,m);
			m = nextSibling(T,v,m);
			if (m != -1)
			{
				printf(",");
			}
			
		}
		//PrintAsTable(T,n);
		printf(")");
	}
}

void PrintAsTableTrees(pTree* T)
{
	int i;
	for(i=0;i<T->n;i++)
	{
		if(T->node[i].parent==-1)
			PrintAsTable(T,i);
	}	
}

void postTraverse(pTree *T)
{
	int i;
	int visited[MAXLEN];
	for(i=0;i<T->n;i++)
	{
		visited[i]=0;	
	}
	    //��������㣬������ɭ�֣��ж�������
	for(i=0;i<T->n;i++)
	{
		if(T->node[i].parent==-1)
			postOrder(T,i);
	}
}

//��ӡ��
void printTree(pTree *T)
{
	int i;
	printf("�±�\t���\t˫��\n");
	for(i=0;i<T->n;i++)
		printf("%3d%7c%7d\n",i,T->node[i].data,T->node[i].parent);
}

//˫�ױ�ʾ���塢�㷨����---------------------------------------------------------------

//�����ֵ������ʾ���塢�����㷨��ʼ---------------------------------------------------
    //����ɭ�֣��ĺ����ֵ������ʾ
typedef char elementType;

typedef struct csNode
{
	elementType data;
	struct csNode *firstChild, *nextSibling;
}csNode,*csTree;

//ɾ���ַ������ַ�������߿ո�
void strLTrim(char* str)
{
	int i,j;
	int n=0;
	n=strlen(str)+1;
	for(i=0;i<n;i++)
	{
		if(str[i]!=' ')  //�ҵ������һ���ǿո�λ��
			break;
	}
	    //�Ե�һ���ǿո��ַ�Ϊ���ַ��ƶ��ַ���
	for(j=0;j<n;j++)
	{
		str[j]=str[i];
		i++;
	}
}


//****************** �ļ�����˫�ױ�ʾ������ɭ�֣�********************//
//* �������ܣ����ı��ļ�����˫�ױ�ʾ��ͼ                            *//
//* ��ڲ���  char fileName[]�������ļ���                           *//
//* ���ڲ�����pTree &T������������                                  *//
//* �� �� ֵ��bool��true�����ɹ���false����ʧ��                     *//
//* �� �� ����CreateTreeFromFile(char fileName[], pTree &T)         *//
//* ��ע��������ʹ�õ������ļ���ʽ�Աߣ����Ӷԣ�Ϊ��������          *//
//*******************************************************************//
int CreateTreeFromFile(char fileName[], pTree **T)
{
	FILE* pFile;     //����˳�����ļ�ָ��
	char str[1000];  //��Ŷ���һ���ı����ַ���
	char strTemp[10]; //�ж��Ƿ�ע����

    int i=0,j=0;


	pFile=fopen(fileName,"r");
	if(!pFile)
	{
		printf("�����ļ�%s��ʧ�ܡ�\n",fileName);
		return 0;
	}
	
	while(fgets(str,1000,pFile)!=NULL)  //�������к�ע����
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0]=='\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //����ע����
			continue;
		else  //��ע���С��ǿ��У�����ѭ��
			break;
	}

    //ѭ��������str��Ӧ���Ѿ����ļ���ʶ���ж��ļ���ʽ
	if(strstr(str,"Tree or Forest")==NULL)
	{
		printf("���󣺴򿪵��ļ���ʽ����\n");
		fclose(pFile); //�ر��ļ�
		return 0;
	}


	//��ȡ������ݣ���str����������
	while(fgets(str,1000,pFile)!=NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0]=='\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;		
		else  //�ǿ��У�Ҳ��ע���У���ͼ�Ķ���Ԫ����
			break;
	}

	//������ݴ������Ľ������		
	char* token=strtok(str," ");
	int nNum=0;	
	while(token!=NULL)
	{
		(*T)->node[nNum].data=*token;
		(*T)->node[nNum].parent=-1;       //�����ָ���ʼ��Ϊ-1
		
		token = strtok( NULL, " ");
        
		nNum++;
	}
	
    //ѭ����ȡ�ߣ����Ӷӣ�����
	int nP;  //����������±�
	int nC;  //�ӽ�������±�

	elementType Nf,Ns; //���ӽ��Ե��������
	while(fgets(str,1000,pFile)!=NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0]=='\n')  //���У�������ȡ��һ��
			continue;
		
		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;

		char* token=strtok(str," ");  //�Կո�Ϊ�ָ������ָ�һ�����ݣ�д���ڽӾ���
		
		if(token==NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡ���ı�����ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return 0;
		}
		Nf=*token;  //��ȡ�����
		
		token = strtok( NULL, " ");  //��ȡ��һ���Ӵ������ӽ��
		if(token==NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡ���ı�����ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return 0;
		}

		Ns=*token;  //��ȡ�ߵĵڶ�����㣨�ӽ�㣩
            //ȡ�ø�����±�		
		for(nP=0;nP<nNum;nP++)
		{
			if((*T)->node[nP].data==Nf)  //�Ӷ����б��ҵ���һ������ı��
				break;
		}
           //��ȡ�ӽ��������±�		
		for(nC=0;nC<nNum;nC++)
		{
			if((*T)->node[nC].data==Ns)  //�Ӷ����б��ҵ��ڶ�������ı��
				break;
		}

		(*T)->node[nC].parent=nP;        //nC�ĸ������±�ΪnP
	}

    (*T)->n=nNum;  //���Ľ�����������������ʵ�ʴ�С

	fclose(pFile); //�ر��ļ�
	return 1;
}

//����˫�ױ�ʾ�У��±�w����һ���ֵܽ�㣬�����ֵܽ����±�
int next(pTree T,int w)  
{
	int i;
	for(i=w+1;i<T.n;i++)
	{
		if(T.node[w].parent==T.node[i].parent)
			return i;	
	}
	return -1;
}


#endif
//�ݹ鴴��һ�ú����ֵ������ʾ����
// void create(csNode *&T,pTree &T1,int v)
// {
// 	int w;
// 	T=new csNode;
// 	T->data=T1.node[v].data;
// 	T->firstChild=NULL;
// 	T->nextSibling=NULL;
// 	w=firstChild(&T1,v);  //����v�ĵ�һ�����ӽ��
// 	if(w!=-1)
// 	{
// 		create(T->firstChild,T1,w);
// 	}
	
// 	w=next(T1,v);       //����v����һ���ֵܽ��
// 	if(w!=-1)
// 	{
// 		create(T->nextSibling,T1,w);
// 	}	
// }

//��˫�ױ�ʾ������ɭ�֣����������ֵ������ʾ������ɭ�֣�
// void createCsTree(csNode *&T,pTree T1)
// {
// 	int i;
// 	//����T1�ĵ�һ�������
// 	for(i=0;i<T1.n;i++)
// 	{
// 		if(T1.node[i].parent==-1)   //�ҵ���һ�������
// 			break;		
// 	}
// 	if(i<T1.n)
// 		create(T,T1,i);
// }


// //�����ֵ������ʾ���塢�����㷨����---------------------------------------------------