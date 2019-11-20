#include"BTreeHead.h"
int NumOfTwoNodes(Node* T)
{
    int r,l;

    if(T == NULL)
    {
        return 0;
    }

    if(T->lchild != NULL &&T->rchild != NULL)
    {
        return 1 + NumOfTwoNodes(T->rchild) + NumOfTwoNodes(T->lchild);
    }

    NumOfTwoNodes(T->lchild);
    NumOfTwoNodes(T->rchild);
}