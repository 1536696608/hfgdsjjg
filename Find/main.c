#include"Sort.h"
int main()
{
    int flag = 1;
    int p = 0;
    int x,i;
    int arraytest1[25] = {1,2,3,4,6,7,8,9,10,11,12,13,17,18,19,20,24,25,26,30,35,40,45,50,100};
    int arraytest2[15] = {100,150,120,50,70,60,80,170,180,160,110,30,40,35,175};
    int arraytest3[26] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    Node* T;
    //T = NULL;
    
    LinkQueue** q;
    initLinkQueue(q);
    
    while(1)
    {
        printf("***************************************\n");
        printf("1二分查找\n");
        printf("2输入数值构建二叉排序树\n");
        printf("3在构建二叉树中查找元素\n");
        printf("4删除二叉树中指定元素\n");
        printf("5根据有序数组创建平衡二叉树\n");
        printf("6层次打印\n");
        printf("7中序遍历\n");
        printf("***************************************\n");
        printf("请输入选项\n");
        scanf("%d",&p);
        switch (p)
        {
        case 1:
            printf("输入查找数字,输入-999结束\n");
            scanf("%d",&x);
            while (x!=-999)
            {
                Binarysearch(arraytest1,25,x);
                scanf("%d",&x);
            }
            break;
        
        case 2:
            for(i = 0;i < 15;i++)
            {
                printf("%d,%d\n",i+1,arraytest2[i]);
                BinarySortingTree(&T,arraytest2[i]);
            }
            LevelPrint(T,q);
            break;

        case 3:
            printf("输入查找数字,输入-999结束\n");
            scanf("%d",&x);
            while (x!=-999)
            {
                flag = 1;
                SearchSortingTree(T,x,1,&flag);
                if (flag == 1)
                {
                    printf("未找到该数\n");
                }
                scanf("%d",&x);
            }
            break;

        case 4:
            printf("输入删除元素,输入-999结束\n");
            scanf("%d",&x);
            while (x!=-999)
            {
                
                T = DeleteBST(T,x);
                
                scanf("%d",&x);
                
            }
            break;
            
        case 5:
            T = sortedArrayToBST(arraytest3,0,25);
        
            break;

        case 6:
            LevelPrint(T,q);
            break;

        case 7:
            MidTravel(T);
            break;   
        default:
            break;
        }
        
    }
    
    return 0;
}