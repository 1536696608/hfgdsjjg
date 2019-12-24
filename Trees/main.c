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
        printf("1�������\n");
        printf("2�������\n");
        printf("3��α���\n");
        printf("4ɭ�ֵĸ߶�\n");
        printf("5ɭ�ֵĽ����\n");
        printf("6ɭ�ֵ�Ҷ�ӽ����\n");
        printf("7ɭ�ֵĶ���\n");
        printf("8ɭ�ֵ����������\n");
        printf("9�Թ�������ʽ���\n");
        printf("****************************\n");
        printf("����ѡ��\n");
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