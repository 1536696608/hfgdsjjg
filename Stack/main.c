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
        printf("1˳��ջ�������ֽ�ת��Ϊʮ������\n");
        printf("2˳��ջ�ж��ַ����������Ƿ���ƥ���\n");
        printf("3��ջ�������ֽ�ת��Ϊʮ������\n");
        printf("4��ջ�ж��ַ����������Ƿ���ƥ���\n");
        printf("5����ջ����������Ϊ1��2��3��...��n������㷨ʵ�ֶԸ�����һ�����У��ж����Ƿ��Ǵ�ջ�Ϸ���������С�\n");
        printf("**********************\n");
        printf("����ѡ��,����-1����\n");
        scanf("%d",&point);
        switch (point)
        {
        case 1:
            printf("������ֵ\n");
            scanf("%d",&num);
            Turn10to16(num);
            break;
        case 2:
            printf("�����ַ���\n");
            getchar();
            gets(s);
            IsMatch(s);
            break;
        case 3:
            printf("������ֵ\n");
            scanf("%d",&num);
            Turn10to16L(num);
            break;
        case 4:
            printf("�����ַ���\n");
            getchar();
            gets(s);
            IsMatchL(s);
            break;
        case 5:
            printf("�����ַ���\n");
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