#include"Stackhead.h"
int IsMatchL(char* w)//≈–∂œ∑˚∫≈ «∑Ò∆•≈‰£¨∆•≈‰∑µªÿ1£¨∑Ò‘Ú∑µªÿ0
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
                    printf("∆•≈‰¥ÌŒÛ\n");
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
                        printf("∆•≈‰¥ÌŒÛ\n");
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
                        printf("∆•≈‰¥ÌŒÛ\n");
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
                        printf("∆•≈‰¥ÌŒÛ\n");
                        return -1;
                    }
                }

            
            }
            
        }

        w++;
    }
    if(IsEmptyL(s)==0)
        {
            printf("∆•≈‰¥ÌŒÛabc\n");
            return 0;
        }
    printf("∆•≈‰’˝»∑\n");
    return 1;
}