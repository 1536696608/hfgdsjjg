#include"Sort.h"
int DeletNode(Node** T,Mytype x)
{
    int flag = 1;
    Node* dnode = SearchSortingTree(*T,x,0,&flag);
    Node* tem = dnode;
	printf("flag = %d\n",flag);
    if(flag != -1)
    {
        printf("û�ҵ���ֵ\n");
        return -1;
    }
    Node* q,* s;
    //Ҷ�ӽ������������ֻ����������ֻ�����������������
    //ֻ��������
	if ((dnode)->rchild == NULL)
	{
		q = dnode;
		dnode = (dnode)->lchild;
		free(q);
	}
    //ֻ��������
	else if ((dnode)->lchild == NULL)
	{
		q = dnode;
		dnode = (dnode)->rchild;
		free(q);
	}
    //����������
    //�÷���������ֱ��ǰ���滻
	else
	{
		//��q=ֱ��ǰ����˫��
		q = dnode;
		//Ѱ�Ҵ�ɾ����ֱ��ǰ��
		s = (dnode)->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		//����ɾ�����滻Ϊֱ��ǰ��������
		(dnode)->data = s->data;
		if (q != dnode)
		{
			//��ֱ��ǰ�����������ӵ�ֱ��ǰ����˫��
			q->rchild = s->lchild;
		}
		else
		{
			//���ֱ��ǰ�����Ǵ�ɾ���ݽ���������
			q->lchild = s->lchild;
		}
		//�ͷ�ֱ��ǰ��
		free(s);
	}
}