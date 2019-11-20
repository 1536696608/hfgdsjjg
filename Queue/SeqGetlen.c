#include"QueueHead.h"
int SeqGetLen(SeqQueue* s)
{
   
   return (s->roar - s->fron + maxlen)%maxlen;
}