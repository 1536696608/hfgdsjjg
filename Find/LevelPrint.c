#include"Sort.h"
void initLinkQueue(LinkQueue** q)
{
    
    Nodel *p = (Nodel*)malloc(sizeof(Nodel));
    (*q)->front = (*q)->rear = p;
    
}



int LinkIsEmpty(LinkQueue *q)
{
    if(q->front == q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int inLinkQueue(LinkQueue* q,ElemenType x) 
{
 
        Nodel *p = (Nodel*)malloc(sizeof(Nodel));
        p->data = x;
        p->next = NULL;
        q->rear->next = p;
        q->rear = p;
        return 1;
    
    
}

ElemenType outLinkQueue(LinkQueue* q)
{
    if(LinkIsEmpty(q))
    {
        printf("队列空\n");
        return NULL;
    }
    else
    {
        ElemenType value;
        Nodel *p = q->front;
        value = q->front->next->data;
        q->front = q->front->next;
        free(p);
        return value;
    }
    
}

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
        printf("%d,",tem->data);
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

int MidTravel(Node* T)
{
    
    if(T == NULL)
    {
        
        return 1;
    }
    else
    {
        
        MidTravel(T->lchild);
        printf("%7d",T->data);
        MidTravel(T->rchild);
    }
    
}