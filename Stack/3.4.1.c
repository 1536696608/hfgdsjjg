#include"Stackhead.h"
int IsRight(char* c)
{
    char val,tm;
    SeqStack* s = (SeqStack*)malloc(sizeof(SeqStack));
    init(s);
    char tmp[100];
    char r[100];
    int t = 0;
    int i = 0;
    val = *c;
    while(c[i] != '\0')
    {
        r[i] = '1'+i;
        i++;
    }
    
    i = 0;
    while(*c != '\0')
    {
        
        if(val >= *c)
        {
            PushStack(s,*c);
        }
        else if(!IsEmpty(s)&&*c > val)
        {
            tm = PopStack(s);
            while(tm < *c)
            {
                tmp[i] = tm;
                printf("%d = %c\n",i,tmp[i]);
                i++;
                if(IsEmpty(s))
                {
                    break;
                }
                tm = PopStack(s);
            }
            if(!IsEmpty(s))
            {
                PushStack(s,tm);
                PushStack(s,*c);
            }
            else
            {
                
                PushStack(s,*c);
            }
            
        }
        
        val = *c;
        c++;
    }
    while(IsEmpty(s) == 0)
    {
        val = PopStack(s);
        printf("输出%c\n",val);
        
        tmp[i] = val;
        i++;
    }
    tmp[i] = '\0';
    if(strcmp(tmp,r) == 0)
    {
        
        printf("正确输入\n");
    }
    else
    {
        puts(tmp);
        printf("错误输入\n");
    }
    
}