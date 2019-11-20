#include"BTreeHead.h"
int PrintLeavePath(Node* T,SeqStack* s)
{
    if (T == NULL)
    {
        return 0;
    }
    PushStack(s,T->data);
    if(T->rchild == NULL && T->lchild == NULL)
    {
        PrintPath(s);
        printf("\n");
    }
    PrintLeavePath(T->lchild,s);
    PrintLeavePath(T->rchild,s);
    PopStack(s);
}