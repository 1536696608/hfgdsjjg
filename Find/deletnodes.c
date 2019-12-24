#include"Sort.h"
Node* DelNode(Node *p)
{
      if (p->lchild)
      {
        Node *r = p->lchild;   //r指向其左子树;
        Node *prer = p->lchild;   //prer指向其左子树;
        while(r->rchild != NULL)//搜索左子树的最右边的叶子结点r
        {
            prer = r;
            r = r->rchild;
        }
        p->data = r->data;

        if(prer != r)//若r不是p的左孩子，把r的左孩子作为r的父亲的右孩子
            prer->rchild = r->lchild;
        else
            p->lchild = r->lchild; //否则结点p的左子树指向r的左子树

            free(r);
            return p;
      }
      else
      {
            Node *q = p->rchild;   //q指向其右子树;
            free(p);
            return q;
      }
}

Node* DeleteBST(Node *b, int x)
{
      if (b)
      {
            if (b->data == x)
                  b = DelNode(b);
            else if (b->data > x)
                  b->lchild = DeleteBST(b->lchild, x);
            else
                  b->rchild = DeleteBST(b->rchild, x);
      }
      return b;
}
