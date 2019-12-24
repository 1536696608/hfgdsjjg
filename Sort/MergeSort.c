#include"Sorts.h"
int MergeSort(ElemenType* A,int low,int high)
{
    if(A == NULL)
    {
        return -1;
    }
    if (low >= high)
    {
        return -1;
    }
    
    int mid,i,j,m; 
    ElemenType* temp = (ElemenType*)malloc(sizeof(ElemenType)*(high- low + 1));//存储数组
    if(temp == NULL)
    {
        return -1;
    }
    mid = (low + high) / 2;
    //拆分数组i
    MergeSort(A,low,mid);
    MergeSort(A,mid + 1,high);
    //合并数组
    i = low;
    j = mid+1;
    m = 0;
    while (i <= mid&& j <= high)
    {
        if(A[i] < A[j])
        {
            temp[m] = A[i];
            i++;
            m++;
        }
        else 
        {
           temp[m] = A[j];
            j++;
            m++;
        }
        
    }
    while (i <= mid)
    {
        temp[m] = A[i];
        i++;
        m++;
        
    }
    while (j <= high)
    {
       temp[m] = A[j];
        j++;
        m++;
    }
    for(i = 0;i < high- low + 1;i++)
    {
        A[low+i] = temp[i];
        
    }
    Sleep(200);
    system("cls");
    PrintArray(A,100);
}