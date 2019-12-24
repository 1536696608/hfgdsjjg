#include"Sort.h"
int BinarySortingTree(Node** T,Mytype x)//插入二叉排序树
{
    
    if (*T == NULL)
    {
        *T = (Node*)malloc(sizeof(Node));
        init(T);
        (*T)->data = x;
        printf("插入%d成功\n",x);
        return 1;
    }
    else if (x < (*T)->data)
    {
        BinarySortingTree(&((*T)->lchild),x);
    }
    else
    {
        BinarySortingTree(&((*T)->rchild),x);
    }
    
}