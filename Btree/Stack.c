#include"BTreeHead.h"

void PushStack(SeqStack*s,Elemtype x)
{
    if(s->top >= 50)
    {
        printf("ջ��\n");
    }
    else
    {
        // if(s->top<0)
        // {
        //     s->top = 0;
        // }
        s->top++;
        s->base[s->top] = x;
        // printf("��ջ�ɹ�\n");
    }
    
}
Elemtype PopStack(SeqStack*s)
{
    Elemtype val;
    if(s->top <= 0)
    {
        printf("ջ��\n");
        return -1;
    }
    else
    {
        // printf("��ջ�ɹ�\n");
        val = s->base[s->top];
        s->top--;
    }
    return val;
}

void init(SeqStack* s)
{
    s->top = 0;
}

void PrintPath(SeqStack* s)
{
    int i;
    for(i =1;i <= s->top;i++)
    {
        printf("%3c��",s->base[i]);
    }
}