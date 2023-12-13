#include <stdio.h>

#define MYMAX(type) type type##_max(type x, type y) { return x > y ? x : y; }

MYMAX(int)
MYMAX(double)

int main()
{
    int a = 4, b = 5;
    double c = 3.14, d = 9.8;
    int e = int_max(a, b);
    double f = double_max(c, d);
    printf("最大整数: %d\n", e);
    printf("最大浮点数: %f\n", f);
    return 0;
}