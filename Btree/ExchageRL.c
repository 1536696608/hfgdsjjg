#include"BTreeHead.h"
int ExchangeRL(Node* T)
{
    if(T == NULL)
    {
        return 0;
    }
    Node* tem = T->lchild;
    T->lchild = T->rchild;
    T->rchild = tem;
    ExchangeRL(T->lchild);
    ExchangeRL(T->rchild);
}