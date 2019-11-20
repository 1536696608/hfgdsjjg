#include"QueueHead.h"
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