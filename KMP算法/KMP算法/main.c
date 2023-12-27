#include <stdlib.h>
#include <string.h>

int* get_Next(const char* p2, int* next, int length)
{
	int i = 1;	//��׺
	int j = 0;	//ǰ׺
	*next = 0;
	for (i = 1; i <= length; i++) {
		while (j > 0 && *(p2 + j) != *(p2 + i)) {
			j = *(next + j - 1);
		}
		if (*(p2 + j) == *(p2 + i)) {
			j++;
		}
		*(next + i) = j;
	}
	return next;
}

char* my_strstr(const char* p1, const char* p2)
{
	int length = (int)strlen(p2);
	int* next = malloc(length * sizeof(int));
	next = get_Next(p2,next,length);	//�������ǰ׺

}

int main()
{
	char arr1[] = "aabaabaaf";
	char arr2[] = "aabaaf";
	//             010120
	my_strstr(arr1, arr2);
	return 0;
}