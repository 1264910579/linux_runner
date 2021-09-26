#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define BKCONT 50



typedef struct book
{
	char name[20];               //������Ա
	char writer[20];             //���߳�Ա
	char number[20];             //��ų�Ա
	int  hot;                    //�ȶȳ�Ա
	int  sc;                     //����Ա
	float price;	             //�۸��Ա
}BOOK;




void show(void);
void passward(void);
void key_scan(void);
void ch_passwd(void);
void add_book(void);
void search_book(void);
void hot_book(void);
void back_book(void);

char sys_passward[10] = "123456";
BOOK bks[BKCONT];



int main(void)
{
	//�����¼����
	passward();
	while(1)
	{
		
		//������ʾ����
		show();
		//����ѡ����
		key_scan();	
	}

	
	return 0;
}


/***********************************************
*������    ��show
*��������  ����ʾͼ�����ϵͳ��������
*��������  ����
*��������ֵ����
*��������  ��
***********************************************/
void show(void)
{
	printf("-------------------------------------------------\n");
	printf("|          ��ӭ����ͼ�����ϵͳ                 |\n");
	printf("-------------------------------------------------\n");
	printf("|        ��1������      ��2������               |\n");
	printf("|        ��3���ȶ����а�4���������           |\n");
	printf("|        ��5�������޸�  ��0���˳�����           |\n");
	printf("-------------------------------------------------\n");
	printf("��ѡ��");
	
}



/***********************************************
*������    ��passward
*��������  �������¼����
*��������  ����
*��������ֵ����
*��������  ��
***********************************************/
void passward(void)
{
	int i = 0;
	char user_passward[10];
	int cont = 0;
	
	printf("������ϵͳ��¼����\n");
STAR:	
	for(i=0;i<10;i++)
	{
		user_passward[i] = getch();
		//���س���ɾ������ʾ*
		if(user_passward[i] != 13 && user_passward[i] != 8)
		{
			printf("*");
		}
		
		//���س��������� ��ӽ����ַ�
		if(user_passward[i] == 13)
		{
			//���س��滻Ϊ������
			user_passward[i] = '\0';
			break;
		}

		//��ɾ����
		if(user_passward[i] == 8)
		{
			//����
			i-=2;       //�ص�Ҫɾ�����ַ���ǰһ���ַ�λ��
			if(i<=-1)   //��ֹ�û�һֱ��ɾ�����³������
			{
				i = -1;
			}
			//������ʾ
			printf("\b");
			printf(" ");
			printf("\b");	
		}
	
	}
	
	//�Ա�����
	if(strcmp(user_passward,sys_passward)!= 0)
	{
		system("cls");
		cont++;
		if(cont == 5)
		{
			printf("���������������ﵽ5�Σ��밴������˳�ϵͳ\n\a\a\a");
			getch();
			exit(1);
		}
		printf("�����������������\n");
		goto STAR;
	}
	
	system("cls");
}







/************************************************
*������    ��key_scan
*��������  ������ʶ����
*��������  ����
*��������ֵ����
*��������  ����
***************************************************/
void key_scan(void)
{
	char key;
STAR:
	key = getch();
	system("cls");
	switch(key)
	{
		case '1':search_book();break;
		case '2':back_book();break;
		case '3':hot_book();break;
		case '4':add_book();break;
		case '5':ch_passwd();break;
		case '0':exit(1);break;
		default:printf("������������������������\n");goto STAR;break;
		
	}
	
	system("cls");
}


/************************************************
*������    ��ch_passwd
*��������  ���޸�����
*��������  ����
*��������ֵ����
*��������  ����
***************************************************/
void ch_passwd(void)
{
	int i,j;
	char ch_passward[2][10];
	
	
	/*����ԭ����*/
	passward();
SA:	
	/*�޸��������*/
	for(j=0;j<2;j++)
	{
		printf("\n�������%d������\n",j+1);
		for(i=0;i<10;i++)
		{
			ch_passward[j][i] = getch();
			//���س���ɾ������ʾ*
			if(ch_passward[j][i] != 13 && ch_passward[j][i] != 8)
			{
				printf("*");
			}
			
			//���س��������� ��ӽ����ַ�
			if(ch_passward[j][i] == 13)
			{
				//���س��滻Ϊ������
				ch_passward[j][i] = '\0';
				break;
			}

			//��ɾ����
			if(ch_passward[j][i] == 8)
			{
				//����
				i-=2;       //�ص�Ҫɾ�����ַ���ǰһ���ַ�λ��
				if(i<=-1)   //��ֹ�û�һֱ��ɾ�����³������
				{
					i = -1;
				}
				//������ʾ
				printf("\b");
				printf(" ");
				printf("\b");	
			}
		}
	}

	/*�Ա����������Ƿ�һ��*/
	if(strcmp(ch_passward[0],ch_passward[1])!=0)
	{
		system("cls");
		printf("��������������벻һ�£�����������\n");
		goto SA;
		
	}
	else
	{
		system("cls");
		//���µ����븴�Ƹ�ԭ��������
		strcpy(sys_passward,ch_passward[0]);
		printf("�����޸ĳɹ��������µ�¼ϵͳ\n");
		passward();
	}

}




/************************************************
*������    ��add_book
*��������  ��������麯��
*��������  ����
*��������ֵ����
*��������  ������˺�������������鵽������
***************************************************/
void add_book(void)
{
	
	static int i = 0;
	
	while(i<BKCONT)
	{
		printf("�������%d������:\n",i+1);
		scanf("%s",bks[i].name);
		printf("�������%d��������:\n",i+1);
		scanf("%s",bks[i].writer);
		printf("�������%d�����:\n",i+1);
		scanf("%s",bks[i].number);
		printf("�������%d���ȶ�:\n",i+1);
		scanf("%d",&bks[i].hot);
		printf("�������%d�����:\n",i+1);
		scanf("%d",&bks[i].sc);
		printf("�������%d���۸�:\n",i+1);
		scanf("%f",&bks[i].price);
		i++;
		
		printf("�Ƿ�������룬�����밴��y�� �˳����������\n");
		if(getch() != 'y')
		{
			break;
		}		
	}
	
	system("cls");

}




/************************************************
*������    ��search_book
*��������  ������ͼ��
*��������  ����
*��������ֵ����
*��������  �����ַ�ʽ����ͼ��
***************************************************/
void search_book(void)
{
	char k;
	int i = 0;
	char book_name[30] = {0};
	char book_num[30] = {0};
	int cont = 0;
	int q;
	
	
	printf("-------------------------------------------------\n");
	printf("|                ������ʽ����                    |\n");
	printf("-------------------------------------------------\n");
	printf("|               ��1��ȫ������                    |\n");
	printf("|               ��2������������                  |\n");
	printf("|               ��3�������߼���                  |\n");
	printf("|               ��0������ֵ������                |\n");
	printf("-------------------------------------------------\n");
	printf("��ѡ��");
SR:	
	k = getch();
	system("cls");
	if(k == '1')                    //ȫ������
	{
		while(bks[i].name[0] != '\0')
		{
			printf("����:%s\n����:%s\n���:%s\n�ȶ�:%d\n���:%d\n�۸�:%0.2f\n",
				bks[i].name,bks[i].writer,bks[i].number,bks[i].hot,bks[i].sc,bks[i].price);
				printf("\n");
			i++;
		}
		printf("�����������������\n");
		getch();	
	}
	
	else if(k == '2')               //����������
	{
		RT:
		system("cls");
		printf("������Ҫ���ҵ�������\n");
		scanf("%s",book_name);
		//����������Ч��
		while(bks[i].name[0]!= '\0')
		{
			if(strcmp(bks[i].name,book_name) == 0)
			{
				q = i;
				//��ӡ������������
				printf("����:%s\n����:%s\n���:%s\n�ȶ�:%d\n���:%d\n�۸�:%0.2f\n",
				bks[i].name,bks[i].writer,bks[i].number,bks[i].hot,bks[i].sc,bks[i].price);
				printf("\n");
				cont++;
			}
			i++;
		}
		
		
		//�����ҵ���ı�������
		if(cont == 0)                                             //û����
		{
			printf("û�з���Ҫ����飬����֪ͨ����Ա\n");
			printf("����y�����²��ң�����������������ֵ������\n");
			if(getch() == 'y')
			{
				goto RT;
			}
		}
		else if(cont == 1)                                       //һ����
		{
			printf("�ҵ�%d������Ҫ�����\n",cont);
			printf("�����밴��j��,�����������밴����������\n");
			if(getch()=='j')
			{
				if(bks[q].sc == 0)
				{
					printf("��ͼ���Ѿ������꣬��ȴ�...�����������������\n");
					getch();
				}
				else
				{
					bks[q].hot++;
					bks[q].sc--;
					printf("���ĳɹ��������������������\n");
					getch();
				}	
			}
			
		}
		else                                                     //�౾��
		{
			printf("�ҵ�%d������Ҫ�����\n",cont);
			printf("�����밴��j��,�����������밴����������\n");
			if(getch() == 'j')
			{
				printf("��������Ҫ���ĵı��\n");
				QST:
				scanf("%s",book_num);
				i = 0;
				while(bks[i].name[0] != '\0')
				{
					if(strcmp(bks[i].number,book_num) == 0)
					{
						break;
					}
					i++;
				}
				//i��ֵ���Ǵ˱�ŵ�����±�
				//��֤�û�����ı���Ƿ���ȷ
				if(strcmp(bks[i].name,book_name) == 0)
				{
					if(bks[i].sc == 0)
					{
						printf("��ͼ���Ѿ������꣬��ȴ�...�����������������\n");
						getch();
					}
					else
					{
						bks[i].hot++;
						bks[i].sc--;
						printf("���ĳɹ��������������������\n");
						getch();
					}
					
				}
				else
				{
					printf("������ı����������������\n");
					goto QST;
				}

			}
		}
	}
	
	
	else if(k == '3')               //������������
	{
		
	}
	else if(k == '0')
	{
		//�ص�������
		return;
	}
	else
	{
		printf("�������������������������\n");
		goto SR;
	}

}


/************************************************
*������    ��hot_book
*��������  ���ȶ�����
*��������  ����
*��������ֵ����
*��������  ��
***************************************************/
void hot_book(void)
{
	int n = 0;
	int i = 0;
	int j;
	BOOK temp;
	
	
	//�������Ч��ı���
	while(bks[i].name[0]!= '\0')
	{
		n++;
		i++;
	}
	//n����������Ч��ı���
	//����
	
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(bks[j].hot < bks[j+1].hot)
			{
				//����Ԫ�ص�λ��
				temp = bks[j];
				bks[j] = bks[j+1];
				bks[j+1] = temp;
				
			}
			
		}
	}
	
	i = 0;
	//��ӡ����������
	while(bks[i].name[0] != '\0')
	{
		printf("����:%s\n����:%s\n���:%s\n�ȶ�:%d\n���:%d\n�۸�:%0.2f\n",
			bks[i].name,bks[i].writer,bks[i].number,bks[i].hot,bks[i].sc,bks[i].price);
			printf("\n");
		i++;
	}
	printf("�����������������\n");
	getch();	
}


/************************************************
*������    ��back_book
*��������  �����麯��
*��������  ����
*��������ֵ����
*��������  ����
***************************************************/
void back_book(void)
{
	int i = 0;
	int cont = 0;
	char book_num[30];
BSTA:
	printf("��������Ҫ����ı��\n");
	scanf("%s", book_num);
	while(bks[i].name[0] != '\0')
	{
		if(strcmp(bks[i].number,book_num) == 0)
		{
			cont++;
			printf("����:%s\n����:%s\n���:%s\n�ȶ�:%d\n���:%d\n�۸�:%0.2f\n",
			bks[i].name,bks[i].writer,bks[i].number,bks[i].hot,bks[i].sc,bks[i].price);
			break;
		}
		i++;
	}
	//i���Ǵ˱�ŵ�����±�
	if(cont == 0)    
	{ 
		printf("������ı����������������\n");
		goto BSTA;
	}
	else
	{
		printf("ȷ���밴��y��,���ذ�����������");
		if(getch() == 'y')
		{
			bks[i].sc++;
			printf("����ɹ�,�������鰴��b��,���ؽ��水����������\n");
			if(getch() == 'b')
			{
				cont  = 0;
				goto BSTA;
			}	
		}
	}

}


