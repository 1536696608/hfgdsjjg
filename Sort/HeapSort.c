#include"Sorts.h"
void sift(ElemenType* A,int m,int n)//��m��n�������е���
{
    int finish = 0;
    ElemenType X = A[m];
    int i = m;
    int j = 2*m + 1;
    while (j < n&&!finish)
    {
        if(A[j] <= A[j+1]&&j+1 < n)
        j = j+1;
        if(X >= A[j])
        {
            finish = 1;
        }
        else 
        {
            A[i] = A[j];
            i = j;
            j = 2*i + 1;
        }
        
    }
    A[i] = X;
    
}

void HeapSort(ElemenType* A,int l)
{
    ElemenType tem;
    int n = l;
    int i;
    for (i = n/2 - 1;i >= 0;i--)
    {
        Sleep(200);
        system("cls");
        printf("������\n");
        PrintArray(A,l);
        sift(A,i,n);
    }
    printf("\n");
    printf("׼����ʼ�����........................................................................................\n");
    for (i = n-1;i >= 1;i--)
    {
        
        Sleep(200);
        system("cls");
        printf("�����\n");
        PrintArray(A,l);
        tem = A[0];
        A[0] = A[i];
        A[i] = tem;
        sift(A,0,i-1);
    }
} 