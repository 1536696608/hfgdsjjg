#include"QueueHead.h"
void initLinkQueue(LinkQueue** q)
{
    Node *p = (Node*)malloc(sizeof(Node));
    (*q)->front = (*q)->rear = p;
    
}