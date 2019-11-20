#include"QueueHead.h"
int inSeqQueue(SeqQueue* s,ElemenType x)
{
    if(SeqIsFull(s))
    {
        printf("队列满\n");
        return -1;
    }
    else
    {
        s->Queue[s->roar%maxlen] = x;
        s->roar++;
    }
    return 1;
}

ElemenType outSeqQueue(SeqQueue* s)
{
    ElemenType val;
    if(SeqIsEmpty(s))
    {
        printf("队列空\n");
        return -1;
    }
    else
    {
        val = s->Queue[s->fron%maxlen];
        s->fron++;
        return val;
    }
    
}