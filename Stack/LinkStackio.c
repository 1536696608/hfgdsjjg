#include"Stackhead.h"
void PushStackL(LinkStack*s,Elemtype x)
{
    LinkStack* l = (LinkStack*)malloc(sizeof(LinkStack));
    l->data = x;
    l->next = s->next;
    s->next=l;
}
Elemtype PopStackL(LinkStack*s)
{
    int val;
    if(s->next == NULL)
    {
        printf("Õ»¿Õ\n");
        return -1;
    }
    else
    {
       LinkStack* p = s->next;
       val = p->data;
       s->next = p->next;
       free(p);
       return val;
    }
    
}