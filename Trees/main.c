#include"createTree.h"
int main()
{
    int h;
    int point = 0;
    pTree* Trees = (pTree*)malloc(sizeof(pTree));
    char* filename = "./tData/F20.tre";
    CreateTreeFromFile(filename,&Trees);
    printTree(Trees);
    while (1)
    {
        printf("****************************\n");
        printf("1先序遍历\n");
        printf("2后序遍历\n");
        printf("3层次遍历\n");
        printf("4森林的高度\n");
        printf("5森林的结点数\n");
        printf("6森林的叶子结点数\n");
        printf("7森林的度数\n");
        printf("8森林的先序层次输出\n");
        printf("9以广义表的形式输出\n");
        printf("****************************\n");
        printf("输入选项\n");
        scanf("%d",&point);
        switch (point)
        {
        case 1:
            preTraverse(Trees);
            break;
        
        case 2:
            MidTraverse(Trees);
            break;

        case 3:
            LevelOrder(Trees);
            break;

        case 4:
            h = GetTreesHeight(Trees);
            printf("Trees is %d h\n",h);
            break;

        case 5:
            printf("Trees has %d nodes\n",GetNodes(Trees));
            break;

        case 6:
            printf("Trees has %d leaves\n",GetLeave(Trees));
            break;

        case 7:
            printf("degree is %d\n",Getdegree(Trees));
            break;

        case 8:
            OutPutTrees(Trees);
            break;

        case 9:
            PrintAsTableTrees(Trees);
            break;

        default:
            break;
        }
    }
    
    return 0;
}