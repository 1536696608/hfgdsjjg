#include"Sort.h"
int DeletNode(Node** T,Mytype x)
{
    int flag = 1;
    Node* dnode = SearchSortingTree(*T,x,0,&flag);
    Node* tem = dnode;
	printf("flag = %d\n",flag);
    if(flag != -1)
    {
        printf("没找到该值\n");
        return -1;
    }
    Node* q,* s;
    //叶子结点的情况包含在只有左子树和只有右子树的情况里了
    //只有左子树
	if ((dnode)->rchild == NULL)
	{
		q = dnode;
		dnode = (dnode)->lchild;
		free(q);
	}
    //只有右子树
	else if ((dnode)->lchild == NULL)
	{
		q = dnode;
		dnode = (dnode)->rchild;
		free(q);
	}
    //有左右子树
    //该方法是利用直接前驱替换
	else
	{
		//让q=直接前驱的双亲
		q = dnode;
		//寻找待删结点的直接前驱
		s = (dnode)->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		//将待删数据替换为直接前驱的数据
		(dnode)->data = s->data;
		if (q != dnode)
		{
			//将直接前驱的左子树接到直接前驱的双亲
			q->rchild = s->lchild;
		}
		else
		{
			//如果直接前驱就是待删数据结点的左子树
			q->lchild = s->lchild;
		}
		//释放直接前驱
		free(s);
	}
}