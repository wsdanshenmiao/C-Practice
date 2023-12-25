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
	//char* ret = strstr(p1, p2);	//子串存在则返回子串首字母地址，否则返回空指针，只返回第一次出现的地址
	char* ret = my_strstr(p1, p2);
	if (ret == NULL) {
		printf("子串不存在\n");
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
//	//if (*arr1 > *arr2) {	//VS实现方式
//	//	return 1;
//	//}
//	//else {
//	//	return -1;
//	//}
//	return *arr1 - *arr2;	//gcc实现方式
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
//	//找到\0
//	while (*dest != '\0') {
//		dest++;
//	}
//	//追加
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
//		return 1 + my_strlen2(++str);	//不能用str++，要先自加再使用
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
//	//strlen的返回值为size_t（unsigned int）类型，相减后依旧为正数
//	if (strlen("abcd") - strlen("abcdef") > 0) {
//		printf("正\n");
//	}
//	else {
//		printf("负\n");
//	}
//
//	return 0;
//}