#include"Stackhead.h"
void Turn10to16L(int i)
{
    int val;
    LinkStack *l;
    initL(&l);
    while ((i != 0))
    {
        PushStackL(l,i%16);
        i /= 16;
    }
    printf("16½øÖÆÎª£º\n");
    while(IsEmptyL(l)!=1)
    {
        val = PopStackL(l);
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