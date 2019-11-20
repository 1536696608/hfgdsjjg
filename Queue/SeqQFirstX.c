#include"QueueHead.h"
ElemenType SeqGetFront(SeqQueue* s)
{
    if (SeqIsEmpty(s))
    {
        printf("Õ»¿Õ\n");
        return -1;   
    }
    return s->Queue[s->fron%maxlen];
}