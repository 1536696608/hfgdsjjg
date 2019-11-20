#include"QueueHead.h"
int SeqIsFull(SeqQueue* s)
{
    if(SeqGetLen(s) >= maxlen)
    {
        return 1;//队列满
    }
    else
    {
        return 0;
    }
    
}