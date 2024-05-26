#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
int main()
{
	char str[] = "- This, a sample string.";
	char* pch;
	printf("Splitting string \"%s\" into tokens:\n", str);
	pch = strtok(str, " ,.-");
	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
	}
	return 0;
}

//#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>
//#include <assert.h>
//
//int main()
//{
//	int arr1[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int arr2[] = { 0,1,3,6,3,4,8 };
//	printf("%d", memcmp(arr1, arr2, 3 * sizeof(arr1[0])));
//	int arr3[10] = { 0 };
//	memset(arr3, 1, 40);
//	return 0;
//}

//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	size_t i;
//	void* ret = dest;
//	if (dest < src) {
//		for (i = 0; i < num; i++) {
//			*((char*)dest + i) = *((char*)src + i);
//		}
//	}
//	else {
//		for (i = num; i > 0; i--) {
//			*((char*)dest + i - 1) = *((char*)src + i - 1);
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr1[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int* arr2 = malloc(sizeof(arr1));
//	//memcpy(arr2, arr1,sizeof(arr1));	//内存拷贝，c语言标准只需拷贝内存不重叠的情况，VS编译器下也可拷贝重叠情况
//	//memmove(arr1, arr1 + 3, 20);	//可处理内存重叠的情况
//	my_memmove(arr1 + 3, arr1, 20);
//	for (int i = 0; i < sizeof(arr1)/sizeof(arr1[0]); i++) {
//		printf("%d\n", arr1[i]);
//	}
//	return  0;
//}

//#include <stdio.h>
//#include <ctype.h>
//
//int main()
//{
//	////字符分类函数
//	//char ch = '4';
//	////int ret = islower(ch);
//	//int ret = isdigit(ch);
//	//printf("%d\n", ret);
//
//	//字符转换函数
//	//char ch = tolower('Q');
//	//char ch = toupper('q');
//	//printf("%c\n", ch);
//	char arr[] = "I Love Clannad";
//	for (int i = 0; arr[i++];) {
//		if (islower(arr[i])) {
//			arr[i] = toupper(arr[i]);
//		}
//	}
//	printf("%s", arr);
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//
//int main()
//{
//	////错误码  错误信息
//	////0       No error
//	////1       Operation not permitted
//	////2       No such file or directory
//	////...
//	////errno是一个全局的错误变量
//	////当C语言的库函数执行错误时，会把对应错误码赋值到errno中
//
//	//char* ret = strerror(errno);
//	//printf("%s\n", ret);
//
//	FILE* pf = fopen("test.txt", "r");
//
//	if (pf == NULL) {
//		printf("%s\n", strerror(errno));
//	}
//	else {
//		printf("open file successfully\n");
//	}
//
//	return 0;
//}

//#include <assert.h>
//#include <stdio.h>
//#include <string.h>
////strtok函数可将字符串拆分
//int main()
//{
//	//char arr1[] = "wsdanshenmiao@outlook.com";
//	char arr1[] = "654.654984.654";
//	char arr2[] = "@.";
//	char* replica = arr1;
//	for (char* ret = strtok(replica, arr2); ret; ret = strtok(NULL, arr2)) {
//		printf("%s\n", ret);
//	}
//}

//////自己写的my_strstr函数，但有些情况不能处理，如在"abbbcdef"中查找"bbc"会查找失败
////char* my_strstr(const char* string, const char* substring)
////{
////	assert(string && substring);
////	if (substring == NULL) {	//substring为空指针时返回被查找的字符串
////		return string;
////	}
////	char* ret;
////	char* store_Substring = substring;	//保存子串的地址
////	while (*string) {
////		while (*string != *substring) {		//查找相同的字符
////			if (!*string) {
////				return NULL;
////			}
////			string++;
////		}
////		ret = string;
////		while (*substring) {
////			if (!*string) {
////				return NULL;
////			}
////			if (*string == *substring) {
////				string++;
////				substring++;
////			}
////			else {
////				break;
////			}
////		}
////		if (*substring == '\0') {	//substring指向'/0'时查找完成
////			return ret;
////		}
////		substring = store_Substring;
////	}
////	return NULL;
////}
//
//#include <assert.h>
//#include <stdio.h>
//#include <string.h>
////可用KMP算法解决
//char* my_strstr(const char* string, const char* substring)
//{
//	assert(string && substring);
//	char* p1 = (char*)string;
//	char* p2 = (char*)substring;
//	char* reserve = (char*)string;
//	if ('\0' == p2) {
//		return (char*)string;	//子串为'\0'时，返回被查找字符串
//	}
//	while (*reserve) {
//		p1 = reserve;
//		p2 = (char*)substring;
//		while (*p1 == *p2 && '\0' != *p1 && '\0' != *p2) {
//			p1++;
//			p2++;
//		}
//		if (*p2 == '\0') {
//			return reserve;		//找到子串
//		}
//		reserve++;
//	}
//	return NULL;	//找不到子串
//}
//
//int main()
//{
//	char* p1 = "I get CLANNAD,CLANNAD";
//	char* p2 = "CLANNAD";
//	//char* ret = strstr(p1, p2);	//子串存在则返回子串首字母地址，否则返回空指针，只返回第一次出现的地址
//	char* ret = my_strstr(p1, p2);
//	if (ret == NULL) {
//		printf("子串不存在\n");
//	}
//	else {
//		printf("%s", ret);
//	}
//	return 0;
//}

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