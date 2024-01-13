#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <errno.h>
#include <string.h>

//文件的随机读取
int main()
{
	int ch;
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		return 0;
	}
	fseek(pf, -2, SEEK_END);	//随机读取
	ch = getc(pf);
	printf("%c", ch);
	printf("%d", ftell(pf));
	rewind(pf);	//让文件指针回到起始位置
	printf("%d", ftell(pf));
	fclose(pf);
	pf = NULL;
	return 0;
}

//int main()
//{
//	char arr[10000] = { 0 };
//	FILE* fp = fopen("D:\\PCL2\\.minecraft\\versions\\原版生存\\saves\\极限生存\\playerdata\\00000000-0000-300b-9c32-bd85215ec19b.dat", "rb");
//	if (fp == NULL) {
//		printf("%s", strerror(errno));
//		return 0;
//	}
//
//	//printf("%c", fgetc(fp));
//
//	//fgets(arr, 10, fp);
//	//puts(arr);
//
//	fread(&arr, sizeof(arr), 1, fp);
//	for (int i = 0; i < 1000; i++) {
//		printf("%d", *(arr + i));
//	}
//
//	fclose(fp);
//	fp = NULL;
//
//	return 0;
//}