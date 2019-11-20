#include"QueueHead.h"
int inLinkQueue(LinkQueue* q,ElemenType x)
{
    if(LinkIsFull(q))
    {
        printf("队列满\n");
        return -1;
    }
    else
    {
        Node *p = (Node*)malloc(sizeof(Node));
        p->data = x;
        p->next = NULL;
        q->rear->next = p;
        q->rear = p;
        return 1;
    }
    
}

ElemenType outLinkQueue(LinkQueue* q)
{
    if(LinkIsEmpty(q))
    {
        printf("队列空\n");
        return -1;
    }
    else
    {
        ElemenType value;
        Node *p = q->front;
        value = q->front->next->data;
        q->front = q->front->next;
        free(p);
        return value;
    }
    
}