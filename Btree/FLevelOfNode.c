#include"BTreeHead.h"
int FindNode(Node* T,int *flag,int level,ElemType item)
{
    if(T == NULL)
    {
        return 0;
    }
    if(T->data == item)
    {
        printf("find it\n");
        printf("its level is %d",level);
        *flag = 1;
        return 1;
    }
    FindNode(T->lchild,flag,level+1,item);
    FindNode(T->rchild,flag,level+1,item);
}