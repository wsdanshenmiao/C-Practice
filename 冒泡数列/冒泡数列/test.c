#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>//Ä£Äâqsort¿âº¯Êý
#include <string.h>

typedef struct stu
{
	char name[30];
	int age;
}stu;

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

int cmp_double(const void* e1, const void* e2)
{
	if (*(double*)e1 == *(double*)e2)
		return 0;
	else if (*(double*)e1 > *(double*)e2)
		return 1;
	else
		return -1;
}

int cmp_struct_age(const void* e1, const void* e2)
{
	return ((stu*)e1)->age - ((stu*)e2)->age;
}

int cmp_struct_name(const void* e1, const void* e2)
{
	return strcmp((char*)e1, (char*)e2);
}

void Swap(char* arr1, char* arr2, int width)//»¥»»
{
	int i;
	for (i = 0; i < width; i++, arr1++, arr2++) {
		int temp = *arr1;
		*arr1 = *arr2;
		*arr2 = temp;
	}
}

void Bubble_sort(void* arr, int sz, int width, int (*compare)(const void*,const void*))
{
	int i, j;
	for (i = 0; i < sz; i++) {
		for (j = 0; j < sz - i - 1; j++) {
			if (compare((char*)arr + j * width, (char*)arr + (j + 1) * width) > 0) {
				Swap((char*)arr + j * width, (char*)arr + (j + 1) * width, width);
			}
		}
	}
}

int main()
{
	int arr1[] = { 4,5,7,2,3,8,9,7,5,4,3,0,7,5 };
	double arr2[] = { 6.6,9.1,6.2,8.2,3.7,1.5,4.8 };
	stu a[3] = { {"joe",50 }, { "tom",38 }, { "marry",34 } };

	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	int sz3 = sizeof(a) / sizeof(a[0]);

	Bubble_sort(arr1, sz1, sizeof(arr1[0]), cmp_int);
	Bubble_sort(arr2, sz2, sizeof(arr2[0]), cmp_double);
	Bubble_sort(a, sz3, sizeof(a[0]), cmp_struct_age);
	Bubble_sort(a, sz3, sizeof(a[0]), cmp_struct_name);

	return 0;
}

//#include <stdio.h>
//
//int mp(int arr[], int sz)
//{
//	int i;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int b = 1;
//		int j;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//				b = 0;
//			}
//		}
//		if (b == 1)
//		{
//			break;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[] = {5,4,7,8,2,1,3,6,9,0,10,12,48,65,15,23,54,19};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int a = 0;
//	mp(arr, sz);
//	for (a = 0; a < sz; a++)
//	{
//		printf("%d ", arr[a]);
//	}
//	return 0;
//}