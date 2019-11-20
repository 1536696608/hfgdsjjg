#include<stdio.h>
#include<stdlib.h>
#include"Stackhead.h"
int main()
{
    int point = 1;
    int num;
    char s[100];
    while(point!=-1)
    {
        
        printf("**********************\n");
        printf("1顺序栈输入数字将转化为十六进制\n");
        printf("2顺序栈判断字符串各括号是否是匹配的\n");
        printf("3链栈输入数字将转化为十六进制\n");
        printf("4链栈判断字符串各括号是否是匹配的\n");
        printf("5假设栈的输入序列为1、2、3、...、n，设计算法实现对给定的一个序列，判定其是否是此栈合法的输出序列。\n");
        printf("**********************\n");
        printf("输入选项,输入-1结束\n");
        scanf("%d",&point);
        switch (point)
        {
        case 1:
            printf("输入数值\n");
            scanf("%d",&num);
            Turn10to16(num);
            break;
        case 2:
            printf("输入字符串\n");
            getchar();
            gets(s);
            IsMatch(s);
            break;
        case 3:
            printf("输入数值\n");
            scanf("%d",&num);
            Turn10to16L(num);
            break;
        case 4:
            printf("输入字符串\n");
            getchar();
            gets(s);
            IsMatchL(s);
            break;
        case 5:
            printf("输入字符串\n");
            getchar();
            gets(s);
            IsRight(s);
            break;
        default:
            break;
        }
    }
    return 0;
}