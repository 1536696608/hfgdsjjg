#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"linkhead.h"
int main()
{
	srand(time(NULL));
	int n,num,i,m,k,l,o,len;
	mytype j;
	Node* list1 = NULL;
	Node* list2 = NULL;
	Node* list3 = NULL;
	Node* list4 = NULL;
	Node* A;
	Node* B;
	Node* list6;
	initList(&A);
	initList(&B);
	while(1)
	{
		int point;
		printf("**************************\n");
		printf("0随机生成递增数列\n");
		
		printf("1尾插法得到链表\n");
		printf("2头插法得到链表\n");
		printf("3销毁链表\n");
		printf("4链表长度\n");
		printf("5找到链表第i元素\n");
		printf("6插入元素\n");
		printf("7查找元素值为x的节点\n");
		printf("8删除元素\n");
		printf("9在递增数列中插入元素\n");
		printf("10将数列分成奇偶数列\n");
		printf("11找到递增数列相同元素，返回链表\n");
		printf("12删除递增数列重复元素\n");
		printf("13合并递增数列\n");
        printf("14遍历\n");
		printf("输入-1退出\n");
		printf("**************************\n");
		printf("输入项目序号");

		scanf("%d",&point);
		switch(point)
		{
			case -1:
				return 0;
            case 14:
                Travel(list1);
                break;
			case 0:
				system("cls");
				printf("输入数列个数\n");
				scanf("%d",&num);
				list1 = CreateRandList(num);
				system("cls");
				printf("遍历得:\n");
				Travel(list1);

				break;
			case 1:
				printf("输入-1结束\n");
				list1 =  Tail_Creat_list();
				
				printf("遍历得:\n");
				// Travel(list1);

				break;
			case 2:
				system("cls");
				list1 =  Head_Creat_list();
				printf("遍历得:\n");
				printf("遍历得:\n");
				Travel(list1);
				break;
			case 3:
				DestoryList(&list1);
				break;
			case 4:
				len = Len_List(list1);
				printf("链表长度为%d\n",len);
				break;
			case 5:
				system("cls");
				m = 0;
				printf("输入查找元素序号输入-1退出\n");
				scanf("%d",&m);
				while(m != -1)
				{
					printf("x = %d\n",Find_Index(list1,m));

					printf("输入查找元素序号输入-1退出\n");
					scanf("%d",&m);
				}
				break;
			case 6:

				system("cls");
				int u = 0;

				printf("是否插入1继续-1退出\n");
				scanf("%d",&o);
				while(o != -1)
				{
					Insert(list1);
					printf("此时链表元素:\n");
					Travel(list1);
					printf("是否插入1继续-1退出\n");
					scanf("%d",&o);
				}
				break;
			case 7:
				system("cls");
				m = 0;
				while(m != -1)
				{
					printf("输入查找元素序号输入-1退出\n");
					scanf("%d",&m);
					if(Find_element(list1,m) != NULL)
					{
						printf("找到x = %d\n",Find_element(list1,m)->date);
					}
				}
				break;
			case 8:
				system("cls");
				m = 0;
				printf("是否继续删除1继续-1退出\n");
				scanf("%d",&m);
				while(m != -1)
				{
					Delet(list1);
					printf("此时遍历的：\n");
					Travel(list1);
					printf("是否继续删除1继续-1退出\n");
					scanf("%d",&m);
				}
				break;
			case 9:
				system("cls");
				printf("是否插入1继续-1退出\n");
				scanf("%d",&m);
				while(m != -1)
				{
					SeqLinkListInsert(list1);
					printf("此时链表元素:\n");
					Travel(list1);
					printf("是否插入1继续-1退出\n");
					scanf("%d",&m);
			 	}
			 	break;
			case 10:
				// system("cls");
				printf("开始\n");
				SplitList(list1,&A,&B);
				break;
			case 11:
				printf("创建递增数列1\n");
				list2 = Tail_Creat_list();
// 				list2 = CreateRandList(13);
				Travel(list2);
				printf("创建递增数列2\n");
				list3 = Tail_Creat_list();
// 				list3 = CreateRandList(13);
				Travel(list3);
				printf("结果为\n");
				list4 = AddCommonToList(list3,list2);
				Travel(list4);
                break;
			case 12:
				list6 = Tail_Creat_list();
				DeletR(list6);
				printf("删除成功\n");
				Travel(list6);
                break;
			case 13:
                // system("cls");
				printf("创建递增数列1输入-1结束\n");
				list2 =  Tail_Creat_list();
				
				Travel(list2);
				printf("创建递增数列2输入-1结束\n");
				list3 = Tail_Creat_list();
				Travel(list3);
				UnitList(&list2,list3);
				Travel(list2);
                break;

		}
	}
	return 0;
}
