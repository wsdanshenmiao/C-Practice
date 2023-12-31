#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

enum Message
{
	Name,
	Age,
	Sex,
	Tele,
	Addr
};
typedef struct Contact_Person	//通讯人结构体
{
	int age;
	char sex[10];
	char tele[15];
	char name[20];
	char addr[30];
	struct Contact_Person* next;
}Contact_Person;
Contact_Person* first = NULL;

void Message()
{
	printf("*************************0.姓名*************************\n");
	printf("******************1.年龄        2.性别******************\n");
	printf("******************3.电话        4.地址******************\n");
}

void add_Person()
{
	printf("请输入通讯人信息。\n");
	Contact_Person* new_node;	//新的通讯人结点
	new_node = malloc(sizeof(Contact_Person));
	if (new_node == NULL) {
		printf("内存不足。\n");
		return;
	}
	printf("姓名:");
	scanf("%s", &new_node->name);
	printf("年龄:");
	scanf("%d", &new_node->age);
	printf("性别:");
	scanf("%s", &new_node->sex);
	printf("电话:");
	scanf("%s", &new_node->tele);
	printf("地址:");
	scanf("%s", &new_node->addr);
	new_node->next = first;
	first = new_node;
}

void delete_Person(char* dname)	//删除结点，使前一个结点跳过后一个节点，并释放后一个结点的内存
{
	Contact_Person* pre;
	Contact_Person* dnode;
	//这里要注意判断是否为NULL在前，否则若是遇到NULL会先把NULL传入strcmp，导致程序错误
	for (pre = NULL, dnode = first; dnode != NULL && strcmp(dnode->name, dname);
		pre = dnode, dnode = dnode->next);	//寻找要删除的结点
	if (dnode) {
		if (pre) {	//判断是否为第一个结点
			pre->next = dnode->next;
		}
		else {
			first = dnode->next;
		}
		free(dnode);
		dnode = NULL;
		printf("已删除。\n");
	}
	else {
		printf("无此通讯人。\n");
	}
}

Contact_Person* search_Person(char* sname)	//查找通讯人
{
	Contact_Person* snode = first;
	if (snode) {
		for (; snode && strcmp(snode->name, sname); snode = snode->next);
		if (snode) {
			printf("姓名		年龄		性别		电话			地址			\n");
			printf("%-16s%-16d%-16s%-24s%-24s\n", snode->name, snode->age, snode->sex
				, snode->tele, snode->addr);
		}
		else {
			printf("无此通讯人。\n");
			return NULL;	
		}
	}
	else {
		printf("无此通讯人。\n");	//未查到通讯人返回NULL
		return NULL;
	}
	return snode;
}

void modify_Conracts(char* mname)
{
	enum Message message;
	Contact_Person* mnode;
	if (*mname && mname) {
		 mnode = search_Person(mname);
	}
	else {
		printf("无此通讯人。\n");
		return;
	}
	if (mnode == NULL) {
		return;
	}
	Message();
	printf("请选择要修改的信息:");
	scanf("%d", &message);
	switch (message)
	{
	case Name:
		printf("请输入要修改的信息：");
		scanf("%s", &mnode->name);
		break;
	case Age:
		printf("请输入要修改的信息：");
		scanf("%d", &mnode->age);
		break;
	case Sex:
		printf("请输入要修改的信息：");
		scanf("%s", &mnode->sex);
		break;
	case Tele:
		printf("请输入要修改的信息：");
		scanf("%s", &mnode->tele);
		break;
	case Addr:
		printf("请输入要修改的信息：");
		scanf("%s", &mnode->addr);
		break;
	default:
		printf("输入错误。\n");
		break;
	}
}

void print_Contacts()	//打印通讯录
{
	Contact_Person* node;
	for (node = first; node; node = node->next) {	//从起始开始，结点向后移，遇到NULL停止
		printf("姓名		年龄		性别		电话			地址			\n");
		printf("%-16s%-16d%-16s%-24s%-24s\n", node->name, node->age, node->sex
											, node->tele, node->addr);
	}
}