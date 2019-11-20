#include"Stackhead.h"
void initL(LinkStack** l)
{
    *l = (LinkStack*)malloc(sizeof(LinkStack));
    (*l)->next = NULL;
}