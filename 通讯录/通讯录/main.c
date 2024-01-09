#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Contacts.h"

enum Function
{
	EXIT,
	ADD,
	DELETE,
	SEARCH,
	MODIFY,
	PRINT,
	SORT
};

void Catalogue()
{
	printf("************************0.EXIT***************************\n");
	printf("*****************1.ADD          2.DELETE*****************\n");
	printf("*****************3.SEARCH       4.MODIFY*****************\n");
	printf("*****************5.PRINT        6.SORT*******************\n");
}

int main()
{
	enum Function select;
	do {
		Catalogue();	//��ӡĿ¼
		printf("��ѡ��:");
		scanf("%d", &select);
		getchar(); 
		system("cls");
		switch (select)
		{
		case EXIT:
			break;
		case ADD: {
			add_Person();
			break;
		}
		case DELETE: {
			char dname[20];
			print_Contacts();
			printf("������Ҫɾ����ͨѶ�˵�����:");
			gets(dname);
			delete_Person(&dname);
			getchar();
			break;
		}
		case SEARCH: {
			char sname[20];
			printf("������Ҫ���ҵ�ͨѶ�˵�������");
			gets(sname);
			search_Person(&sname);
			getchar();
			break;
		}
		case MODIFY: {
			char mname[20];
			printf("������Ҫ�޸ĵ�ͨѶ�˵�������");
			gets(mname);
			modify_Conracts(&mname);
			getchar();
			break;
		}
		case PRINT: {
			print_Contacts();
			getchar();
			break;
		}
		case SORT: {
			break;
		}
		default: {
			printf("�������\n");
			getchar();
			break;
		}
		}
		system("cls");
	} while(select);

	return 0;
}