#include"Sort.h"
Node* sortedArrayToBST(Mytype A[],int start,int end)
{
    if(start > end)
    {
        return NULL;
    }
    Node* T = (Node*)malloc(sizeof(Node));
    T->lchild = T->rchild = NULL;
    int mid = (start+end)/2;
    T->data = A[mid];
    T->lchild = sortedArrayToBST(A,start,mid - 1);
    T->rchild = sortedArrayToBST(A,mid+1,end);
    return T;
}