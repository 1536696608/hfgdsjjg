#include"QueueHead.h"
int LinkGetLen(LinkQueue* q)
{
    Node* l=q->front;
    int len=0;
    while (l != q->rear)
    {
        l = l->next;
        len++;
    }
    
    return len;
}