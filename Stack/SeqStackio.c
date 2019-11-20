#include"Stackhead.h"

void PushStack(SeqStack*s,Elemtype x)
{
    if(s->top >= 50)
    {
        printf("栈满\n");
    }
    else
    {
        // if(s->top<0)
        // {
        //     s->top = 0;
        // }
        s->top++;
        s->base[s->top] = x;
        // printf("入栈成功\n");
    }
    
}
Elemtype PopStack(SeqStack*s)
{
    Elemtype val;
    if(s->top <= 0)
    {
        printf("栈空\n");
        return -1;
    }
    else
    {
        // printf("出栈成功\n");
        val = s->base[s->top];
        s->top--;
    }
    return val;
}