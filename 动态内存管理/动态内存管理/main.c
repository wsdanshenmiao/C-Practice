#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct S
{
	int a;
	int arr[];	//δ֪��С�����顪�����������Ա������С�ɵ���
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
//	int* p = (int*)calloc(5, sizeof(int));	//calloc��������ֵ0,Ч�ʱ�malloc��
//	
//	//reallo����ע������
//	//1.���p�������㹻�Ŀռ䣬��ֱ��׷�ӣ�����p
//	//2.���p����û���㹻�Ŀռ䣬���¿���һ���ռ䣬�������ݸ��ƹ�ȥ���ͷ�ԭ�ռ䣬�����¿ռ�ĵ�ַ
//	//3.Ҫ��һ���µı�������realloc�ķ���ֵ
//	int* ptr = realloc(p, 5 * sizeof(int));
//	if (ptr) {
//		p = ptr;
//	}
//	if (p == NULL) {	//�ڴ����ʧ���򷵻ؿ�ָ��
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
//	int* p = (int*)calloc(10, sizeof(int));	//calloc��������ֵ0,Ч�ʱ�malloc��
//	if (p == NULL) {	//�ڴ����ʧ���򷵻ؿ�ָ��
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
//	free(p);	//�ͷź�p��Ȼ�������ҵ��ǿ�ռ�
//	p = NULL;	//��������p��ָ��
//	return 0;
//}