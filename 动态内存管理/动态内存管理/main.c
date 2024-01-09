#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct S
{
	int a;
	int arr[];	//未知大小的数组——柔性数组成员——大小可调整
};

int main()
{
	//struct S s;
	//printf("%d\n", sizeof(s));
	struct S* ps = malloc(sizeof(struct S) + 5 * sizeof(int));
	ps->a = 100;
	for (int i = 0; i < 5; i++) {
		ps->arr[i] = i;
	}
	struct S *psr = realloc(ps, sizeof(struct S) + 10 * sizeof(int));
	if (psr) {
		ps = psr;
	}
	else {
		return 0;
	}
	for (int i = 5; i < 10; i++) {
		ps->arr[i] = i;
	}
	free(ps);
	ps = NULL;

	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>
//
//int main()
//{
//	int* p = (int*)calloc(5, sizeof(int));	//calloc函数赋初值0,效率比malloc低
//	
//	//reallo函数注意事项
//	//1.如果p后面有足够的空间，则直接追加，返回p
//	//2.如果p后面没有足够的空间，则新开辟一个空间，内容内容复制过去，释放原空间，返回新空间的地址
//	//3.要用一个新的变量接收realloc的返回值
//	int* ptr = realloc(p, 5 * sizeof(int));
//	if (ptr) {
//		p = ptr;
//	}
//	if (p == NULL) {	//内存分配失败则返回空指针
//		printf("%s", strerror(errno));
//	}
//	else {
//		for (int i = 0; i < 10; i++) {
//			*(p + i) = i;
//		}
//		for (int i = 0; i < 10; i++) {
//			printf("%d ", *(p + i));
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	//int* p = (int*)malloc(LLONG_MAX);
//	int* p = (int*)calloc(10, sizeof(int));	//calloc函数赋初值0,效率比malloc低
//	if (p == NULL) {	//内存分配失败则返回空指针
//		printf("%s", strerror(errno));
//	}
//	else {
//		for (int i = 0; i < 10; i++) {
//			*(p + i) = i;
//		}
//		for (int i = 0; i < 10; i++) {
//			printf("%d ", *(p + i));
//		}
//	}
//	free(p);	//释放后p依然有能力找到那块空间
//	p = NULL;	//主动更改p的指向
//	return 0;
//}