#include"Sorts.h"
void patitionmod3(ElemenType* A,int low,int high)
{
    int h = high;
    ElemenType X = A[low];
    
    while (low < high)
    {
        //printf("*-------------------------------------------------------------------------------------*\n");
        while(low < high&&A[high] %3 != 0)
        {
            high--;
            
        }
        if(low < high)
        {
            A[low] = A[high];
            low++;
            
            
        }
        while(low < high&&A[low] % 3 == 0)
        {
            low++;
            
        }
        if(low < high)
        {
            A[high] = A[low];
            high--;
            
        }
        
        //printf("*-------------------------------------------------------------------------------------*\n");
    }
    A[low] = X;
    if (A[low] % 3  == 0)
    {
        low++;
    }
    X = A[low];
    while (low < h)
    {
        //printf("*-------------------------------------------------------------------------------------*\n");
        while(low < h&&A[h] %3 == 2)
        {
            h--;
            
        }
        if(low < h)
        {
            A[low] = A[h];
            low++;
            
            
        }
        while(low < h&&A[low] % 3 == 1)
        {
            low++;
            
        }
        if(low < h)
        {
            A[h] = A[low];
            h--;
            
        }
        
        //printf("*-------------------------------------------------------------------------------------*\n");
    }
    A[low] = X;
   
}