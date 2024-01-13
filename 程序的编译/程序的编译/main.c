#include <stdio.h>
#include <stddef.h>

#define OFFSETOF(s,m) (size_t)&(((s*)0)->m)

struct S
{
	char a;
	int b;
	char c;
};

int main()
{
	printf("%zd", OFFSETOF(struct S, a));	//计算结构体中某个元素的偏移量
	printf("%zd", OFFSETOF(struct S, b));
	printf("%zd", OFFSETOF(struct S, c));
	return 0;
}

////条件编译
//
//int main()
//{
//#if 2==1
//	printf("1\n");
//#elif 3 == 2
//	printf("2\n");
//#else 
//	printf("3\n");
//#endif
//	return 0;
//}

//#define DEBUG
//
//int main()
//{
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	for (int i = 0; i < 10; i++) {
//		arr[i] = 0;
////#if 1
////		printf("%d", arr[i]);
////#endif
////#ifdef DEBUG
////		printf("%d", arr[i]);
////#endif
//	}
//	return 0;
//}

////带副作用的宏参数
////给宏传参时尽量不要传带副作用的参数
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//
//int main()
//{
//	int a = 10;
//	int b = 11;
//	int max = MAX(a++, b++);
//	//int max = （（a++） > （b++） ? （a++） : （b++））;
//	printf("%d\n", max);//12
//	printf("%d\n", a);//11
//	printf("%d\n", b);//13
//#undef MAX
//	//移除一个宏定义
//	return 0;
//}

////##可以把位于它两边的符号合成一个符号。
//#define CAT(X,Y) X##Y
//
//int main()
//{
//	int wsdsm = 100;
//	printf("%d\n", CAT(ws, dsm));
//	//printf("%d\n", ws##dsm);
//	//printf("%d\n", wsdsm);
//	return 0;
//}

////使用#，把一个宏参数变成对应的字符串。
//#define PRINT(X) printf("the value of " #X " is %d\n", X);
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	PRINT(a);
//	//printf("the value of a is %d\n", a);
//	PRINT(b);
//	//printf("the value of b is %d\n", b);
//	return 0;
//}

////#define 机制包括了一个规定，允许把参数替换到文本中，这种实现通常称为宏（macro）或定义宏（define macro）。
//
////#define 替换规则
////1. 在调用宏时，首先对参数进行检查，看看是否包含任何由#define定义的符号。如果是，它们首先
////被替换。
////2. 替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被他们的值替换。
////3. 最后，再次对结果文件进行扫描，看看它是否包含任何由#define定义的符号。如果是，就重复上
////述处理过程。
//
////注意：
////1. 宏参数和#define 定义中可以出现其他#define定义的变量。但是对于宏，不能出现递归。
////2. 当预处理器搜索#define定义的符号的时候，字符串常量的内容并不被搜索。
//#define MAX 100
//#define SQURT(X) ((X)*(X))
//
//int main()
//{
//	printf("%d", SQURT(MAX));
//	return 0;
//}

//int main()
//{
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//
//	return 0;
//}