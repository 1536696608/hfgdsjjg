#include"QueueHead.h"
int main()
{
    SeqQueue* q = (SeqQueue*)malloc(sizeof(SeqQueue));
    LinkQueue* p = (LinkQueue*)malloc(sizeof(LinkQueue));
    Node *tem;
    int i = 0;
    int m = 1;
    int n;
    int k = -1;
    while(i != -1)
    {
        printf("***********\n");
        printf("顺序队列\n");
        printf("0测试队列满\n");
        printf("1初始化队列\n");
        printf("2判断队列是否为空\n");
        printf("3判断是否队满\n");
        printf("4入队\n");
        printf("5出队\n");
        printf("6取队头元素\n");
        printf("7队列长度\n");
        printf("8\n初始化空循环队列;\n当键盘输入奇数时，此奇数入队；\n当键盘输入偶数时，队头出队；\n当键盘输入0时，算法退出；\n每当键盘输入后，输出当前队列中的所有元素。\n");
        printf("链队列\n");
        printf("9初始化队列\n");
        printf("10判断队列是否为空\n");
        printf("11判断是否队满\n");
        printf("12入队\n");
        printf("13出队\n");
        printf("14取队头元素\n");
        printf("15队列长度\n");
        printf("16：\n初始化空循环队列;\n当键盘输入奇数时，此奇数入队；\n当键盘输入偶数时，队头出队；\n当键盘输入0时，算法退出；\n每当键盘输入后，输出当前队列中的所有元素。\n");
        printf("***********\n");
        printf("20循环入队验证队列满实验\n");
        printf("请输入序号\n");
        scanf("%d",&i);
        switch (i)
        {
            case 0:
               
               for(n = 0;n < 120;n++)
               {
                   inSeqQueue(q,n);
                   printf("n = %d\n",n);
               }
               printf("队列长度=%d\n",SeqGetLen(q));
                break;
            case 1:
                initSeqQueue(q);
                break;

            case 2:
                if(SeqIsEmpty(q))
                {
                    printf("队列空\n");
                }
                else
                {
                    printf("队列非空\n");
                }
                
                break;

            case 3:
                SeqIsFull(q);
                break;
            case 4:
                
                printf("请输入入队元素,-1退出\n");
                scanf("%d",&m);
                while(m != -1)
                {
                    inSeqQueue(q,m);
                    printf("请输入入队元素,-1退出\n");
                    scanf("%d",&m);
                    
                }
                m = 0;
                break;

            case 5:

                printf("出队元素=%d\n",outSeqQueue(q));
                break;

            case 6:
                printf("队头元素=%d\n",SeqGetFront(q));
                break;
                
            case 7:
                printf("队列长度=%d\n",SeqGetLen(q));
                break;
            
            case 8:
                initSeqQueue(q);
                printf("输入数值,0结束\n");
                scanf("%d",&k);
                while (k != 0)
                {
                    if(k % 2 != 0)
                    {
                        inSeqQueue(q,k);
                    }
                    else
                    {
                        printf("队头=%d",outSeqQueue(q));
                    }
                    scanf("%d",&k);
                }
                k = q->fron;
                while (k < q->roar)
                {
                    
                    printf("%3d,",q->Queue[k]);
                    k++;
                }
                
                break;
            
            case 9:
                initLinkQueue(&p);
                break;

            case 10:
                if(LinkIsEmpty(p))
                {
                    printf("队列空\n");
                }
                else
                {
                    printf("队列非空\n");
                }
                
                break;

            case 11:
                LinkIsFull(p);
                break;

            case 12:
            printf("请输入入队元素,-1退出\n");
                scanf("%d",&m);
                while(m != -1)
                {
                    inLinkQueue(p,m);
                    printf("请输入入队元素,-1退出\n");
                    scanf("%d",&m);
                    
                }
                m = 0;
                break;
             case 13:

                printf("出队元素=%d\n",outLinkQueue(p));
                break;

            case 14:
                 printf("队头元素=%d\n",LinkGetFristX(p));
                break;

            case 15:
                printf("队列长度=%d\n",LinkGetLen(p));
                break;

            case 16:
                initLinkQueue(&p);
                printf("输入数值,0结束\n");
                scanf("%d",&k);
                while (k != 0)
                {
                    if(k % 2 != 0)
                    {
                        inLinkQueue(p,k);
                    }
                    else
                    {
                        printf("队头=%d",outLinkQueue(p));
                    }
                    scanf("%d",&k);
                }
                tem = p->front;
                while (tem != p->rear)
                {
                    printf("%3d,",tem->next->data);
                    tem = tem->next;
                }
                
                break;
            default:
                break;
            case 20:
                for(n = 1;n < 120;n++)
                {
                    inLinkQueue(p,n);
                    printf("n = %d\n",n);
                }
                printf(":==%d\n",(p->rear - p->front)/sizeof(LinkQueue));
        }
    }
    return 0;
}
