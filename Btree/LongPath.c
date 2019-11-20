#include"BTreeHead.h"
int SearchLongPath(Node* T,SeqStack* s,SeqStack* save)
{
    if(T == NULL)
    {
        return 0;
    }
    PushStack(s,T->data);
    if(T->lchild == NULL&&T->rchild == NULL)
    {
        if(s->top > save->top)
        {
            int i;
            save->top = 0;
            for(i = 1;i <= s->top;i++)
            {
                save->base[i] = s->base[i];
                save->top++;
            }
        }
    }
    SearchLongPath(T->lchild,s,save);
    SearchLongPath(T->rchild,s,save);
    PopStack(s);
}

int PrintLongPath(Node* T,SeqStack* s,SeqStack* save)
{
    SearchLongPath(T,s,save);
    PrintPath(save);
}