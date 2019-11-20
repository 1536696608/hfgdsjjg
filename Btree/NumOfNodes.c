#include"BTreeHead.h"
int NumNodes(Node* T)
{
    if(T == NULL)
    {
        return 0;
    }
    return  NumNodes(T->lchild) + NumNodes(T->rchild)+1;
}

int LevelNodes(Node* T)
{
    if(T == NULL)
    {
        return 0;
    }
    if(T->lchild == NULL&&T->rchild == NULL)
    {
        return 1;
    }
    return LevelNodes(T->lchild) + LevelNodes(T->rchild);
}