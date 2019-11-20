#include"BTreeHead.h"
int NodePath(Node* T,char c,SeqStack* s)
{
    if(T == NULL)
    {
        return 0;
    }
    PushStack(s,T->data);
    if(T->data == c)
    {
        PrintPath(s);
        printf("\n");
        return 1;
    }
    if (NodePath(T->lchild,c,s))
    {
        return 1;
    }
    if(NodePath(T->rchild,c,s))
    {
        return 1;
    }
    PopStack(s);
    return 0;
}

int CommonAncestor(Node* T,ElemType node1,ElemType node2)
{
    ElemType t1,t2,t3;
    SeqStack* s1 = (SeqStack*)malloc(sizeof(SeqStack));
    SeqStack* s2 = (SeqStack*)malloc(sizeof(SeqStack));
    init(s1);
    init(s2);
    NodePath(T,node1,s1);
    NodePath(T,node2,s2);
    t1 = PopStack(s1);
    t2 = PopStack(s2);
    t3 = t1;
    if(t1 == t2)
    {
        printf("%c is ancestor",t1);
        return 1;
    }
    

    while (s1->top > 0&&s2->top > 0)
    {
        
        if(t1 == t2)
        {
           
            printf("%c is ancestor!\n",t1);
           return 1;
        }
        else if(s1->top > s2->top)
        {
            t1 = PopStack(s1);
        }
        else
        {
            t2 = PopStack(s2);
        }
        
    }
    printf("%c is ancestor\n",t3);
}