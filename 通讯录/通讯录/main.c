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
		Catalogue();	//打印目录
		printf("请选择:");
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
			printf("请输入要删除的通讯人的姓名:");
			gets(dname);
			delete_Person(&dname);
			getchar();
			break;
		}
		case SEARCH: {
			char sname[20];
			printf("请输入要查找的通讯人的姓名：");
			gets(sname);
			search_Person(sname);
			getchar();
			break;
		}
		case MODIFY: {
			char mname[20];
			printf("请输入要修改的通讯人的姓名：");
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
			printf("保存成功。\n");
			getchar();
			break;
		}
		default: {
			printf("输入错误。\n");
			getchar();
			break;
		}
		}
		system("cls");
	} while(select);

	return 0;
}