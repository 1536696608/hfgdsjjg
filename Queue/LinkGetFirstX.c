#include"QueueHead.h"
ElemenType LinkGetFristX(LinkQueue* q)
{
    ElemenType val;
    if(LinkIsEmpty(q))
    {
        printf("¶ÓÁĞ¿Õ©º\n");
        return 0;
    }
    else
    {
        printf("!!\n");
        val = q->front->next->data;
        return val;
    }
    
}