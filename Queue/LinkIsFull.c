#include"QueueHead.h"
int LinkIsFull(LinkQueue* q)
{
    if((q->rear - q->front)/sizeof(LinkQueue) >= (maxlen))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
