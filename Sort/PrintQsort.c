#include"Sorts.h"
int Patition(ElemenType*A,int low,int high,int len)
{
    
    ElemenType X = A[low];
    //printf("%d is standard number in %d position\n",X,low);
    while (low < high)
    {
        //printf("*-------------------------------------------------------------------------------------*\n");
        while(low < high&&A[high] > X)
        {
            high--;
           
        }
        if(low < high)
        {
            //printf("%d ---> %d position\n",A[high] , low);
            A[low] = A[high];
            low++;
        }
        while(low < high&&A[low] < X)
        {
            low++;
           
        }
        if(low < high)
        {
            //printf("%d ---> %d position\n",A[low] , high);
            A[high] = A[low];
            high--;
        }
        
        //printf("*-------------------------------------------------------------------------------------*\n");
    }
    A[low] = X;
    
    //printf("result:\3");
    
    printf("\n");
    Sleep(200);
    system("cls");
    PrintArray(A,len);
    return low;
}

void printqsorts(ElemenType* A,int start,int end,int len)
{
    int mid;
    int i;
    if(start < end)
    {
        
        mid = Patition(A,start,end,len);
        
        printqsorts(A,mid+1,end,len);
        printqsorts(A,start,mid-1,len);
        
    }
    
}