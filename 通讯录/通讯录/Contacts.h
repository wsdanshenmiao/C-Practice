#ifndef __CONTACTS_H__
#define __CONTACTS_H__

typedef struct Contact_Person	//通讯人结构体
{
	int age;
	char sex[10];
	char tele[15];
	char name[20];
	char addr[30];
	struct Contact_Person* next;
}Contact_Person;

void contacts_Init();
void delete_Data();
void add_Person();
void delete_Person();
Contact_Person* search_Person(char* sname);
void modify_Conracts();
void print_Contacts();
void sort_Contacts();
void save_Contacts();

#endif // !__CONTACTS_H__

