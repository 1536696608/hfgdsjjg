#include"Stackhead.h"
int IsEmptyL(LinkStack* s)
{
    if(s->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}