#include"Stackhead.h"
int IsMatchL(char* w)//�жϷ����Ƿ�ƥ�䣬ƥ�䷵��1�����򷵻�0
{
    char c = *w;
    char tem;
    LinkStack* s;
    initL(&s);
    while(*w != '\0')
    {
        if(*w == '{'||*w == '['||*w == '(')
        {
            
            PushStackL(s,*w);
        }
        else if(*w == '}'||*w == ']'||*w == ')')
        {
            while(1)
            {
                if(IsEmptyL(s))
                {
                    printf("ƥ�����\n");
                    return 0;
                }
            
                else if(*w == '}')
                {
                    if(PopStackL(s) == '{')
                    {
                        w++;
                        break;
                    }
                    else
                    {
                        printf("ƥ�����\n");
                        return -1;
                    }
                    
                }
                else if(*w == ']')
                {
                    if(PopStackL(s) == '[')
                    {
                        w++;
                        break;
                    }
                    else
                    {
                        printf("ƥ�����\n");
                        return -1;
                    }
                }
                else if(*w == ')')
                {
                    if(PopStackL(s) == '(')
                    {
                        w++;
                        break;
                    }
                    else
                    {
                        printf("ƥ�����\n");
                        return -1;
                    }
                }

            
            }
            
        }

        w++;
    }
    if(IsEmptyL(s)==0)
        {
            printf("ƥ�����abc\n");
            return 0;
        }
    printf("ƥ����ȷ\n");
    return 1;
}