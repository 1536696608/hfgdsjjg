#include"SeqHead.h"
int main()
{
	srand(1);
	int n,num,i,m,k,l,o,r;
	int point;
	mytype j;
	SeqList* test = (SeqList*)malloc(sizeof(SeqList));
	SeqList* test2 = (SeqList*)malloc(sizeof(SeqList));
	initialList(test);
	initialList(test2);
	point = 1;
	while(point != -1)
	{
		printf("**************************\n");
		printf("0随机生成顺序表\n");
		printf("10生成递增顺序表\n");
		printf("11遍历\n");
		printf("1得到第n个元素的值\n");
		printf("2插入元素到第n个，错误返回-1，成功返回1\n");
		printf("3删除第i元素\n");
		printf("4递增数列添加元素\n");
		printf("5拆分成奇数与偶数\n");
		printf("6找到递增集合AB之中的共有元素放入C\n");
		printf("7删除递增有序表重复元素\n");
		printf("输入-1退出\n");
		printf("**************************\n");
		printf("输入项目序号");
		
		scanf("%d",&point);
		switch(point)
		{
			case 1:
				
				printf("输入选取下标\n");
				scanf("%d",&k);
				j = GetValue(test,k);
				printf("value = %d\n",j);
				break;
			case 2:
				printf("请输入插入位置，元素\n");
				scanf("%d%d",&m,&k);
				Insert(test,m,k);
				break;
			case 3:
				fflush(stdin);
				printf("请输入删除位置\n");
				scanf("%d",&l);
				Delet(test,l);
				break;
			case 4:
				printf("递增数列添加元素\n");
				scanf("%d",&l);
				InsertSeq(test,l);
				break;
			case 5:
				SplitJandO(test);break;
			case 6:
				printf("输入顺序表1元素，-1结束\n");
				scanf("%d",&m);
				initialList(test);
				initialList(test2);
				
				while(m != -1)
				{
					
					test->array[test->len] = m;
					test->len++;
					scanf("%d",&m);
				}
				printf("输入顺序表2元素，-1结束\n");
				scanf("%d",&m);
				while(m != -1)
				{
					test2->array[test2->len] = m;
					test2->len++;
					scanf("%d",&m);
				}
				printf("结果为\n");
				Travel(Addcommon(test,test2));break;
			case 7:
				printf("输入元素\n");
				scanf("%d",&m);
				initialList(test);
				while(m != -1)
				{
					
					test->array[test->len] = m;
					test->len++;
					scanf("%d",&m);
				}
				Travel(test);
				DeletRepeat(&test);
				Travel(test);break;
			case 0:
				printf("输入元素个数，随机生成顺序表,100以内\n");
				scanf("%d",&m);
				initialList(test);
				for(i = 0;i < m;i++)
				{
					test->array[i] = rand()%100;
					test->len++;
				}
				Travel(test);break;
			case 11:
				Travel(test);break;
			case 10:
				o = 0;
				printf("输入元素个数，随机生成顺序表,100以内\n");
				scanf("%d",&m);
				initialList(test);
				for(i = 0;i < m;i++)
				{
					o += (rand()%10);
					test->array[i] = o;
					test->len++;
				}
				break;
			
		}
	}
	
	return 0;
}
