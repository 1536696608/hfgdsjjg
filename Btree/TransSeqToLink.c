#include"BTreeHead.h"
int TransToLinkTree(Node* T,ElemType *array,int now,int len)
{
    if(now > len)
    {
        return 0;
    }
    if(array[now] == '/')     //数组中表示空的符号
    {
        return 0;
    }
    T = (Node*)malloc(sizeof(Node));
    T->data = array[now];
    T->lchild = T->rchild = NULL;
    TransToLinkTree(T->lchild,array,2*now,len);
    TransToLinkTree(T->rchild,array,2*now+1,len);
}