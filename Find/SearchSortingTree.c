#include"Sort.h"
Node* SearchSortingTree(Node* T,Mytype x,int level,int* flag)
{
    if (T == NULL)
    {
        return NULL;
    }
    if(T->data == x)
    {
        *flag = -1;//若没找到，flag为原值
        printf("find %d in %d level\n",x,level);
        return T;
    }
    else if(T->data > x&&*flag != -1)
    {
        SearchSortingTree(T->lchild,x,level + 1,flag);
    }
    else if(T->data < x&&*flag != -1)
    {
        SearchSortingTree(T->rchild,x,level + 1,flag);
    }
   
}
