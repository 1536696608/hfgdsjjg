#include"BTreeHead.h"
int CopyTree(Node* T1,Node** T2)
{
    if(T1 == NULL)
    {
        return 0;
    }
    (*T2) = (Node*)malloc(sizeof(Node));
    (*T2)->lchild = (*T2)->rchild = NULL;
    (*T2)->data = T1->data;
    CopyTree(T1->lchild,&((*T2)->lchild));
    CopyTree(T1->rchild,&((*T2)->rchild));
}