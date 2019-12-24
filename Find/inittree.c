#include"Sort.h"
void init(Node** T)
{
    *T = (Node*)malloc(sizeof(Node));
    (*T)->lchild = (*T)->rchild = NULL;
}