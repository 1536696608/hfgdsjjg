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
        printf("1输入树的文件名,创建树\n");
        printf("2先序遍历\n");
        printf("3中序遍历\n");
        printf("4后序遍历\n");
        printf("5二叉树的高度\n");
        printf("6打印二叉树的结点和层次\n");
        printf("7树的结点数\n");
        printf("8二叉树的叶子结点数\n");
        printf("9求树度为2的结点数\n");
        printf("10输入一个值，求其父节点，兄弟节点以及孩子节点\n");
        printf("11查找一个值，找到的输出其层次\n");
        printf("12将顺序存储的树转化为链表形式\n");
        printf("13将左右子树交换\n");
        printf("附加\n");
        printf("14复制一棵二叉树T1到T2\n");
        printf("15打印叶子到根的节点\n");
        printf("16层次打印二叉树\n");
        printf("17求两节点最近的祖先节点\n");
        printf("18打印二叉树最长路径\n");
        printf("请输输入选项\n");
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
                printf("查找失败\n");
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