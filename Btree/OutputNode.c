#include"BTreeHead.h"
int PrintNode(Node* T,int deep)
{
    if(T == NULL)
    {
        return 0;
    }
    
    PrintNode(T->lchild,deep+1);
    printf("node=%c,deep=%d\n",T->data,deep);
    PrintNode(T->rchild,deep+1);
}