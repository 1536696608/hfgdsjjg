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
        printf("˳�����\n");
        printf("0���Զ�����\n");
        printf("1��ʼ������\n");
        printf("2�ж϶����Ƿ�Ϊ��\n");
        printf("3�ж��Ƿ����\n");
        printf("4���\n");
        printf("5����\n");
        printf("6ȡ��ͷԪ��\n");
        printf("7���г���\n");
        printf("8\n��ʼ����ѭ������;\n��������������ʱ����������ӣ�\n����������ż��ʱ����ͷ���ӣ�\n����������0ʱ���㷨�˳���\nÿ����������������ǰ�����е�����Ԫ�ء�\n");
        printf("������\n");
        printf("9��ʼ������\n");
        printf("10�ж϶����Ƿ�Ϊ��\n");
        printf("11�ж��Ƿ����\n");
        printf("12���\n");
        printf("13����\n");
        printf("14ȡ��ͷԪ��\n");
        printf("15���г���\n");
        printf("16��\n��ʼ����ѭ������;\n��������������ʱ����������ӣ�\n����������ż��ʱ����ͷ���ӣ�\n����������0ʱ���㷨�˳���\nÿ����������������ǰ�����е�����Ԫ�ء�\n");
        printf("***********\n");
        printf("20ѭ�������֤������ʵ��\n");
        printf("���������\n");
        scanf("%d",&i);
        switch (i)
        {
            case 0:
               
               for(n = 0;n < 120;n++)
               {
                   inSeqQueue(q,n);
                   printf("n = %d\n",n);
               }
               printf("���г���=%d\n",SeqGetLen(q));
                break;
            case 1:
                initSeqQueue(q);
                break;

            case 2:
                if(SeqIsEmpty(q))
                {
                    printf("���п�\n");
                }
                else
                {
                    printf("���зǿ�\n");
                }
                
                break;

            case 3:
                SeqIsFull(q);
                break;
            case 4:
                
                printf("���������Ԫ��,-1�˳�\n");
                scanf("%d",&m);
                while(m != -1)
                {
                    inSeqQueue(q,m);
                    printf("���������Ԫ��,-1�˳�\n");
                    scanf("%d",&m);
                    
                }
                m = 0;
                break;

            case 5:

                printf("����Ԫ��=%d\n",outSeqQueue(q));
                break;

            case 6:
                printf("��ͷԪ��=%d\n",SeqGetFront(q));
                break;
                
            case 7:
                printf("���г���=%d\n",SeqGetLen(q));
                break;
            
            case 8:
                initSeqQueue(q);
                printf("������ֵ,0����\n");
                scanf("%d",&k);
                while (k != 0)
                {
                    if(k % 2 != 0)
                    {
                        inSeqQueue(q,k);
                    }
                    else
                    {
                        printf("��ͷ=%d",outSeqQueue(q));
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
                    printf("���п�\n");
                }
                else
                {
                    printf("���зǿ�\n");
                }
                
                break;

            case 11:
                LinkIsFull(p);
                break;

            case 12:
            printf("���������Ԫ��,-1�˳�\n");
                scanf("%d",&m);
                while(m != -1)
                {
                    inLinkQueue(p,m);
                    printf("���������Ԫ��,-1�˳�\n");
                    scanf("%d",&m);
                    
                }
                m = 0;
                break;
             case 13:

                printf("����Ԫ��=%d\n",outLinkQueue(p));
                break;

            case 14:
                 printf("��ͷԪ��=%d\n",LinkGetFristX(p));
                break;

            case 15:
                printf("���г���=%d\n",LinkGetLen(p));
                break;

            case 16:
                initLinkQueue(&p);
                printf("������ֵ,0����\n");
                scanf("%d",&k);
                while (k != 0)
                {
                    if(k % 2 != 0)
                    {
                        inLinkQueue(p,k);
                    }
                    else
                    {
                        printf("��ͷ=%d",outLinkQueue(p));
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
