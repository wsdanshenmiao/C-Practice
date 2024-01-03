#include <stdio.h>
#include <stddef.h>



////联合大小的计算
//
////联合的大小至少是最大成员的大小。
////当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍。
//union Un
//{
//	int a;
//	char b[5];
//};
//
//int main()
//{
//	union Un u;
//	printf("%zd", sizeof(u));
//	return 0;
//}

//int check_Sys()
//{
//	union
//	{
//		int a;
//		char b;
//	}u;
//	u.a = 1;
//	//返回1表示小端
//	//返回0表示大端
//	return u.b;
//}
//
////int check_Sys()
////{
////	int a = 1;
////	//返回1表示小端
////	//返回0表示大端
////	return *(char*)&a;
////}
//
//int main()
//{
//	int ret = check_Sys();
//	if (ret) {
//		printf("小端存储\n");
//	}
//	else {
//		printf("大端存储\n");
//	}
//	return 0;
//}

////联合（共用体）
//union Un
//{
//	int a;
//	char b;
//};
//
//int main()
//{
//	union Un u;
//	printf("%d\n", sizeof(u));
//	printf("%p %p %p", &u, &u.a, &u.b);
//	
//	return 0;
//}

////枚举
////枚举的优点：
////1. 增加代码的可读性和可维护性
////2. 和#define定义的标识符比较枚举有类型检查，更加严谨。
////3. 防止了命名污染（封装）
////4. 便于调试
////5. 使用方便，一次可以定义多个常量
//
//enum Color
//{
//	RED,
//	GREEN,
//	BLUE
//};
//
//int main()
//{
//	printf("%d %d %d", RED, GREEN, BLUE);
//	return 0;
//}

////位段——二进制位
////1. 位段的成员可以是，int，unsigned int，signed int 或者是，char （属于整形家族）类型
////2. 位段的空间上是按照需要以4个字节（int ）或者1个字节（char ）的方式来开辟的。
////3. 位段涉及很多不确定因素，位段是不跨平台的，注重可移植的程序应该避免使用位段。
//
////位段的跨平台问题
////1. int 位段被当成有符号数还是无符号数是不确定的。
////2. 位段中最大位的数目不能确定。（16位机器最大16，32位机器最大32，写成27，在16位机器会出问题。
////3. 位段中的成员在内存中从左向右分配，还是从右向左分配标准尚未定义。
////4. 当一个结构包含两个位段，第二个位段成员比较大，无法容纳于第一个位段剩余的位时，是舍弃剩余的位还是利用，这是不确定的。
//
//struct S
//{
//	int a : 2;
//	int b : 5;
//	int c : 10;
//	int d : 30;
//};
////47bit
//
//int main()
//{
//	struct S s;
//	printf("%zd", sizeof(s));
//	return 0;
//}

////结构体内存对齐
//
////1. 第一个成员在与结构体变量偏移量为0的地址处。
////2. 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
////对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。(VS中默认的值为8)
////3. 结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍。
////4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍
//
////gcc没有默认对齐数
//
////默认对齐数可修改
//#pragma pack(4)	//设置默认对齐数为4
//struct Node1
//{
//	int value;
//	struct Node1* next;
//	int a;
//};
//
//struct Node2
//{
//	int a;
//	int value;
//	struct Node2* next;
//};
//#pragma pack()	//取消设置的默认对齐数
//
//int main()
//{
//	struct Node1 n1 = { 0 };
//	struct Node2 n2 = { 0 };
//	//printf("%zu", sizeof(n1));
//	//printf("%zu", sizeof(n2));
//	
//	//offsetof()计算结构体成员偏移量的宏
//	printf("%zd\n", offsetof(struct Node1, value));
//	printf("%zd\n", offsetof(struct Node1, next));
//	printf("%zd\n", offsetof(struct Node1, a));
//
//	return 0;
//}

////结构体的自引用
//struct Node
//{
//	int value;
//	struct Node* next;
//};
//
//int main()
//{
//	return 0;
//}