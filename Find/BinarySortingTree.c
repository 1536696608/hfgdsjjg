#include"Sort.h"
int BinarySortingTree(Node** T,Mytype x)//�������������
{
    
    if (*T == NULL)
    {
        *T = (Node*)malloc(sizeof(Node));
        init(T);
        (*T)->data = x;
        printf("����%d�ɹ�\n",x);
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