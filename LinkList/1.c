#include "linkhead.h"
Node* Tail_Creat_list() //Î²²å
{
	int x;                               
      Node* p,*head,*r;                             
      head = (Node*)malloc(sizeof(Node));
      head->next = NULL;
      r = head;
      scanf("%d",&x);
     while(x != -1)
     {
         p = (Node*)malloc(sizeof(Node));
         p->date = x;                    
         p->next = r->next;
         r->next = p;
         r = p;             
         scanf("%d",&x);
     }
 
     return head;
 }
