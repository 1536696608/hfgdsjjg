#include"BTreeHead.h"
int GetNodeFBC(Node* T,Node* Pa,char elem,int *flag)
{
    
    if(T == NULL)
    {
        
        return 0;
    }
    if(T->data == elem)
    {   
        printf("Parents is %c \n",Pa->data);
        if(Pa == T)
        {
            printf("   \n");
        }
        else if (Pa->lchild != T&&Pa->lchild != NULL)
        {
            printf("left brother is %c\n",Pa->lchild->data);
        }
        else if (Pa->rchild != T&&Pa->rchild != NULL)
        {
            printf("right brother is %c\n",Pa->rchild->data);
        }
        if(T->lchild)
        {
            printf("lelf child is %c\n",T->lchild->data);
        }
        if(T->rchild)
        {
            printf("right child is %c\n",T->rchild->data);
        }
        *flag = 1;
        return 1;
    }
    GetNodeFBC(T->lchild,T,elem,flag);
    GetNodeFBC(T->rchild,T,elem,flag);
}