#include"BTreeHead.h"
void initLinkQueue(LinkQueue** q)
{
    
    Nodel *p = (Nodel*)malloc(sizeof(Nodel));
    (*q)->front = (*q)->rear = p;
    
}



int LinkIsEmpty(LinkQueue *q)
{
    if(q->front == q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int inLinkQueue(LinkQueue* q,ElemenType x) 
{
 
        Nodel *p = (Nodel*)malloc(sizeof(Nodel));
        p->data = x;
        p->next = NULL;
        q->rear->next = p;
        q->rear = p;
        return 1;
    
    
}

ElemenType outLinkQueue(LinkQueue* q)
{
    if(LinkIsEmpty(q))
    {
        printf("队列空\n");
        return NULL;
    }
    else
    {
        ElemenType value;
        Nodel *p = q->front;
        value = q->front->next->data;
        q->front = q->front->next;
        free(p);
        return value;
    }
    
}
