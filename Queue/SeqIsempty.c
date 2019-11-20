#include"QueueHead.h"
int SeqIsEmpty(SeqQueue* s)
{
    if(s->fron%maxlen == s->roar%maxlen)
    {
        
        return 1;
    }
    return 0;
}