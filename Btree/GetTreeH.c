#include"BTreeHead.h"
int MAX(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
    
}
int GetHeight(Node* T)
{
    int l,r;
    if(T == NULL)
    {
        return 0;
    }
   
    l = GetHeight(T->lchild);
    
    
    r = GetHeight(T->rchild);

    return MAX(r,l)+1;
}