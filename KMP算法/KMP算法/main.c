#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

int* get_Next(const char* p2, int* next, int lengthp2)
{
	int i = 1;	//后缀
	int j = 0;	//最长前缀
	*next = 0;
	for (i = 1; i <= lengthp2; i++) {
		while (j > 0 && *(p2 + j) != *(p2 + i)) {
			j = *(next + j - 1);	//遇到不相等的回退
		}
		if (*(p2 + j) == *(p2 + i)) {
			j++;	//遇到相等的j往后加一
		}
		*(next + i) = j;
	}
	return next;
}

char* my_strstr(const char* p1, const char* p2)
{
	if (*p2 == '\0') {
		return (char*)p1;
	}
	int lengthp1 = 0;
	int lengthp2 = 0;
	for (; *(p2 + lengthp2); lengthp2++);
	for (; *(p1 + lengthp1); lengthp1++);
	int* next = malloc(lengthp2 * sizeof(int));
	next = get_Next(p2,next, lengthp2);	//求最长公共前缀
	int j = 0;
	for (int i = 0; i < lengthp1; i++) {
		while (j > 0 && *(p1 + i) != *(p2 + j)) {
			j = *(next + j - 1);
		}
		if (*(p1 + i) == *(p2 + j) && *(p1 + i) != '\0' && *(p2 + j) != '\0') {
			j++;
		}
		if (*(p2 + j) == '\0') {
			return (char*)(p1 + i - lengthp2 + 1);
		}
	}
	return NULL;
}

int main()
{
	char arr1[] = "aabaabaaf";
	char arr2[] = "aabaaf";
	//             010120
	printf("%s", my_strstr(arr1, arr2));
	return 0;
}