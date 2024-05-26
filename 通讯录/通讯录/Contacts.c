#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <io.h>

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

void contacts_Init()
{
	size_t condition;
	Contact_Person* node, * pre;
	FILE* pfr;
	if (_access("contact.dat", 0)) {
		pfr = fopen("contact.dat", "wb");
	}
	else {
		pfr = fopen("contact.dat", "rb");
	}
	first = malloc(sizeof(Contact_Person));
	condition = fread(first, sizeof(Contact_Person), 1, pfr);
	if (!condition) {
		free(first);
		first = NULL;
		return;
	}
	for (pre = first, node = malloc(sizeof(Contact_Person)), first->next = node;
		fread(node, sizeof(Contact_Person), 1, pfr);
		pre = node, node = malloc(sizeof(Contact_Person)), pre->next = node);
	free(node);
	node = NULL;
	pre->next = NULL;
	fclose(pfr);
	pfr = NULL;
}

void Message()
{
	printf("*************************0.姓名*************************\n");
	printf("******************1.年龄        2.性别******************\n");
	printf("******************3.电话        4.地址******************\n");
}

void delete_Data()
{
	Contact_Person* pre, * dnote;
	for (pre = NULL, dnote = first; dnote;) {
		pre = dnote;
		dnote = dnote->next;
		free(pre);
		pre = NULL;
	}
	first = NULL;
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

int LinkCmp(const void* e1, const void* e2)
{
	return (*((Contact_Person*)e1)).age - (*((Contact_Person*)e2)).age;
}

void sort_Contacts()
{
#if 1
	Contact_Person* after;
	Contact_Person* node;
	Contact_Person* pre;
	int count;
	int i;
	for (count = 0, node = first; node; node = node->next, count++);
	if (first && first->next) {
		for (i = count - 1; i; i--) {
			int j;
			for (pre = NULL, node = first, after = first->next, j = i - 1; j; j--) {
				if (strcmp(after->name, node->name) < 0) {
					Contact_Person* temp = after->next;
					if (pre) {
						pre->next = after;
						after->next = node;
						node->next = temp;
					}
					else {
						first = after;
						after->next = node;
						node->next = temp;
					}
					pre = after, after = node->next;
				}
				else {
					pre = node, node = after, after = after->next;
				}
			}
		}
	}
#else	//失败
	Contact_Person* node;
	int count;
	int i;
	for (count = 0, node = first; node; node = node->next, count++);	//计算数据个数
	Contact_Person** LinkNode = malloc(count  * sizeof(Contact_Person*));	//创建一个数组储存链表节点
	if (LinkNode == NULL) {
		return;
	}
	for (i = 0, node = first; i < count; i++, node = node->next) {
		LinkNode[i] = node;	//将节点储存到数组中
	}
	qsort(LinkNode, count, sizeof(Contact_Person*), LinkCmp);	//对链表进行排序
	first = LinkNode[0];
	for (i = 1, node = first; i < count; i++, node = node->next) {
		node->next = LinkNode[i];
	}
	node = NULL;
	free(LinkNode);
	LinkNode = NULL;
#endif
}

void save_Contacts()
{
	Contact_Person* snode;
	FILE* pfw = fopen("contact.dat", "wb");	//创建文件
	if (pfw == NULL) {
		printf("%s", strerror(errno));
		return;
	}
	for (snode = first; snode; snode = snode->next) {	//将数据存入文件中，遇到NULL时停止
		fwrite(snode, sizeof(Contact_Person), 1, pfw);
	}
	fclose(pfw);
	pfw = NULL;
}