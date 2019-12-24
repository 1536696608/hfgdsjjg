#include"grpAdjMatrix.h"
void strLTrim(char* str);


//*************************�������ļ�����ͼ**************************//
//* �������ܣ����ı��ļ������ڽӾ����ʾ��ͼ                        *//
//* ��ڲ���  char fileName[]���ļ���                               *//
//* ���ڲ�����                                                      *//
//* �� �� ֵ��bool��true�����ɹ���false����ʧ��                     *//
//* �� �� ����CreateGrpFromFile(char fileName[])                  *//
//*******************************************************************//
bool CreateGraphFromFile(char fileName[], Graph &G)
{
	FILE* pFile;      //����˳�����ļ�ָ��
	char str[1000];   //��Ŷ���һ���ı����ַ���
	char strTemp[10]; //�ж��Ƿ�ע����

	cellType  eWeight;     //�ߵ���Ϣ����Ϊ�ߵ�Ȩֵ
	GraphKind GrpType;  //ͼ����ö�ٱ���

	pFile=fopen(fileName,"r");
	if(!pFile)
	{

		printf("�����ļ�%s��ʧ�ܡ�\n",fileName);
		return false;
	}

	while(fgets(str,1000,pFile)!=NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0]=='\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //����ע����
			continue;
		else  //��ע���С��ǿ��У�����ѭ��
			break;
	}

    //ѭ��������str��Ӧ���Ѿ����ļ���ʶ���ж��ļ���ʽ
	if(strstr(str,"Graph")==NULL)
	{
		printf("���󣺴򿪵��ļ���ʽ����\n");
		fclose(pFile); //�ر��ļ�
		return false;
	}

	//��ȡͼ�����ͣ���������
	while(fgets(str,1000,pFile)!=NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0]=='\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;		
		else  //�ǿ��У�Ҳ��ע���У���ͼ�����ͱ�ʶ
			break;
	}
    
    //����ͼ������
	if(strstr(str,"UDG"))
		GrpType=UDG;  //����ͼ
	else if(strstr(str,"UDN"))
		GrpType=UDN;  //������
	else if(strstr(str,"DG"))
		GrpType=DG;   //����ͼ
	else if(strstr(str,"DN"))
		GrpType=DN;   //������
	else
	{
		printf("���󣺶�ȡͼ�����ͱ��ʧ�ܣ�\n");
		fclose(pFile); //�ر��ļ�
		return false;
	}

	//��ȡ����Ԫ�أ���str����������
	while(fgets(str,1000,pFile)!=NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0]=='\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;		
		else  //�ǿ��У�Ҳ��ע���У���ͼ�Ķ���Ԫ����
			break;
	}

    //�������ݷ���ͼ�Ķ�������	
	char* token=strtok(str," ");
	int nNum=1;	
	while(token!=NULL)
	{
		G.Data[nNum]=*token; // atoi(token);	//��������ת��Ϊ��������Ϊ�ַ�����ת��		
        token = strtok( NULL, " ");
		nNum++;
	}
	nNum--;   //������

    //ͼ���ڽӾ����ʼ��
	int nRow=1;  //�������±꣬��1��ʼ
	int nCol=1;  //�������±꣬��1��ʼ
	if(GrpType==UDG || GrpType==DG)
	{
		for(nRow=1;nRow<=nNum;nRow++)
			for(nCol=1;nCol<=nNum;nCol++)
				G.AdjMatrix[nRow][nCol]=0;
	}
	else
	{
		for(nRow=1;nRow<=nNum;nRow++)
			for(nCol=1;nCol<=nNum;nCol++)
				G.AdjMatrix[nRow][nCol]=INF;  //INF��ʾ�����
	}
	
	//ѭ����ȡ�ߵ����ݵ��ڽӾ���

	int edgeNum=0;  //�ߵ�����
	elementType Nf,Ns; //�߻򻡵�2�����ڶ���
	while(fgets(str,1000,pFile)!=NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0]=='\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;

		char* token=strtok(str," ");  //�Կո�Ϊ�ָ������ָ�һ�����ݣ�д���ڽӾ���
		
		if(token==NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}
		Nf=*token;  //��ȡ�ߵĵ�һ������
		
		token = strtok( NULL, " ");  //��ȡ��һ���Ӵ������ڶ�������
		if(token==NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}

		Ns=*token;  //��ȡ�ߵĵڶ�������
            //�ӵ�һ�������ȡ�к�		
		for(nRow=1;nRow<=nNum;nRow++)
		{
			if(G.Data[nRow]==Nf)  //�Ӷ����б��ҵ���һ������ı��
				break;
		}
           //�ӵڶ��������ȡ�к�		
		for(nCol=1;nCol<=nNum;nCol++)
		{
			if(G.Data[nCol]==Ns)  //�Ӷ����б��ҵ��ڶ�������ı��
				break;
		}

		//���Ϊ������ȡȨֵ
		if(GrpType==UDN || GrpType==DN)
		{
			token = strtok( NULL, " ");  //��ȡ��һ���Ӵ������ߵĸ�����Ϣ����Ϊ�ߵ�Ȩ��
			if(token==NULL)  //�ָ�Ϊ�մ���ʧ���˳�
			{
				printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
				fclose(pFile); //�ر��ļ�
				return false;
			}
			eWeight=atoi(token);  //ȡ�ñߵĸ�����Ϣ
		}
		if(GrpType==UDN || GrpType==DN)  //���Ϊ�����ڽӾ����ж�Ӧ�ı�����Ȩֵ��������Ϊ1
			G.AdjMatrix[nRow][nCol]=eWeight;
		else
			G.AdjMatrix[nRow][nCol]=1;  //atoi(token);	//�ַ���תΪ����

		edgeNum++;   //������1
	}

    G.VerNum=nNum;  //ͼ�Ķ�����
	if(GrpType==UDG || GrpType==UDN)
		G.ArcNum=edgeNum / 2;  //����ͼ�����ı�������ͳ�Ƶ����ֳ�2  
	else
		G.ArcNum=edgeNum;

	G.gKind=GrpType;  //ͼ������

	fclose(pFile); //�ر��ļ�
	printf("�����ɹ�\n");
	return true;
}

//ɾ���ַ������ַ�������߿ո�
void strLTrim(char* str)
{
	int i,j;
	int n=0;
	n=strlen(str)+1;
	for(i=0;i<n;i++)
	{
		if(str[i]!=' ')  //�ҵ������һ���ǿո�λ��
			break;
	}
	    //�Ե�һ���ǿո��ַ�Ϊ���ַ��ƶ��ַ���
	for(j=0;j<n;j++)
	{
		str[j]=str[i];
		i++;
	}
	
}
