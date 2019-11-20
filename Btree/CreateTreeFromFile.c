#include"BTreeHead.h"
int ReadFileToArray(char* file,ElemType tem[100][3])
{
    
    FILE* fp;
    char str[100];
    int i = 0;
    fp = fopen(file,"r");
    if(!fp)
    {
        printf("文件打开失败\n");
        return -1;
    }
    
    while (fgets(str,100,fp)!=NULL)
    {
        
        if(strcmp(str,"BinaryTree\n") == 0)
        {
            puts(str);
            break;
        }
    }
       

    while (fscanf(fp,"%c %c %c\n",&tem[i][0],&tem[i][1],&tem[i][2]) != EOF)
    {
        
        i++;
    }
    fclose(fp);
    return i;
}
int CreateTreeFromFile(Node** node,ElemType tem[100][3],int *now,int size)
{
    if(*now >= size||size == 0)
    {
        return 1;
    }
    else 
    {
        
        (*node) = (Node*)malloc(sizeof(Node));
        (*node)->data = tem[*now][0];
        (*node)->lchild = NULL;
        (*node)->rchild = NULL;
        printf("=%c\n",(*node)->data);
        printf("%d\n",*now);
        int t = *now;
        if(tem[t][1] == '1')
        {
            *now = *now+1;
            CreateTreeFromFile(&((*node)->lchild),tem,now,size);
        }
        if (tem[t][2] == '1')
        {
            *now = *now + 1;
            CreateTreeFromFile(&((*node)->rchild),tem,now,size);
        }
        
    }
    
}