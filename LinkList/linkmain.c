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
		printf("0������ɵ�������\n");
		
		printf("1β�巨�õ�����\n");
		printf("2ͷ�巨�õ�����\n");
		printf("3��������\n");
		printf("4������\n");
		printf("5�ҵ������iԪ��\n");
		printf("6����Ԫ��\n");
		printf("7����Ԫ��ֵΪx�Ľڵ�\n");
		printf("8ɾ��Ԫ��\n");
		printf("9�ڵ��������в���Ԫ��\n");
		printf("10�����зֳ���ż����\n");
		printf("11�ҵ�����������ͬԪ�أ���������\n");
		printf("12ɾ�����������ظ�Ԫ��\n");
		printf("13�ϲ���������\n");
        printf("14����\n");
		printf("����-1�˳�\n");
		printf("**************************\n");
		printf("������Ŀ���");

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
				printf("�������и���\n");
				scanf("%d",&num);
				list1 = CreateRandList(num);
				system("cls");
				printf("������:\n");
				Travel(list1);

				break;
			case 1:
				printf("����-1����\n");
				list1 =  Tail_Creat_list();
				
				printf("������:\n");
				// Travel(list1);

				break;
			case 2:
				system("cls");
				list1 =  Head_Creat_list();
				printf("������:\n");
				printf("������:\n");
				Travel(list1);
				break;
			case 3:
				DestoryList(&list1);
				break;
			case 4:
				len = Len_List(list1);
				printf("������Ϊ%d\n",len);
				break;
			case 5:
				system("cls");
				m = 0;
				printf("�������Ԫ���������-1�˳�\n");
				scanf("%d",&m);
				while(m != -1)
				{
					printf("x = %d\n",Find_Index(list1,m));

					printf("�������Ԫ���������-1�˳�\n");
					scanf("%d",&m);
				}
				break;
			case 6:

				system("cls");
				int u = 0;

				printf("�Ƿ����1����-1�˳�\n");
				scanf("%d",&o);
				while(o != -1)
				{
					Insert(list1);
					printf("��ʱ����Ԫ��:\n");
					Travel(list1);
					printf("�Ƿ����1����-1�˳�\n");
					scanf("%d",&o);
				}
				break;
			case 7:
				system("cls");
				m = 0;
				while(m != -1)
				{
					printf("�������Ԫ���������-1�˳�\n");
					scanf("%d",&m);
					if(Find_element(list1,m) != NULL)
					{
						printf("�ҵ�x = %d\n",Find_element(list1,m)->date);
					}
				}
				break;
			case 8:
				system("cls");
				m = 0;
				printf("�Ƿ����ɾ��1����-1�˳�\n");
				scanf("%d",&m);
				while(m != -1)
				{
					Delet(list1);
					printf("��ʱ�����ģ�\n");
					Travel(list1);
					printf("�Ƿ����ɾ��1����-1�˳�\n");
					scanf("%d",&m);
				}
				break;
			case 9:
				system("cls");
				printf("�Ƿ����1����-1�˳�\n");
				scanf("%d",&m);
				while(m != -1)
				{
					SeqLinkListInsert(list1);
					printf("��ʱ����Ԫ��:\n");
					Travel(list1);
					printf("�Ƿ����1����-1�˳�\n");
					scanf("%d",&m);
			 	}
			 	break;
			case 10:
				// system("cls");
				printf("��ʼ\n");
				SplitList(list1,&A,&B);
				break;
			case 11:
				printf("������������1\n");
				list2 = Tail_Creat_list();
// 				list2 = CreateRandList(13);
				Travel(list2);
				printf("������������2\n");
				list3 = Tail_Creat_list();
// 				list3 = CreateRandList(13);
				Travel(list3);
				printf("���Ϊ\n");
				list4 = AddCommonToList(list3,list2);
				Travel(list4);
                break;
			case 12:
				list6 = Tail_Creat_list();
				DeletR(list6);
				printf("ɾ���ɹ�\n");
				Travel(list6);
                break;
			case 13:
                // system("cls");
				printf("������������1����-1����\n");
				list2 =  Tail_Creat_list();
				
				Travel(list2);
				printf("������������2����-1����\n");
				list3 = Tail_Creat_list();
				Travel(list3);
				UnitList(&list2,list3);
				Travel(list2);
                break;

		}
	}
	return 0;
}
