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
	printf("%zd", OFFSETOF(struct S, a));	//����ṹ����ĳ��Ԫ�ص�ƫ����
	printf("%zd", OFFSETOF(struct S, b));
	printf("%zd", OFFSETOF(struct S, c));
	return 0;
}

////��������
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

////�������õĺ����
////���괫��ʱ������Ҫ���������õĲ���
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//
//int main()
//{
//	int a = 10;
//	int b = 11;
//	int max = MAX(a++, b++);
//	//int max = ����a++�� > ��b++�� ? ��a++�� : ��b++����;
//	printf("%d\n", max);//12
//	printf("%d\n", a);//11
//	printf("%d\n", b);//13
//#undef MAX
//	//�Ƴ�һ���궨��
//	return 0;
//}

////##���԰�λ�������ߵķ��źϳ�һ�����š�
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

////ʹ��#����һ���������ɶ�Ӧ���ַ�����
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

////#define ���ư�����һ���涨������Ѳ����滻���ı��У�����ʵ��ͨ����Ϊ�꣨macro������꣨define macro����
//
////#define �滻����
////1. �ڵ��ú�ʱ�����ȶԲ������м�飬�����Ƿ�����κ���#define����ķ��š�����ǣ���������
////���滻��
////2. �滻�ı���󱻲��뵽������ԭ���ı���λ�á����ں꣬�����������ǵ�ֵ�滻��
////3. ����ٴζԽ���ļ�����ɨ�裬�������Ƿ�����κ���#define����ķ��š�����ǣ����ظ���
////��������̡�
//
////ע�⣺
////1. �������#define �����п��Գ�������#define����ı��������Ƕ��ں꣬���ܳ��ֵݹ顣
////2. ��Ԥ����������#define����ķ��ŵ�ʱ���ַ������������ݲ�����������
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