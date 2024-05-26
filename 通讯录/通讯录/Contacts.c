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
typedef struct Contact_Person	//ͨѶ�˽ṹ��
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
	printf("*************************0.����*************************\n");
	printf("******************1.����        2.�Ա�******************\n");
	printf("******************3.�绰        4.��ַ******************\n");
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
	printf("������ͨѶ����Ϣ��\n");
	Contact_Person* new_node;	//�µ�ͨѶ�˽��
	new_node = malloc(sizeof(Contact_Person));
	if (new_node == NULL) {
		printf("�ڴ治�㡣\n");
		return;
	}
	printf("����:");
	scanf("%s", &new_node->name);
	printf("����:");
	scanf("%d", &new_node->age);
	printf("�Ա�:");
	scanf("%s", &new_node->sex);
	printf("�绰:");
	scanf("%s", &new_node->tele);
	printf("��ַ:");
	scanf("%s", &new_node->addr);
	new_node->next = first;
	first = new_node;
}

void delete_Person(char* dname)	//ɾ����㣬ʹǰһ�����������һ���ڵ㣬���ͷź�һ�������ڴ�
{
	Contact_Person* pre;
	Contact_Person* dnode;
	//����Ҫע���ж��Ƿ�ΪNULL��ǰ��������������NULL���Ȱ�NULL����strcmp�����³������
	for (pre = NULL, dnode = first; dnode != NULL && strcmp(dnode->name, dname);
		pre = dnode, dnode = dnode->next);	//Ѱ��Ҫɾ���Ľ��
	if (dnode) {
		if (pre) {	//�ж��Ƿ�Ϊ��һ�����
			pre->next = dnode->next;
		}
		else {
			first = dnode->next;
		}
		free(dnode);
		dnode = NULL;
		printf("��ɾ����\n");
	}
	else {
		printf("�޴�ͨѶ�ˡ�\n");
	}
}

Contact_Person* search_Person(char* sname)	//����ͨѶ��
{
	Contact_Person* snode = first;
	if (snode) {
		for (; snode && strcmp(snode->name, sname); snode = snode->next);
		if (snode) {
			printf("����		����		�Ա�		�绰			��ַ			\n");
			printf("%-16s%-16d%-16s%-24s%-24s\n", snode->name, snode->age, snode->sex
				, snode->tele, snode->addr);
		}
		else {
			printf("�޴�ͨѶ�ˡ�\n");
			return NULL;	
		}
	}
	else {
		printf("�޴�ͨѶ�ˡ�\n");	//δ�鵽ͨѶ�˷���NULL
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
		printf("�޴�ͨѶ�ˡ�\n");
		return;
	}
	if (mnode == NULL) {
		return;
	}
	Message();
	printf("��ѡ��Ҫ�޸ĵ���Ϣ:");
	scanf("%d", &message);
	switch (message)
	{
	case Name:
		printf("������Ҫ�޸ĵ���Ϣ��");
		scanf("%s", &mnode->name);
		break;
	case Age:
		printf("������Ҫ�޸ĵ���Ϣ��");
		scanf("%d", &mnode->age);
		break;
	case Sex:
		printf("������Ҫ�޸ĵ���Ϣ��");
		scanf("%s", &mnode->sex);
		break;
	case Tele:
		printf("������Ҫ�޸ĵ���Ϣ��");
		scanf("%s", &mnode->tele);
		break;
	case Addr:
		printf("������Ҫ�޸ĵ���Ϣ��");
		scanf("%s", &mnode->addr);
		break;
	default:
		printf("�������\n");
		break;
	}
}

void print_Contacts()	//��ӡͨѶ¼
{
	Contact_Person* node;
	for (node = first; node; node = node->next) {	//����ʼ��ʼ���������ƣ�����NULLֹͣ
		printf("����		����		�Ա�		�绰			��ַ			\n");
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
#else	//ʧ��
	Contact_Person* node;
	int count;
	int i;
	for (count = 0, node = first; node; node = node->next, count++);	//�������ݸ���
	Contact_Person** LinkNode = malloc(count  * sizeof(Contact_Person*));	//����һ�����鴢������ڵ�
	if (LinkNode == NULL) {
		return;
	}
	for (i = 0, node = first; i < count; i++, node = node->next) {
		LinkNode[i] = node;	//���ڵ㴢�浽������
	}
	qsort(LinkNode, count, sizeof(Contact_Person*), LinkCmp);	//�������������
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
	FILE* pfw = fopen("contact.dat", "wb");	//�����ļ�
	if (pfw == NULL) {
		printf("%s", strerror(errno));
		return;
	}
	for (snode = first; snode; snode = snode->next) {	//�����ݴ����ļ��У�����NULLʱֹͣ
		fwrite(snode, sizeof(Contact_Person), 1, pfw);
	}
	fclose(pfw);
	pfw = NULL;
}