#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "Contacts.h"

enum Function
{
	EXIT,
	ADD,
	DELETE,
	SEARCH,
	MODIFY,
	PRINT,
	SORT,
	SAVE
};

void Catalogue()
{
	printf("*****************0.EXIT         1.ADD********************\n");
	printf("*****************2.DELETE       3.SEARCH*****************\n");
	printf("*****************4.MODIFY       5.PRINT******************\n");
	printf("*****************6.SORT         7.SAVE*******************\n");
}

int main()
{
	enum Function select;
	contacts_Init();
	do {
		Catalogue();	//��ӡĿ¼
		printf("��ѡ��:");
		scanf("%d", &select);
		getchar(); 
		system("cls");
		switch (select)
		{
		case EXIT:
			save_Contacts();
			delete_Data();
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
			search_Person(sname);
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
		case SAVE: {
			save_Contacts();
			printf("����ɹ���\n");
			getchar();
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