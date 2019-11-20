#include"BTreeHead.h"
int LevelPrint(Node* T,LinkQueue** q)
{
    Node* tem;
    Node* nlast = T;//保存下一层节点的最右节点
    Node* rlast = T;//保存当层节点的最右节点
    if(T == NULL)
    {
        printf("empty\n");
        return 0;
    }
    inLinkQueue(*q,T);
    while(!LinkIsEmpty(*q))
    {
        
        tem = outLinkQueue(*q);
        printf("%c,",tem->data);
        if(tem->lchild != NULL)
        {
            inLinkQueue(*q,tem->lchild);
            nlast = tem->lchild;
        }
        if(tem->rchild != NULL)
        {
            inLinkQueue(*q,tem->rchild);
            nlast = tem->rchild;
        }
        if(tem == rlast)
        {
            printf("\n");
            rlast = nlast;
        }
    }
}