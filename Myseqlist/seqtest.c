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
		printf("0�������˳���\n");
		printf("10���ɵ���˳���\n");
		printf("11����\n");
		printf("1�õ���n��Ԫ�ص�ֵ\n");
		printf("2����Ԫ�ص���n�������󷵻�-1���ɹ�����1\n");
		printf("3ɾ����iԪ��\n");
		printf("4�����������Ԫ��\n");
		printf("5��ֳ�������ż��\n");
		printf("6�ҵ���������AB֮�еĹ���Ԫ�ط���C\n");
		printf("7ɾ������������ظ�Ԫ��\n");
		printf("����-1�˳�\n");
		printf("**************************\n");
		printf("������Ŀ���");
		
		scanf("%d",&point);
		switch(point)
		{
			case 1:
				
				printf("����ѡȡ�±�\n");
				scanf("%d",&k);
				j = GetValue(test,k);
				printf("value = %d\n",j);
				break;
			case 2:
				printf("���������λ�ã�Ԫ��\n");
				scanf("%d%d",&m,&k);
				Insert(test,m,k);
				break;
			case 3:
				fflush(stdin);
				printf("������ɾ��λ��\n");
				scanf("%d",&l);
				Delet(test,l);
				break;
			case 4:
				printf("�����������Ԫ��\n");
				scanf("%d",&l);
				InsertSeq(test,l);
				break;
			case 5:
				SplitJandO(test);break;
			case 6:
				printf("����˳���1Ԫ�أ�-1����\n");
				scanf("%d",&m);
				initialList(test);
				initialList(test2);
				
				while(m != -1)
				{
					
					test->array[test->len] = m;
					test->len++;
					scanf("%d",&m);
				}
				printf("����˳���2Ԫ�أ�-1����\n");
				scanf("%d",&m);
				while(m != -1)
				{
					test2->array[test2->len] = m;
					test2->len++;
					scanf("%d",&m);
				}
				printf("���Ϊ\n");
				Travel(Addcommon(test,test2));break;
			case 7:
				printf("����Ԫ��\n");
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
				printf("����Ԫ�ظ������������˳���,100����\n");
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
				printf("����Ԫ�ظ������������˳���,100����\n");
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
