#include"QueueHead.h"
ElemenType SeqGetFront(SeqQueue* s)
{
    if (SeqIsEmpty(s))
    {
        printf("ջ��\n");
        return -1;   
    }
    return s->Queue[s->fron%maxlen];
}