#include"Sorts.h"
int main()
{
    int p,i;
    srand((unsigned)time(NULL));
    int com = 0,ex = 0;
    int len = 25;
    ElemenType test1[25] = {106,213,325,446,579,654,721,870,917,510,21,632,73,14,815,316,412,18,619,720,21,808,923,25,26};
    ElemenType test3[22] = {180,203,32,46,25,76,17,58,99,100,11,102,13,54,75,6,27,18,19,29,2,82};
    ElemenType test4[25] = {106,213,325,446,579,654,721,870,917,510,21,632,73,14,815,316,412,18,619,720,21,808,923,25,26};
    ElemenType test5[26] = {-999,106,213,325,446,579,654,721,870,917,510,21,632,73,14,815,316,412,18,619,720,21,808,923,25,26};
    ElemenType test8[100];
    
    while(1)
    {
        printf("********************************************************************************************\n");
        printf("1快速排序\n");
        printf("2除3余数分类\n");
        printf("3希尔排序\n");
        printf("4打印快速排序过程\n");
        printf("5堆排序\n");
        printf("6归并排序\n");
        printf("********************************************************************************************\n");
        printf("输入选项\n");
        for ( i = 0; i < 100; i++)
        {
            test8[i] = rand()%1000;
        }
    int l = 100;
        scanf("%d",&p);
        switch (p)
        {
        case 1:
            PrintArray(test8,l);
            qsorts(test8,0,l-1,l);
            
            break;
        
        case 2:
            PrintArray(test8,l);
            patitionmod3(test8,0,l-1);
            PrintArray(test8,l);
            break;

        case 3:
            ShellSort(test8,l);
            PrintArray(test8,l);
            break;

        case 4:
            PrintArray(test8,l);
            printf("准备开始........................................................................................\n");
            Sleep(5000);
            printqsorts(test8,0,l-1,l);
            break;

        case 5:
            PrintArray(test8,l);
            printf("准备开始........................................................................................\n");
            Sleep(5000);
            HeapSort(test8,l);
            break;
        case 6:
            PrintArray(test8,l);
            printf("准备开始........................................................................................\n");
            Sleep(5000);
            MergeSort(test8,0,l-1);
            
            break;

        default:
            break;
        }

    }
    return 0;
}