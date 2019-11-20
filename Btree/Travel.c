#include"BTreeHead.h"
int PreTravel(Node* T)
{
    
    if(T == NULL)
    {
        
        return 1;
    }
    else
    {
        
        printf("%c",T->data);
        PreTravel(T->lchild);
        PreTravel(T->rchild);
    }
    
}

int MidTravel(Node* T)
{
    
    if(T == NULL)
    {
        
        return 1;
    }
    else
    {
        
        PreTravel(T->lchild);
        printf("%c",T->data);
        PreTravel(T->rchild);
    }
    
}

int TailTravel(Node* T)
{
    
    if(T == NULL)
    {
        
        return 1;
    }
    else
    {
        
        PreTravel(T->lchild);
        PreTravel(T->rchild);
        printf("%c",T->data);
    }
    
}