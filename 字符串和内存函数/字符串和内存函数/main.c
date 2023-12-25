#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include <stdio.h>
#include <string.h>

char* my_strstr(const char* string, const char* substring)
{
	assert(string && substring);
	if (substring == NULL) {
		return string;
	}
	char* ret;
	char* store_Substring = substring;
	while (*string) {
		while (*string != *substring) {
			if (!*string) {
				return NULL;
			}
			string++;
		}
		ret = string;
		while (*substring) {
			if (!*string) {
				return NULL;
			}
			if (*string == *substring) {
				string++;
				substring++;
			}
			else {
				break;
			}
		}
		if (*substring == '\0') {
			return ret;
		}
		substring = store_Substring;
	}
	return NULL;
}

int main()
{
	char* p1 = "I get CLANNAD,CLANNAD";
	char* p2 = "CLANNAD";
	//char* ret = strstr(p1, p2);	//�Ӵ������򷵻��Ӵ�����ĸ��ַ�����򷵻ؿ�ָ�룬ֻ���ص�һ�γ��ֵĵ�ַ
	char* ret = my_strstr(p1, p2);
	if (ret == NULL) {
		printf("�Ӵ�������\n");
	}
	else {
		printf("%s", ret);
	}
	return 0;
}

//char* my_strncpy(char* dest, const char* sourse,unsigned int count)
//{
//	assert(dest && sourse);
//	char* ret = dest;
//	while (count && (*dest++ = *sourse++) != '\0') {
//		count--;
//	}
//	while (count--) {
//		*dest++ = '\0';
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "abcdefghijklmn";
//	char arr2[] = "clannad";
//	my_strncpy(arr1, arr2, 9);
//	printf("%s", arr1);
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//int my_strcmp(const char* arr1, const char* arr2)
//{
//	assert(arr1 && arr2);
//	while (*arr1 == *arr2) {
//		if (*arr1 == '\0') {
//			return 0;
//		}
//		arr1++;
//		arr2++;
//	}
//	//if (*arr1 > *arr2) {	//VSʵ�ַ�ʽ
//	//	return 1;
//	//}
//	//else {
//	//	return -1;
//	//}
//	return *arr1 - *arr2;	//gccʵ�ַ�ʽ
//}
//
//int main()
//{
//	const char* p1 = "abcefg";
//	const char* p2 = "qwert";
//	int ret = my_strcmp(p1, p2);
//	printf("%d", ret);
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//
//#include <string.h>
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strcat(char* dest, const char* sourse)
//{
//	assert(dest && sourse);
//	char* ret = dest;
//	//�ҵ�\0
//	while (*dest != '\0') {
//		dest++;
//	}
//	//׷��
//	while (*dest++ = *sourse++);
//	return ret;
//}
//
//int main()
//{
//	char arr1[30] = "I love ";
//	char arr2[] = "CLANNAD";
//	my_strcat(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//
//#include <string.h>
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strcpy(char* dest, const char* source)
//{
//	assert(dest != NULL);
//	assert(source != NULL);
//	char* ret = dest;
//	while (*dest++ = *source++);
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "abcdefghijklmnopq";
//	char arr2[] = "I love CLANNAD";
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//int my_strlen1(const char* str)
//{
//	assert(str != NULL);
//	int count = 0;
//	while (*str) {
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int my_strlen2(const char* str)
//{
//	assert(str != NULL);
//	if (*str) {
//		return 1 + my_strlen2(++str);	//������str++��Ҫ���Լ���ʹ��
//	}
//	else {
//		return 0;
//	}
//}
//
//int main()
//{
//	printf("%d\n", my_strlen1("abcdef"));
//	printf("%d\n", my_strlen2("abcdef"));
//
//	//strlen�ķ���ֵΪsize_t��unsigned int�����ͣ����������Ϊ����
//	if (strlen("abcd") - strlen("abcdef") > 0) {
//		printf("��\n");
//	}
//	else {
//		printf("��\n");
//	}
//
//	return 0;
//}