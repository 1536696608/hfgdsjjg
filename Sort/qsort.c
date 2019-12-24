#include"Sorts.h"
int compare = 0,share = 0;
void PrintArray(ElemenType* A,int i)
{
    int n;
    for(n = 0;n < i;n++)
    {
        printf("%5d",A[n]);
    }
    printf("\n");
}
int patition(ElemenType*A,int low,int high,int len)
{
    
    ElemenType X = A[low];
    printf("¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý¡ý\n");
    printf("%d is center\n",X);
    while (low < high)
    {
        //printf("*-------------------------------------------------------------------------------------*\n");
        while(low < high&&A[high] > X)
        {
            compare++;
            high--;
            
        }
        if(low < high)
        {
            share++;
            printf("exchane%d and %d\n",A[low] , A[high]);
            A[low] = A[high];
            low++;
            
            
        }
        while(low < high&&A[low] < X)
        {
            compare++;
            low++;
           
        }
        if(low < high)
        {
            share++;
            printf("exchane%d and %d\n",A[low] , A[high]);
            A[high] = A[low];
            high--;
            
        }
        
        //printf("*-------------------------------------------------------------------------------------*\n");
    }
    A[low] = X;
  
    printf("result:\3");
    PrintArray(A,len);
    printf("¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü¡ü\n");
    printf("\n");
    return low;
}

void Qsorts(ElemenType* A,int start,int end,int len)
{
    int mid;
    int i;
    if(start < end)
    {
        
        mid = patition(A,start,end,len);
        Qsorts(A,mid+1,end,len);
        Qsorts(A,start,mid-1,len);
        
    }
    
}
void qsorts(ElemenType* A,int start,int end,int len)
{
    Qsorts(A,start,end,len);
    printf("\n");
    printf("compare = %d share = %d\n",compare,share);
}