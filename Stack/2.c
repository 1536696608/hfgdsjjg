#include"Stackhead.h"
int IsMatch(char* w)//�жϷ����Ƿ�ƥ�䣬ƥ�䷵��1�����򷵻�0
{
    char c = *w;
    char tem;
    SeqStack* s = (SeqStack*)malloc(sizeof(SeqStack));
    init(s);
    while(*w != '\0')
    {
        if(*w == '{'||*w == '['||*w == '(')
        {
            
            PushStack(s,*w);
        }
        else if(*w == '}'||*w == ']'||*w == ')')
        {
            while(1)
            {
                if(IsEmpty(s))
                {
                    printf("ƥ�����\n");
                    return 0;
                }
            
                else if(*w == '}')
                {
                    if(PopStack(s) == '{')
                    {
                        w++;
                        break;
                    }
                }
                else if(*w == ']')
                {
                    if(PopStack(s) == '[')
                    {
                        w++;
                        break;
                    }
                }
                else if(*w == ')')
                {
                    if(PopStack(s) == '(')
                    {
                        w++;
                        break;
                    }
                }

            
            }
            
        }

        w++;
    }
    if(IsEmpty(s)==0)
        {
            printf("ƥ�����abc\n");
            return 0;
        }
    printf("ƥ����ȷ\n");
    return 1;
}