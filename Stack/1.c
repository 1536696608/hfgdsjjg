#include"Stackhead.h"
void Turn10to16(int i)
{
    int val;
    SeqStack* s = (SeqStack*)malloc(sizeof(SeqStack));
    init(s);
    while ((i != 0))
    {
        PushStack(s,i%16);
        i /= 16;
    }
    printf("16½øÖÆÎª£º\n");
    while(IsEmpty(s)!=1)
    {
        val = PopStack(s);
        if(val >= 10)
        {
            printf("%3c\n",val-10+'A');
        }
        else
        {
            printf("%3d\n",val);
        }
        
    }
}