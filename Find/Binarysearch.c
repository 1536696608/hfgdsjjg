#include"Sort.h"
int Binarysearch(Mytype* A,int len,Mytype x)
{
    int mid;
    int head = 0;
    int tail = len - 1;
    while (head <= tail)
    {
        
        mid = (head + tail) / 2;
        printf("head = %d, mid value = %d ,tail = %d\n",head,A[mid],tail);
        if (A[mid] == x)
        {
            printf("�ҵ��ڵ�%d��λ��\n",mid+1);
            return x;
        }
        else if (A[mid] > x)
        {
            tail = mid;
            tail--;
        }
        else if (A[mid] < x)
        {
            head = mid;
            head++;
        }
        
        
    }
    printf("δ�ҵ���Ԫ��\n");
    return -1;
    
}