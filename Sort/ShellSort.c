#include"Sorts.h"
void ShellSort(ElemenType *A,int len)
{
    int i,j,tem,X,dis;
    int step = len;
    
    while (step > 1)
    {
        int ex = 0,com = 0;
        step /= 2;
        for(i = step+1;i < len;i++)
        {
            X = A[i];
            j = i;
            dis = j - step;
            com++;
            while (dis >= 0&&A[dis] > X)
            {
                A[j] = A[dis];
                j = dis;
                dis = j - step;
                ex++;
                com++;
            }
            A[j] = X;
            
        }
        printf("when step is %d,compare is %d,exchange is %d\n",step,com,ex);
        PrintArray(A,len);
    }
    
}