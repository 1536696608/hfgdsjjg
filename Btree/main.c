#include"BTreeHead.h"

int main()
{
    int i;
    Node* node;
    Node* ctree;
    SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));
    SeqStack* s1 = (SeqStack*)malloc(sizeof(SeqStack));
    SeqStack* s2 = (SeqStack*)malloc(sizeof(SeqStack));
    LinkQueue* q1;
    q1 = (LinkQueue*)malloc(sizeof(LinkQueue));
    
    initLinkQueue(&q1);
    init(stack);
    init(s1);
    init(s2);
    char item;
    ElemType tem[100][3];
    int flag = 0;
    int flag2 = 0;
    int point = -1;
    int size = 0;
    int now = 0;
    char* filename = ".\\BTdata\\bt21.btr";

    while (1)
    {
        printf("*********************************************\n");
        printf("1���������ļ���,������\n");
        printf("2�������\n");
        printf("3�������\n");
        printf("4�������\n");
        printf("5�������ĸ߶�\n");
        printf("6��ӡ�������Ľ��Ͳ��\n");
        printf("7���Ľ����\n");
        printf("8��������Ҷ�ӽ����\n");
        printf("9������Ϊ2�Ľ����\n");
        printf("10����һ��ֵ�����丸�ڵ㣬�ֵܽڵ��Լ����ӽڵ�\n");
        printf("11����һ��ֵ���ҵ����������\n");
        printf("12��˳��洢����ת��Ϊ������ʽ\n");
        printf("13��������������\n");
        printf("����\n");
        printf("14����һ�ö�����T1��T2\n");
        printf("15��ӡҶ�ӵ����Ľڵ�\n");
        printf("16��δ�ӡ������\n");
        printf("17�����ڵ���������Ƚڵ�\n");
        printf("18��ӡ�������·��\n");
        printf("��������ѡ��\n");
        printf("*********************************************\n");
        scanf("%d",&point);
        switch (point)
        {
        case 1:
            size = ReadFileToArray(filename,tem);
            CreateTreeFromFile(&node,tem,&now,size);
            break;
        
        case 2:
            PreTravel(node);
            printf("\n");
            break;

        case 3:
            MidTravel(node);
            printf("\n");
            break;

        case 4:
            TailTravel(node);
            printf("\n");
            break;

        case 6:
            PrintNode(node,1);
            break;

        case 5:
            printf("height = %d\n",GetHeight(node));
            break;
        
        case 7:
            printf("nodes of number = %d\n",NumNodes(node));
            break;

        case 8:
            printf("leaves of number = %d\n",LevelNodes(node));
            break;

        case 9:
            printf("nodes owning 2 du of number = %d\n",NumOfTwoNodes(node));
            break;

        case 10:
            printf("input your value\n");
            getchar();
            scanf("%c",&item);
            GetNodeFBC(node,node,item,&flag);
            if(!flag)
            {
                printf("����ʧ��\n");
            }
            break;

        case 11:
            printf("input your value\n");
            getchar();
            scanf("%c",&item);
            FindNode(node,&flag2,1,item);
            if(!flag2)
            {
                printf("no find\n");
            }
            break;

        case 13:
            ExchangeRL(node);
            break;

        case 14:
            CopyTree(node,&ctree);
            PreTravel(ctree);

            break;

        case 15:
            PrintLeavePath(node,stack);
            break;

        case 16:
            LevelPrint(node,&q1);
            break;

        case 17:
            CommonAncestor(node,'u','r');
            break;


        case 18:
            PrintLongPath(node,s1,s2);
            break;
        default:
            break;
        }
    }
    
    return 0;
}